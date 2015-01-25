#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "munit.h"
#include "utils.h"


/* TESTS */
int test_trim_char(void);
int test_trim(void);
int test_copy_value(void);
int test_randi(void);
void test_suite(void);

int test_int_cmp()
{
    int val_1 = 1;
    int val_2 = 1;
    int *val_ptr_1 = &val_1;
    int *val_ptr_2 = &val_2;

    /* ASCENDING TESTS */
    /* when val_1 and val_2 are equal */
    int result = int_cmp_asc(&val_1, &val_2);
    mu_assert(result == 0, "Result should be 0!");

    /* when val_2 is bigger than val_1 */
    val_2 = 10;
    result = int_cmp_asc(&val_1, &val_2);
    mu_assert(result == -1, "Result should be -1!");

    /* when val_1 is bigger than val_2 */
    val_2 = -1;
    result = int_cmp_asc(&val_1, &val_2);
    mu_assert(result == 1, "Result should be 1!");

    /* when val_1 and val_2 are pointers */
    result = int_cmp_asc(val_ptr_1, val_ptr_2);
    mu_assert(result == 1, "Result should be 1!");


    /* resetting values */
    val_1 = 1;
    val_2 = 1;
    val_ptr_1 = &val_1;
    val_ptr_2 = &val_2;


    /* DESCENDING TESTS */
    /* when val_1 and val_2 are equal */
    result = int_cmp_desc(&val_1, &val_2);
    mu_assert(result == 0, "Result should be 0!");

    /* when val_2 is bigger than val_1 */
    val_2 = 10;
    result = int_cmp_desc(&val_1, &val_2);
    mu_assert(result == 1, "Result should be 1!");

    /* when val_1 is bigger than val_2 */
    val_2 = -1;
    result = int_cmp_desc(&val_1, &val_2);
    mu_assert(result == -1, "Result should be -1!");

    /* when val_1 and val_2 are pointers */
    result = int_cmp_desc(val_ptr_1, val_ptr_2);
    mu_assert(result == -1, "Result should be -1!");

    return 0;
}

int test_float_cmp()
{
    float val_1 = 1.0;
    float val_2 = 1.0;

    /* ASCENDING TESTS */
    /* when val_1 and val_2 are equal */
    int result = float_cmp_asc(&val_1, &val_2);
    mu_assert(result == 0, "Result should be 0!");

    /* when val_2 is bigger than val_1 */
    val_1 = 0.001;
    val_2 = 0.01;
    result = float_cmp_asc(&val_1, &val_2);
    mu_assert(result == -1, "Result should be -1!");

    /* when val_1 is bigger than val_2 */
    val_1 = 0.01;
    val_2 = 0.001;
    result = float_cmp_asc(&val_1, &val_2);
    mu_assert(result == 1, "Result should be 1!");


    /* resetting values */
    val_1 = 1.0;
    val_2 = 1.0;


    /* DESCENDING TESTS */
    result = float_cmp_desc(&val_1, &val_2);
    mu_assert(result == 0, "Result should be 0!");

    /* when val_2 is bigger than val_1 */
    val_1 = 0.001;
    val_2 = 0.01;
    result = float_cmp_desc(&val_1, &val_2);
    mu_assert(result == 1, "Result should be 1!");

    /* when val_1 is bigger than val_2 */
    val_1 = 0.01;
    val_2 = 0.001;
    result = float_cmp_desc(&val_1, &val_2);
    mu_assert(result == -1, "Result should be -1!");

    return 0;
}

int test_epsilon_float_cmp()
{
    float val_1 = 1.0;
    float val_2 = 1.0;
    float epsilon = 0.00001;

    /* ASCENDING TESTS */
    /* when val_1 and val_2 are equal */
    int result = float_epsilon_cmp_asc(&val_1, &val_2, epsilon);
    mu_assert(result == 0, "Result should be 0!");

    /* when val_2 is bigger than val_1 */
    val_1 = 0.001;
    val_2 = 0.01;
    result = float_epsilon_cmp_asc(&val_1, &val_2, epsilon);
    mu_assert(result == -1, "Result should be -1!");

    /* when val_1 is bigger than val_2 */
    val_1 = 0.01;
    val_2 = 0.001;
    result = float_epsilon_cmp_asc(&val_1, &val_2, epsilon);
    mu_assert(result == 1, "Result should be 1!");

    /* resetting values */
    val_1 = 1.0;
    val_2 = 1.0;


    /* DESCENDING TESTS */
    result = float_epsilon_cmp_desc(&val_1, &val_2, epsilon);
    mu_assert(result == 0, "Result should be 0!");

    /* when val_2 is bigger than val_1 */
    val_1 = 0.001;
    val_2 = 0.01;
    result = float_epsilon_cmp_desc(&val_1, &val_2, epsilon);
    mu_assert(result == 1, "Result should be 1!");

    /* when val_1 is bigger than val_2 */
    val_1 = 0.01;
    val_2 = 0.001;
    result = float_epsilon_cmp_desc(&val_1, &val_2, epsilon);
    mu_assert(result == -1, "Result should be -1!");

    return 0;
}

int test_str_cmp()
{
    char *val_1 = "B";  /* 'B' has char code 66 */
    char *val_2 = "B";  /* 'B' has char code 66 */

    /* ASCENDING TESTS */
    /* when val_1 and val_2 are equal */
    int result = str_cmp_asc(val_1, val_2);
    mu_assert(result == 0, "Result should be 0!");

    /* when val_2 is bigger than val_1 */
    val_2 = "C";  /* 'C' has char code 67 */
    result = str_cmp_asc(val_1, val_2);
    mu_assert(result == -1, "Result should be -1!");

    /* when val_1 is bigger than val_2 */
    val_2 = "A";  /* 'A' has char code 65 */
    result = str_cmp_asc(val_1, val_2);
    mu_assert(result == 1, "Result should be 1!");


    /* resetting values */
    val_1 = "B";  /* 'B' has char code 66 */
    val_2 = "B";  /* 'B' has char code 66 */


    /* DESCENDING TESTS */
    /* when val_1 and val_2 are equal */
    result = str_cmp_desc(val_1, val_2);
    mu_assert(result == 0, "Result should be 0!");

    /* when val_2 is bigger than val_1 */
    val_2 = "C";  /* 'C' has char code 67 */
    result = str_cmp_desc(val_1, val_2);
    mu_assert(result == 1, "Result should be 1!");

    /* when val_1 is bigger than val_2 */
    val_2 = "A";  /* 'A' has char code 65 */
    result = str_cmp_desc(val_1, val_2);
    mu_assert(result == -1, "Result should be -1!");

    return 0;
}


int test_trim_char(void)
{
    mu_check(trim_char('\n') == 1);
    mu_check(trim_char('\t') == 1);
    mu_check(trim_char('\r') == 1);
    mu_check(trim_char(' ') == 1);
    mu_check(trim_char('A') == 0);

    return 0;
}

int test_trim(void)
{
    char *result;
    const char *test_1 = "\nHello World\n ";
    const char *test_2 = "\n\tWorld\n \t";

    result = trim(test_1);
    mu_check(strcmp(result, "Hello World") == 0);
    free(result);

    result = trim(test_2);
    mu_check(strcmp(result, "World") == 0);
    free(result);

    return 0;
}

int test_copy_value(void)
{
    int *int_ptr;
    float *float_ptr;
    double *double_ptr;
    char *str_ptr;

    int int_value = 0;
    float float_value = 10.0;
    double doule_value = 100.0;
    const char *str_value = "test";

    int_ptr = copy_value(INTEGER, &int_value);
    mu_check(intcmp(int_ptr, &int_value) == 0);

    float_ptr = copy_value(FLOAT, &float_value);
    mu_check(fltcmp(float_ptr, &float_value) == 0);

    double_ptr = copy_value(DOUBLE, &doule_value);
    mu_check(fltcmp(double_ptr, &doule_value) == 0);

    str_ptr = copy_value(STRING, (void *) str_value);
    mu_check(strcmp(str_ptr, str_value) == 0);

    /* clean up */
    free(int_ptr);
    free(float_ptr);
    free(double_ptr);
    free(str_ptr);
    return 0;
}

int test_randi(void)
{
    int i;
    int retval;
    int counter_1 = 0;
    int counter_2 = 0;
    int counter_3 = 0;

    for (i = 0; i < 10000; i++) {
        retval = randi(0, 2);

        if (retval == 0) {
            counter_1++;
        } else if (retval == 1) {
            counter_2++;
        } else if (retval == 2) {
            counter_3++;
        }
    }

    printf("%d, %d, %d\n", counter_1, counter_2, counter_3);

    return 0;
}

void test_suite(void)
{
    srand((unsigned int) time(NULL));
    mu_add_test(test_int_cmp);
    mu_add_test(test_float_cmp);
    mu_add_test(test_epsilon_float_cmp);
    mu_add_test(test_str_cmp);

    mu_add_test(test_trim_char);
    mu_add_test(test_trim);
    mu_add_test(test_copy_value);

    mu_add_test(test_randi);
}

mu_add_tests(test_suite)
