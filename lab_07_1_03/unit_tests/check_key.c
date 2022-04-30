#include <stdio.h>
#include "functions.h"

int check_key_without_negative()
{
    int check = 0;
    int is_wrong = 0;
    int test_length = 10;
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *arr_after_key = NULL;
    int *end_arr_after_key = NULL;
    check = key(arr, arr + test_length, &arr_after_key, &end_arr_after_key);
    if (check != 0 ||  end_arr_after_key - arr_after_key != test_length)
        is_wrong = 1;
    int *p_1 = arr_after_key;
    int *p_2 = arr;
    while (p_1 != end_arr_after_key)
        if (*(p_1++) != *(p_2++))
            is_wrong = 1;
    free(arr_after_key);
    return is_wrong;
}

int check_key_with_wrong_arguments()
{
    int is_wrong = 0;
    int check = 0;
    int *p = &check;
    check = key(NULL, &check, NULL, NULL);
    if (check == 0)
        is_wrong = 1;
    check = key(&check, NULL, &p, &p);
    if (check == 0)
        is_wrong = 1;
    check = key(&check + 1, &check, &p, &p);
    if (check == 0)
        is_wrong = 1;
    check = key(&check + 1, &check, NULL, &p);
    if (check == 0)
        is_wrong = 1;
    check = key(&check + 1, &check, &p, NULL);
    if (check == 0)
        is_wrong = 1;
    return is_wrong;
}

int check_key_with_one_negative()
{
    int check = 0;
    int is_wrong = 0;
    int test_length = 10;
    int arr[] = {0, 1, 2, 3, 4, -5, 6, 7, 8, 9};
    int *arr_after_key = NULL;
    int *end_arr_after_key = NULL;
    check = key(arr, arr + test_length, &arr_after_key, &end_arr_after_key);
    if (check != 0 ||  end_arr_after_key - arr_after_key != 5)
        is_wrong = 1;
    int *p_1 = arr_after_key;
    int *p_2 = arr;
    while (p_1 != end_arr_after_key)
        if (*(p_1++) != *(p_2++))
            is_wrong = 1;
    free(arr_after_key);
    return is_wrong;
}

int check_key_with_multiple_negatives()
{
    int check = 0;
    int is_wrong = 0;
    int test_length = 10;
    int arr[] = {0, 1, -2, 3, -4, -5, 6, 7, 8, 9};
    int *arr_after_key = NULL;
    int *end_arr_after_key = NULL;
    check = key(arr, arr + test_length, &arr_after_key, &end_arr_after_key);
    if (check != 0 ||  end_arr_after_key - arr_after_key != 5)
        is_wrong = 1;
    int *p_1 = arr_after_key;
    int *p_2 = arr;
    while (p_1 != end_arr_after_key)
        if (*(p_1++) != *(p_2++))
            is_wrong = 1;
    free(arr_after_key);
    return is_wrong;
}

int check_key()
{
    int error_amount = 0;
    error_amount += check_key_with_wrong_arguments();
    error_amount += check_key_without_negative();
    error_amount += check_key_with_one_negative();
    error_amount += check_key_with_multiple_negatives();
    return error_amount;
}