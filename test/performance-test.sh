#!/bin/bash

if command -v gdate >/dev/null 2>&1; then
    # macOS + coreutils（brew install coreutils）
    DATE_CMD="gdate"
else
    # Linux (GNU date)
    DATE_CMD="date"
fi

start_time=$($DATE_CMD +%s%3N)
./hotrace < test/perf_example.seed | tr -d '\0' > test/perf_example.out.tmp
end_time=$($DATE_CMD +%s%3N)
elapsed=$((end_time - start_time))
echo "Execution time: ${elapsed} ms"

diff test/perf_example.out.tmp test/perf_example.result

