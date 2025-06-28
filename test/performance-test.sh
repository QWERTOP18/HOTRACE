
#!/bin/bash







echo "Measuring execution time..."
START_TIME=$(date +%s.%N)
./hotrace < perf_example.htr | tr -d '\0' > test/perf_example.out.tmp
END_TIME=$(date +%s.%N)
ELAPSED=$(echo "$END_TIME - $START_TIME" | bc)
echo "Execution time: $ELAPSED seconds"

diff test/perf_example.out.tmp test/perf_example.out.tmp
rm test/perf_example.out.tmp
