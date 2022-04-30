#include <stdio.h>
#include <stdlib.h>
#include "constants.h"

int get_elements_amount(FILE *src)
{
    int n = 0;
    int element, check = OK;
    while (fscanf(src, "%d", &element) == 1)
        n++;
    if (feof(src) && n != 0)
        check = n;
    else
        check = ERR_READ;
    return check;
}

int read_array(char *filename, int **arr, int **end_arr)
{
    int check = OK;
    FILE *src = fopen(filename, "r");
    if (src == NULL)
        return ERR_INPUT_FILE;
    check = get_elements_amount(src);
    rewind(src);
    if (check != ERR_READ)
    {
        int n = check;
        check = OK;
        *arr = malloc(n * sizeof(int));
        *(end_arr) = *arr + n;
        if (*arr == NULL)
            check = ERR_MEMORY;
        else
            for (int *ptr = *arr; ptr != *end_arr; ptr++)
                fscanf(src, "%d", ptr);
    }
    fclose(src);
    return check;
}

const int *find_last_neg(const int *arr, const int *end_arr)
{
    const int *ptr = end_arr;
    do
        ptr--;
    while (ptr > arr && *ptr >= 0);
    if (ptr == arr && *ptr >= 0)
        ptr = end_arr;
    return ptr;
}

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    int check = OK, n = 0;
    if (pb_src == NULL || pe_src == NULL || pb_src >= pe_src || pb_dst == NULL || pe_dst == NULL)
        check = KEY_ERROR;
    else
    {
        n = find_last_neg(pb_src, pe_src) - pb_src;
        if (n <= 0)
            check = KEY_ERROR;
        else if (*pb_dst == NULL || *pe_dst == NULL || *pe_dst - *pb_dst < n)
            check = n;//*pb_dst = malloc(n * sizeof(int));

        if (check == OK && *pb_dst == NULL)
            check = KEY_ERROR;

        if (check == OK)
        {
            const int *current_src = pb_src;
            int *current_dst = *pb_dst;
            const int *p_end = pb_src + n;
            while (current_src != p_end)
                *(current_dst++) = *(current_src++);
            (*pe_dst) = current_dst;
        }
    }
    return check;
}

int compare(const void *p_1, const void *p_2)
{
    int check;
    const int *p_int_1 = p_1;
    const int *p_int_2 = p_2;
    if (*p_int_1 > *p_int_2)
        check = 1;
    else if (*p_int_1 < *p_int_2)
        check = -1;
    else
        check = 0;
    return check;
}

int file_print_array(char *filename, int *arr, int *arr_end)
{
    int check = OK;
    FILE *f_dst = fopen(filename, "w");
    if (f_dst == NULL)
        check = OUTPUT_FILE_ERR;
    else
    {
        int *p = arr;
        while (p != arr_end - 1)
            fprintf(f_dst, "%d ", *(p++));
        fprintf(f_dst, "%d\n", *p);
    }
    return check;
}

void free_array(int *arr, int *end_arr)
{
    free(arr);
    arr = NULL;
    end_arr++;
    end_arr = NULL;
}