#include <stdio.h>

#include "test_utils.h"

void test_foo();
void test_bar();
void test_later();

/**********************************************************************************************************************/

int main() {
    test_fn_t tests[] = {
            test_foo,
            test_bar,
            test_later
    };

    RUN_TESTS(tests);

    return 0;
}

/**********************************************************************************************************************/

int foo() {
    return 1;
}

/**********************************************************************************************************************/

void test_foo() {
    PRINT_TEST_HEADER;

    ASSERT_EQUAL_INT(1, foo(), "foo should always return 1");
}

void test_bar() {
    PRINT_TEST_HEADER;

    char str1[] = "foo";
    char str2[] = "fbar";

    ASSERT_EQUAL_STR(str1, str2, "The strings should be equal");
    ASSERT_EQUAL_MEMORY(str1, str2, 3, "The memory in both addresses should be equal");
}

void test_later() {
    PRINT_TEST_HEADER;

    FAIL_TEST();
}
