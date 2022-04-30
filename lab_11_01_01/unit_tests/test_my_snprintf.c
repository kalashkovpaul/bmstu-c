#include <stdio.h>
#include <string.h>

#include "my_snprintf.h"

int test_null_arguments();

int test_without_specifiers();

int test_with_char();

int test_with_int();

int test_with_str();

int test_with_hex();

int test_with_all();

int activate_test_my_snprintf()
{
    int error_count = 0;
    error_count += test_null_arguments();
    error_count += test_without_specifiers();
    error_count += test_with_char();
    error_count += test_with_int();
    error_count += test_with_str();
    error_count += test_with_hex();
    error_count += test_with_all();
    return error_count;
}

int test_null_arguments()
{
    int error_count = 0;
    int my_result = 0;
    int true_result = -1;
    my_result = my_snprintf(NULL, 0, NULL);
    // true_result = snprintf(NULL, -1, "%d%d", 5, 5); Segmentation fault
    // true_result = snprintf(NULL, 1, ""); Segmentation fault
    // true_result = snprintf(null_str, 10, "%d%d"); Segmentation fault
    if (my_result != true_result)
        error_count++;
    my_result = my_snprintf(NULL, 0, ""); 
    true_result = 0;
    if (my_result != true_result)
        error_count++;
    if (error_count != 0)
        printf("test_null_arguments in test_my_snprintf FAILED\n");
    return error_count;
}

int test_without_specifiers()
{
    int error_count = 0;
    int my_result = 0;
    int true_result = 0;
    char my_str[10] = { 0 };
    char true_str[10] = { 0 };
    my_result = my_snprintf(my_str, 10, "abcd");
    true_result = snprintf(true_str, 10, "abcd");
    if (my_result != true_result || strncmp(my_str, true_str, 10) != 0)
        error_count++;
    // my_result = my_snprintf(my_str, 10, "1234567890000");
    // true_result = snprintf(true_str, 10, "1234567890000");
    // if (my_result != true_result || strncmp(my_str, true_str, 10) != 0)
    //     error_count++;
    if (error_count != 0)
        printf("test_without_specifiers in test_my_snprintf FAILED\n");
    return error_count;
}

int test_with_char()
{
    int error_count = 0;
    int my_result = 0;
    int true_result = 0;
    char my_str[10] = { 0 };
    char true_str[10] = { 0 };
    my_result = my_snprintf(my_str, 10, "%cbc%c", 'a', 'd');
    true_result = snprintf(true_str, 10, "%cbc%c", 'a', 'd');
    if (my_result != true_result || strncmp(my_str, true_str, 10) != 0)
        error_count++;
    my_result = my_snprintf(my_str, 10, "%c%c%c%c", '1', '2', '3', '4');
    true_result = snprintf(true_str, 10, "%c%c%c%c", '1', '2', '3', '4');
    if (my_result != true_result || strncmp(my_str, true_str, 10) != 0)
        error_count++;
    my_result = my_snprintf(my_str, 10, "%c%c%c%c", '1', '2', '3', '4');
    true_result = snprintf(true_str, 10, "%c%c%c%c", '1', '2', '3', '4');
    if (my_result != true_result || strncmp(my_str, true_str, 10) != 0)
        error_count++;
    // my_result = my_snprintf(my_str, 3, "%c%c%c%c%c", '1', '2', '3');
    // true_result = snprintf(true_str, 3, "%c%c%c%c%c", '1', '2', '3');
    // if (my_result != true_result || strncmp(my_str, true_str, 10) != 0)
    //     error_count++;
    // my_result = my_snprintf(my_str, 10, "12345678%d", 10);
    // true_result = snprintf(true_str, 10, "12345678%d", 10);
    // if (my_result != true_result || strncmp(my_str, true_str, 10) != 0)
    //     error_count++;
    if (error_count != 0)
        printf("test_with_char in test_my_snprintf FAILED\n");
    return error_count;
}

int test_with_int()
{
    int error_count = 0;
    int my_result = 0;
    int true_result = 0;
    char my_str[10] = { 0 };
    char true_str[10] = { 0 };
    my_result = my_snprintf(my_str, 10, "%dbc%d", 1, -4);
    true_result = snprintf(true_str, 10, "%dbc%d", 1, -4);
    if (my_result != true_result || strncmp(my_str, true_str, 10) != 0)
        error_count++;
    my_result = my_snprintf(my_str, 10, "%dbc%d", 0, -4);
    true_result = snprintf(true_str, 10, "%dbc%d", 0, -4);
    if (my_result != true_result || strncmp(my_str, true_str, 10) != 0)
        error_count++;
    my_result = my_snprintf(my_str, 10, "%d%d", 123, -187);
    true_result = snprintf(true_str, 10, "%d%d", 123, -187);
    if (my_result != true_result || strncmp(my_str, true_str, 10) != 0)
        error_count++;
    my_result = my_snprintf(my_str, 10, "%d%d%d%d", -123, 0, -18, 0);
    true_result = snprintf(true_str, 10, "%d%d%d%d", -123, 0, -18, 0);
    if (my_result != true_result || strncmp(my_str, true_str, 10) != 0)
        error_count++;
    if (error_count != 0)
        printf("test_with_int in test_my_snprintf FAILED\n");
    return error_count;
}

int test_with_str()
{
    int error_count = 0;
    int my_result = 0;
    int true_result = 0;
    char my_str[10] = { 0 };
    char true_str[10] = { 0 };
    my_result = my_snprintf(my_str, 10, "%sbc%s", "1", "23");
    true_result = snprintf(true_str, 10, "%sbc%s", "1", "23");
    if (my_result != true_result || strncmp(my_str, true_str, 10) != 0)
        error_count++;
    if (error_count != 0)
        printf("test_with_int in test_my_snprintf FAILED\n");
    return error_count;
}

int test_with_hex()
{
    int error_count = 0;
    int my_result = 0;
    int true_result = 0;
    char my_str[100] = { 0 };
    char true_str[100] = { 0 };
    my_result = my_snprintf(my_str, 100, "%x%x", 1, -24);
    true_result = snprintf(true_str, 100, "%x%x", 1, -24);
    if (my_result != true_result || strncmp(my_str, true_str, 10) != 0)
        error_count++;
    my_result = my_snprintf(my_str, 100, "%x%x", -1, -1);
    true_result = snprintf(true_str, 100, "%x%x", -1, -1);
    if (my_result != true_result || strncmp(my_str, true_str, 10) != 0)
        error_count++;
    my_result = my_snprintf(my_str, 100, "%x", 0);
    true_result = snprintf(true_str, 100, "%x", 0);
    if (my_result != true_result || strncmp(my_str, true_str, 10) != 0)
        error_count++;
    // my_result = my_snprintf(my_str, 3, "%x%x", -1, -1);
    // true_result = snprintf(true_str, 3, "%x%x", -1, -1);
    // if (my_result != true_result || strncmp(my_str, true_str, 10) != 0)
    //     error_count++;
    if (error_count != 0)
        printf("test_with_hex in test_my_snprintf FAILED\n");
    return error_count;
}

int test_with_all()
{
    int error_count = 0;
    int my_result = 0;
    int true_result = 0;
    char my_str[100] = { 0 };
    char true_str[100] = { 0 };
    my_result = my_snprintf(my_str, 100, "%x%x%c%c%c%c%sbc%s%dbc%d", 1, -24, '1', '2', '3', '4', "1", "23", 0, -4);
    true_result = snprintf(true_str, 100, "%x%x%c%c%c%c%sbc%s%dbc%d", 1, -24, '1', '2', '3', '4', "1", "23", 0, -4);
    if (my_result != true_result || strncmp(my_str, true_str, 10) != 0)
        error_count++;
    my_result = my_snprintf(my_str, 100, "%x%xaaa%c%c%c%c%sbc%saa%dbc%d", 1, -24, '1', '2', '3', '4', "1", "23", 0, -4);
    true_result = snprintf(true_str, 100, "%x%xaaa%c%c%c%c%sbc%saa%dbc%d", 1, -24, '1', '2', '3', '4', "1", "23", 0, -4);
    if (my_result != true_result || strncmp(my_str, true_str, 10) != 0)
        error_count++;
    my_result = my_snprintf(NULL, 0, "%x%s%d%c", 255, "string", 5, 'U');
    true_result = snprintf(NULL, 0, "%x%s%d%c", 255, "string", 5, 'U');
    if (my_result != true_result || strncmp(my_str, true_str, 10) != 0)
        error_count++;
    // my_result = my_snprintf(my_str, 0, "");
    // true_result = snprintf(true_str, 0, "");
    // if (my_result != true_result || strncmp(my_str, true_str, 10) != 0)
    //     error_count++;
    my_result = my_snprintf(my_str, 0, "%d", 0);
    true_result = snprintf(true_str, 0, "%d", 0);
    if (my_result != true_result || strncmp(my_str, true_str, 10) != 0)
        error_count++;
    if (error_count != 0)
        printf("test_with_hex in test_my_snprintf FAILED\n");
    return error_count;
}