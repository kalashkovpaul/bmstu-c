#include <stdio.h>
#include "functions.h"

int compare_char(const void *p_1, const void *p_2)
{
    int check;
    const char *p_char_1 = p_1;
    const char *p_char_2 = p_2;
    if (*p_char_1 > *p_char_2)
        check = 1;
    else if (*p_char_1 < *p_char_2)
        check = -1;
    else
        check = 0;
    return check;
}

int compare_short(const void *p_1, const void *p_2)
{
    int check;
    const short int *p_sh_int_1 = p_1;
    const short int *p_sh_int_2 = p_2;
    if (*p_sh_int_1 > *p_sh_int_2)
        check = 1;
    else if (*p_sh_int_1 < *p_sh_int_2)
        check = -1;
    else
        check = 0;
    return check;
}

int compare_long_long(const void *p_1, const void *p_2)
{
    int check;
    const long long int *p_ll_int_1 = p_1;
    const long long int *p_ll_int_2 = p_2;
    if (*p_ll_int_1 > *p_ll_int_2)
        check = 1;
    else if (*p_ll_int_1 < *p_ll_int_2)
        check = -1;
    else
        check = 0;
    return check;
}

int check_mysort_with_char()    
{
    int test_length = 10;
    char ch_arr[] = {'c', 'd', 'a', 'b', 'z', 'y', 'x', 'e', 'f', 'k'};
    char answer[] = {'a', 'b', 'c', 'd', 'e', 'f', 'k', 'x', 'y', 'z'};
    int is_wrong = 0;
    mysort(ch_arr, test_length, sizeof(char), compare_char);
    for (int i = 0; i < test_length; i++)
        if (ch_arr[i] != answer[i])
            is_wrong = 1;
    return is_wrong;
}

int check_my_sort_with_sh_int()
{
    int test_length = 10;
    short sh_int_arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    short answer[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int is_wrong = 0;
    mysort(sh_int_arr, test_length, sizeof(short), compare_short);
    for (int i = 0; i < test_length; i++)
        if (sh_int_arr[i] != answer[i])
            is_wrong = 1;
    return is_wrong;
}

int check_my_sort_with_ll_int()
{
    int test_length = 10;
    long long llint_arr[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
    long long answer[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
    int is_wrong = 0;
    mysort(llint_arr, test_length, sizeof(long long int), compare_long_long);
    for (int i = 0; i < test_length; i++)
        if (llint_arr[i] != answer[i])
            is_wrong = 1;
    return is_wrong;
}

int check_mysort()
{
    int error_amount = 0;
    error_amount += check_mysort_with_char();
    error_amount += check_my_sort_with_sh_int();
    error_amount += check_my_sort_with_ll_int();
    return error_amount;
}