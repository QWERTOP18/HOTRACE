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


make

<< EOF > example.htr
keyword-1
value-1
keyword-2
value-2
EOF

RESULT=$(./hotrace < example.htr)

if [ "$RESULT" != "value-1
value-2" ]; then
    echo -e "Test failed: Expected 'value-1\nvalue-2', got '$RESULT'"
    exit 1
fi


