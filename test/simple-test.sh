#!/bin/bash

# $>cat -e example.htr
# keyword-1$
# value-1$
# keyword-2$
# value-2$
# $
# keyword-1$
# keyword-2$
# $>./hotrace < example.htr
# value-1
# value-2
# $>./hotrace
# keyword-1
# value-1
# keyword-2
# value-2
# keyword-3
# keyword-3: Not found.
# keyword-1
# value-1

cat << EOF > example.htr
keyword-1
value-1
keyword-2
value-2

keyword-1
keyword-2
keyword-3
EOF


RESULT=$(./hotrace < example.htr)
EXPECTED="value-1
value-2
keyword-3
: Not found."

if [ "$RESULT" != "$EXPECTED" ]; then
    echo -e "\033[31mTest failed: Expected '$EXPECTED', got '$RESULT'\033[0m"
    exit 1
fi



echo -e "\033[32mTest passed: Output matches expected result.\033[0m"