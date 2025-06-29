import subprocess
import random
import string
import time
import os
import sys

# --- Configuration ---
EXECUTABLE = "./hotrace"
MAKE_COMMAND = ["make", "re"]

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
    if details:
        color = GREEN if success else RED
        for line in details.split('\n'):
            print(f"  {color}↳ {line}{RESET}")

def run_test(test_name, input_data, expected_output, timeout=10, measure_time=False):
    """
    Runs the hotrace executable, measures execution time, and checks the output.
    Returns True if the test passes, False otherwise.
    """
    try:
        if not input_data.endswith('\n'):
            input_data += '\n'

        start_time = time.time()
        result = subprocess.run(
            [EXECUTABLE],
            input=input_data,
            capture_output=True,
            text=True,
            timeout=timeout,
            check=False
        )
        end_time = time.time()
        elapsed_time = end_time - start_time

        if result.returncode != 0:
            details = f"Process crashed with non-zero exit code: {result.returncode}.\nStderr: {result.stderr.strip()}"
            print_result(test_name, False, details)
            return False

        actual_output = result.stdout
        if actual_output == expected_output:
            details = f"Execution time: {elapsed_time:.4f} seconds" if measure_time else ""
            print_result(test_name, True, details)
            return True
        else:
            details = (f"Output mismatch.\n"
                       f"Expected:\n---\n{expected_output[:1000]}...\n---\n"
                       f"Got:\n---\n{actual_output[:1000]}...\n---")
            print_result(test_name, False, details)
            return False

    except FileNotFoundError:
        print_result(test_name, False, f"Executable '{EXECUTABLE}' not found.")
        sys.exit(1)
    except subprocess.TimeoutExpired:
        details = f"Test timed out after {timeout} seconds. Performance issue suspected."
        print_result(test_name, False, details)
        return False
    except Exception as e:
        details = f"An unexpected error occurred: {e}"
        print_result(test_name, False, details)
        return False

# Test 1: Performance and Accuracy Measurement
def test_performance_and_accuracy():
    print_header("Test 1: Performance and Accuracy")
    
    test_scenarios = {
        "Random Keys": lambda n: random.sample(range(n * 2), n),
        "Sorted Keys": lambda n: list(range(n)),
        "Reverse Sorted Keys": lambda n: list(range(n - 1, -1, -1)),
    }
    data_sizes = [10000, 50000, 100000]

    all_tests_passed = True
    for name, key_generator in test_scenarios.items():
        for size in data_sizes:
            test_name = f"{name} ({size:,} pairs)"
            
            # --- Data Generation ---
            keys = [
                ''.join(random.choices(string.ascii_letters + string.digits, k=random.randint(1, 1024)))
                for _ in range(size)
            ]
            values = [f"value_{i:06d}" for i in range(size)]
            expected_dict = {k: v for k, v in zip(keys, values)}
            store_data = "\n".join([f"{k}\n{v}" for k, v in expected_dict.items()])
            search_keys = keys[:]
            random.shuffle(search_keys)
            input_str = store_data + "\n\n" + "\n".join(search_keys)
            expected_output_lines = [expected_dict[key] for key in search_keys]
            expected_output = "\n".join(expected_output_lines) + "\n"

            # --- Test Execution ---
            # Set a generous timeout; a performant program should be much faster.
            timeout = (size / 10000) * 10 + 10  # e.g., 20s for 10k, 60s for 50k
            if not run_test(test_name, input_str, expected_output, timeout=timeout, measure_time=True):
                all_tests_passed = False
    
    return all_tests_passed

def main():
    """Main function to run all tests."""
    print_header("Building hotrace")
    try:
        build_process = subprocess.run(
            MAKE_COMMAND, capture_output=True, text=True, check=True, timeout=15
        )
        print(f"{GREEN}Build successful.{RESET}")
    except (FileNotFoundError, subprocess.CalledProcessError, subprocess.TimeoutExpired) as e:
        print(f"{RED}Build failed: {e}{RESET}")
        if hasattr(e, 'stderr'): print(e.stderr)
        return 1
    
    if not os.path.exists(EXECUTABLE):
        print(f"{RED}Error: Executable '{EXECUTABLE}' not found after make.{RESET}")
        return 1

    # Run all test suites
    results = [
        test_performance_and_accuracy(),
    ]

    # Final summary
    print_header("Test Summary")
    if all(results):
        print(f"{GREEN}🎉 All tests passed! 🎉{RESET}")
        return 0
    else:
        failed_count = results.count(False)
        total_count = len(results)
        print(f"{RED}🚨 {failed_count} out of {total_count} test suites failed. 🚨{RESET}")
        return 1

if __name__ == "__main__":
    sys.exit(main())
