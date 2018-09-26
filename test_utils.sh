#!/usr/bin/env bash

TEST_FILE=test_$1.c

if [ -e  ${TEST_FILE} ]
then
    echo ${TEST_FILE} already exists!
else
    cat > ${TEST_FILE} << EOF
#include <stdio.h>

#include "test_utils.h"

void test_foo();

/**********************************************************************************************************************/

int main() {
    test_fn_t tests[] = {
            test_foo
    };

    RUN_TESTS(tests);

    return 0;
}

/**********************************************************************************************************************/

void test_foo() {
    PRINT_TEST_HEADER;

    FAIL_TEST();
}
EOF
fi