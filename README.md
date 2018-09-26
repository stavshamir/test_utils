# test_utils
A simple unit testing framework for C99.

## Usage
Clone and run the following command:

```bash
$ source test_utils.sh <test_filename>
```
This will create a skeleton for your unit test file with the name test_filename.c:

```C
#include <stdio.h>

#include "test_filename.h"

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
```

In order to add a test function, do the following:
1. Declare it above the main function
2. Add the unit test function name to the tests array in the main function
3. Implement the function, and optionally (but recommended) add the PRINT_TEST_HEADER macro as the first statment

**All unit test functions must be void and receive no parameters.**

Look at test_utils.h to see the available assertions (feel free to open an issue to add more assertions), and look at the test_example.c file for some more examples.

