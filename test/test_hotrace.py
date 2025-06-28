import subprocess
import random
import string
import time
import os
import sys

# --- Configuration ---
EXECUTABLE = "../hotrace"
MAKE_COMMAND = ["make", "-C", "..", "re"]

# --- ANSI Color Codes for better output ---
GREEN = "\033[92m"
RED = "\033[91m"
YELLOW = "\033[93m"
RESET = "\033[0m"
CYAN = "\033[96m"

def print_header(title):
    """Prints a formatted header."""
    print(f"\n{CYAN}{'='*15} {title} {'='*15}{RESET}")

def print_result(test_name, success, details=""):
    """Prints the result of a single test case."""
    status = f"{GREEN}PASS{RESET}" if success else f"{RED}FAIL{RESET}"
    print(f"[{status}] {test_name}")
    if not success and details:
        # Indent details for readability
        for line in details.split('\n'):
            print(f"  {RED}↳ {line}{RESET}")

def run_test(test_name, input_data, expected_output, timeout=5):
    """
    Runs the hotrace executable with the given input and checks the output.
    Returns True if the test passes, False otherwise.
    """
    try:
        # Ensure input data ends with a newline as required
        if not input_data.endswith('\n'):
            input_data += '\n'

        result = subprocess.run(
            [EXECUTABLE],
            input=input_data,
            capture_output=True,
            text=True,
            timeout=timeout,
            check=False # We check the return code manually
        )

        if result.returncode != 0:
            # The program must not quit unexpectedly [cite: 13]
            details = f"Process crashed with non-zero exit code: {result.returncode}.\nStderr: {result.stderr.strip()}"
            print_result(test_name, False, details)
            return False

        actual_output = result.stdout
        if actual_output == expected_output:
            print_result(test_name, True)
            return True
        else:
            details = (f"Output mismatch.\n"
                       f"Expected:\n---\n{expected_output}---\n"
                       f"Got:\n---\n{actual_output}---")
            print_result(test_name, False, details)
            return False

    except FileNotFoundError:
        print_result(test_name, False, f"Executable '{EXECUTABLE}' not found.")
        # Stop all tests if executable is not there
        sys.exit(1)
    except subprocess.TimeoutExpired:
        details = f"Test timed out after {timeout} seconds. Performance issue suspected."
        print_result(test_name, False, details)
        return False
    except Exception as e:
        details = f"An unexpected error occurred: {e}"
        print_result(test_name, False, details)
        return False

# 1. Normal Case: Random key-value pairs
def test_random_cases(num_tests=5, num_pairs=1000):
    print_header("Test 1: Normal Cases (Random Data)")
    passed_count = 0
    for i in range(num_tests):
        test_name = f"Random Case #{i+1}"
        
        # Generate random key-value pairs
        keys = [''.join(random.choices(string.ascii_letters + string.digits, k=12)) for _ in range(num_pairs)]
        values = [''.join(random.choices(string.ascii_letters + string.digits, k=24)) for _ in range(num_pairs)]
        
        # Use a Python dict as the ground truth
        expected_dict = {k: v for k, v in zip(keys, values)}
        
        # Prepare input data [cite: 23, 26]
        store_data = "\n".join([f"{k}\n{v}" for k, v in expected_dict.items()])
        
        # Select keys to search, including some that don't exist
        search_keys = random.sample(list(expected_dict.keys()), k=num_pairs // 2)
        non_existent_keys = [''.join(random.choices(string.ascii_lowercase, k=8)) for _ in range(20)]
        search_keys.extend(non_existent_keys)
        random.shuffle(search_keys)
        
        input_str = store_data + "\n\n" + "\n".join(search_keys)

        # Prepare expected output
        expected_output_lines = []
        for key in search_keys:
            if key in expected_dict:
                expected_output_lines.append(expected_dict[key])
            else:
                # Format for failed search [cite: 27]
                expected_output_lines.append(f"{key}: Not found.")
        expected_output = "\n".join(expected_output_lines) + "\n"
        
        if run_test(test_name, input_str, expected_output):
            passed_count += 1

    return passed_count == num_tests

# 2. Normal Case: Sorted input to test balancing
def test_sorted_input_performance():
    print_header("Test 2: Performance (Sorted Input)")
    test_name = "Sorted Input Performance Test"
    num_pairs = 20000 # A large number to make performance differences noticeable
    
    # Generate sorted keys, which would be a worst-case for an unbalanced BST
    keys = [f"key_{i:05d}" for i in range(num_pairs)]
    values = [f"value_{i:05d}" for i in range(num_pairs)]
    
    store_data = "\n".join([f"{k}\n{v}" for k, v in zip(keys, values)])
    
    # Search for all keys in a random order
    search_keys = keys[:]
    random.shuffle(search_keys)
    
    input_str = store_data + "\n\n" + "\n".join(search_keys)
    
    # Prepare expected output
    expected_dict = {k: v for k, v in zip(keys, values)}
    expected_output_lines = [expected_dict[key] for key in search_keys]
    expected_output = "\n".join(expected_output_lines) + "\n"
    
    # Use a tight timeout. A balanced tree should handle this easily.
    # An unbalanced tree will likely time out.
    return run_test(test_name, input_str, expected_output, timeout=2.0)

# 3. Edge Case: Duplicate keys
def test_duplicate_keys():
    print_header("Test 3: Edge Case (Duplicate Keys)")
    test_name = "Duplicate key should be overwritten"
    
    # key1 is defined twice. The second value should be stored.
    input_data = (
        "key1\nvalue1\n"
        "key2\nvalue2\n"
        "key1\nvalue1_new\n"
        "\n"
        "key1\n"
        "key2\n"
    )
    
    expected_output = (
        "value1_new\n"
        "value2\n"
    )
    
    return run_test(test_name, input_data, expected_output)

# 4. Error Case: Invalid formats
def test_invalid_formats():
    print_header("Test 4: Error Cases (Invalid Formats)")
    results = []

    # Case 4.1: Incomplete pair (key without value at the end of data section)
    # 'lone_key' should not be registered.
    test_name = "Invalid Format: Incomplete Pair"
    input_data_1 = (
        "key1\nvalue1\n"
        "lone_key\n"
        "\n"
        "key1\n"
        "lone_key\n"
    )
    expected_output_1 = (
        "value1\n"
        "lone_key: Not found.\n"
    )
    results.append(run_test(test_name, input_data_1, expected_output_1))

    # Case 4.2: Empty value
    # The value for 'key1' is an empty string.
    test_name = "Invalid Format: Empty Value"
    input_data_2 = (
        "key1\n\n" # Empty value for key1
        "key2\nvalue2\n"
        "\n"
        "key1\n"
        "key2\n"
    )
    expected_output_2 = (
        "\n" # Empty line for the empty value
        "value2\n"
    )
    results.append(run_test(test_name, input_data_2, expected_output_2))
    
    # Case 4.3: Empty key
    # An empty string is a valid key.
    test_name = "Invalid Format: Empty Key"
    input_data_3 = (
        "\nvalue_for_empty\n" # Empty key
        "key2\nvalue2\n"
        "\n"
        "\n" # Search for the empty key
        "key2\n"
    )
    expected_output_3 = (
        "value_for_empty\n"
        "value2\n"
    )
    results.append(run_test(test_name, input_data_3, expected_output_3))
    
    # Case 4.4: No separating newline between data and search sections
    # All lines should be treated as key-value pairs. No search occurs, so no output.
    test_name = "Invalid Format: No Separator"
    input_data_4 = "key1\nvalue1\nkey2\nvalue2"
    expected_output_4 = ""
    results.append(run_test(test_name, input_data_4, expected_output_4))

    return all(results)


def main():
    """Main function to run all tests."""
    print_header("Building hotrace")
    try:
        # Rebuild the project cleanly before testing
        build_process = subprocess.run(
            MAKE_COMMAND,
            capture_output=True, text=True, check=True, timeout=15
        )
        print(f"{GREEN}Build successful.{RESET}")
        # print(build_process.stdout) # Uncomment for detailed build output
    except FileNotFoundError:
        print(f"{RED}Error: 'make' command not found. Please ensure make is installed.{RESET}")
        return 1
    except subprocess.CalledProcessError as e:
        print(f"{RED}Error: Build failed with status {e.returncode}.{RESET}")
        print(f"--- stdout ---\n{e.stdout}\n--- stderr ---\n{e.stderr}")
        return 1
    except subprocess.TimeoutExpired:
        print(f"{RED}Error: Build timed out.{RESET}")
        return 1
    
    if not os.path.exists(EXECUTABLE):
        print(f"{RED}Error: Executable '{EXECUTABLE}' not found after make.{RESET}")
        print(f"Please ensure your Makefile creates a target named '{os.path.basename(EXECUTABLE)}'.")
        return 1

    # Run all test suites
    test_results = {
        "Random": test_random_cases,
        "Performance": test_sorted_input_performance,
        #"Duplicate Keys": test_duplicate_keys,
        #"Invalid Formats": test_invalid_formats,
    }

    final_results = []
    for name, test_func in test_results.items():
        final_results.append(test_func())

    # Final summary
    print_header("Test Summary")
    if all(final_results):
        print(f"{GREEN}🎉 All tests passed! 🎉{RESET}")
        return 0
    else:
        failed_count = final_results.count(False)
        total_count = len(final_results)
        print(f"{RED}🚨 {failed_count} out of {total_count} test suites failed. 🚨{RESET}")
        return 1


if __name__ == "__main__":
    sys.exit(main())
