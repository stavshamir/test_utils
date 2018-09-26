#include <stdio.h>
#include <string.h>

#include "test_utils.h"

#ifdef USE_COLORS
#define COLOR_RESET fprintf(stderr, "\x1B[0m");
#define COLOR_RED   fprintf(stderr, "\x1B[31m");
#define COLOR_GRN   fprintf(stderr, "\x1B[32m");
#else
#define COLOR_RESET
#define COLOR_RED
#define COLOR_GRN
#endif

/**********************************************************************************************************************/

static int g_error_count = 0;

/**********************************************************************************************************************/

void run_tests(test_fn_t *tests, int test_count) {
    int curr_err_count = 0;
    for(int i = 0; i < test_count; ++i) {
        curr_err_count = g_error_count;
        tests[i]();
        if (g_error_count == curr_err_count) {
            puts("... ok");
        }
    }

    if (g_error_count > 0) {
        COLOR_RED
        printf("\n\nRan %d tests: %d errors were found\n\n", test_count, g_error_count);
        COLOR_RESET
    } else {
        COLOR_GRN
        printf("\n\nRan %d tests: all passed\n\n", test_count);
        COLOR_RESET
    }
}

/**********************************************************************************************************************/

void fail_test(int line) {
    ++g_error_count;

    COLOR_RED;
    fprintf(stderr, "line %d: Not implemented... Failed\n", line);
    COLOR_RESET;
}

/**********************************************************************************************************************/

void assert_equal_ptr(int line_number, void *expected, void *actual, const char *message) {
    if (expected != actual) {
        ++g_error_count;

        COLOR_RED
        fprintf(stderr, "line %d: %s... Failed\n", line_number, message);
        fprintf(stderr, "\texpected: %p\n", expected);
        fprintf(stderr, "\tactual:   %p\n", actual);
        COLOR_RESET
    }
}

/**********************************************************************************************************************/

void assert_equal_str(int line, const char *expected, const char *actual, const char *message) {
    if (strcmp(expected, actual) != 0) {
        ++g_error_count;

        COLOR_RED
        fprintf(stderr, "line %d: %s... Failed\n", line, message);
        fprintf(stderr, "\texpected: %s\n", expected);
        fprintf(stderr, "\tactual:   %s\n", actual);
        COLOR_RESET
    }
}

/**********************************************************************************************************************/

void assert_equal_int(int line_number, int expected, int actual, const char *message) {
    if (expected != actual) {
        ++g_error_count;

        COLOR_RED
        fprintf(stderr, "line %d: %s... Failed\n", line_number, message);
        fprintf(stderr, "\texpected: %d\n", expected);
        fprintf(stderr, "\tactual:   %d\n", actual);
        COLOR_RESET
    }
}

/**********************************************************************************************************************/

void assert_equal_uint64(int line, uint64_t expected, uint64_t actual, const char *message) {
    if (expected != actual) {
        ++g_error_count;

        COLOR_RED
        fprintf(stderr, "line %d: %s... Failed\n", line, message);
        fprintf(stderr, "\texpected: %ld\n", expected);
        fprintf(stderr, "\tactual:   %ld\n", actual);
        COLOR_RESET
    }
}

/**********************************************************************************************************************/

void assert_equal_hex(int line_number, int expected, int actual, const char *message) {
    if (expected != actual) {
        ++g_error_count;

        COLOR_RED
        fprintf(stderr, "line %d: %s... Failed\n", line_number, message);
        fprintf(stderr, "\texpected: 0x%X\n", expected);
        fprintf(stderr, "\tactual:   0x%X\n", actual);
        COLOR_RESET
    }
}

/**********************************************************************************************************************/

void assert_false(int line_number, int expression, const char *message) {
    if (0 != expression) {
        ++g_error_count;

        COLOR_RED
        fprintf(stderr, "line %d: %s... Failed\n", line_number, message);
        fprintf(stderr, "\texpected: false\n");
        fprintf(stderr, "\tactual:   true\n");
        COLOR_RESET
    }
}

/**********************************************************************************************************************/

void assert_true(int line_number, int expression, const char *message) {
    if (0 == expression) {
        ++g_error_count;

        COLOR_RED
        fprintf(stderr, "line %d: %s... Failed\n", line_number, message);
        fprintf(stderr, "\texpected: true\n");
        fprintf(stderr, "\tactual:   false\n");
        COLOR_RESET
    }
}

/**********************************************************************************************************************/

void assert_equal_memory(int line, const void *expected, const void *actual, int length, const char *message) {
    for(int i = 0; i < length; ++i) {
        if (((uint8_t *)expected)[i] != ((uint8_t *)actual)[i]) {
            ++g_error_count;

            COLOR_RED
            fprintf(stderr, "line %d: %s... Failed (on element %d)\n", line, message, i);
            fprintf(stderr, "\texpected[%d]: 0x%02x\n", i, ((uint8_t *)expected)[i]);
            fprintf(stderr, "\tactual[%d]:   0x%02x\n", i, ((uint8_t  *)actual)[i]);
            COLOR_RESET

            return;
        }
    }
}
