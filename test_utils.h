#ifndef TEST_UTILS_H
#define TEST_UTILS_H

/**********************************************************************************************************************/

#include <stdint.h>

/**********************************************************************************************************************/

/* Run tests from given array of test functions and prints an error report.
 * Use only on same scope of array declaration */
#define RUN_TESTS(TESTS) run_tests(TESTS, sizeof(TESTS)/sizeof(test_fn_t))

/* Compare strings equality. On error, the values are printed as ints */
#define ASSERT_EQUAL_STR(EXPECTED, ACTUAL, MESSAGE) assert_equal_str(__LINE__, EXPECTED, ACTUAL, MESSAGE)

/* Compare memory pointed to by two pointers */
#define ASSERT_EQUAL_MEMORY(EXPECTED, ACTUAL, LENGTH, MESSAGE) assert_equal_memory(__LINE__, EXPECTED, ACTUAL, LENGTH, MESSAGE);

/* Compare integers equality. On error, the values are printed as ints */
#define ASSERT_EQUAL_INT(EXPECTED, ACTUAL, MESSAGE) assert_equal_int(__LINE__, EXPECTED, ACTUAL, MESSAGE)
#define ASSERT_EQUAL_UINT64(EXPECTED, ACTUAL, MESSAGE) assert_equal_uint64(__LINE__, EXPECTED, ACTUAL, MESSAGE)

/* Compare integers equality. On error, the values are printed as hex */
#define ASSERT_EQUAL_HEX(EXPECTED, ACTUAL, MESSAGE) assert_equal_hex(__LINE__, EXPECTED, ACTUAL, MESSAGE)

/* Compare two addresses */
#define ASSERT_EQUAL_PTR(EXPECTED, ACTUAL, MESSAGE) assert_equal_ptr(__LINE__, EXPECTED, ACTUAL, MESSAGE)

/* Pass if EXPRESSION evaluates to 0 */
#define ASSERT_FALSE(EXPRESSION, MESSAGE) assert_false(__LINE__, EXPRESSION, MESSAGE)

/* Pass if EXPRESSION evaluates to be different than 0 */
#define ASSERT_TRUE(EXPRESSION, MESSAGE) assert_true(__LINE__, EXPRESSION, MESSAGE)

/* Use for tests not yet implemented */
#define FAIL_TEST() fail_test(__LINE__);

/* Print a formatted header for the test function */
#define PRINT_TEST_HEADER { printf("\n\n*** Testing %s ***\n", __func__ + 5); }

/**********************************************************************************************************************/

typedef void (*test_fn_t)(void);
void run_tests(test_fn_t *tests, int test_count);
void fail_test(int line);

void assert_equal_str   (int line, const char *expected, const char *actual, const char *message);
void assert_equal_memory(int line, const void *expected, const void *actual, int length, const char *message);
void assert_equal_int   (int line, int expected, int actual, const char *message);
void assert_equal_uint64(int line, uint64_t expected, uint64_t actual, const char *message);
void assert_equal_hex   (int line, int expected, int actual, const char *message);
void assert_equal_ptr   (int line, void *expected, void *actual, const char *message);
void assert_false       (int line, int expression, const char *message);
void assert_true        (int line, int expression, const char *message);

/**********************************************************************************************************************/

#endif //TEST_UTILS_H
