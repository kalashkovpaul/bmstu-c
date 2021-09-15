#include <stdio.h>
#include <string.h>
#include "item_lib.h"
#include "constants.h"
// Note: there are functions in item_lib.c without unit tests (all functions below check_for_ending chars).
//       It is OK, because all of remanining functions are built simple and without complex dependencies.

int test_arguments_valid()
{
    int test_amount = 5, argc[] = { 0, 1, 2, 3, 4 };
    int results[] = { 0, 0, 1, 1, 0 };
    int error_count = 0;
    for (int i = 0; i < test_amount; i++)
        if (arguments_valid(argc[i]) != results[i])
            error_count++;
    if (error_count == 0)
        printf("arguments_valid: OK\n");
    else
        printf("arguments_valid: %d errors", error_count);
    return OK;
}

int test_arguments_for_sort()
{
    int test_amount = 3, argc[] = { 1, 2, 3 };
    int results[] = { 0, 1, 0 };
    int error_count = 0;
    for (int i = 0; i < test_amount; i++)
        if (arguments_for_sort(argc[i]) != results[i])
            error_count++;
    if (error_count == 0)
        printf("arguments_for_sort: OK\n");
    else
        printf("arguments_for_sort: %d errors\n", error_count);
    return OK;
}

int test_arguments_for_print()
{
    int test_amount = 10;
    char *prefixes[] = { "all", "All", "aLl", "alL", "ALl", "AlL", "aLL", "ALL",  "alll", "\n" };
    int results[] = { 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 };
    int error_count = 0;
    for (int i = 0; i < test_amount; i++)
        if (arguments_for_print(prefixes[i]) != results[i])
            error_count++;
    if (error_count == 0)
        printf("arguments_for_print: OK\n");
    else
        printf("arguments_for_print: %d errors\n", error_count);
    return OK;
}

int test_file_read_line()
{
    // This unit test requires an additional file "test_file_read_line_input.txt"
    int test_amount = 6, check = OK;
    int error_count = 0;
    char test_str[16]; //test_length = 15
    char *result_strings[] = { "first", "s e c o n d", "    th1rd   ", "", ")(*&^%", "123456789012345678901234567890" };
    int results[] = { OK, OK, OK, ERR_LENGTH, OK, ERR_LENGTH };
    FILE *input = fopen("test_file_read_line_input.txt", "r");
    if (input == NULL)
        check = ERR_FILE;
    if (check == OK)
    {
        for (int i = 0; i < test_amount; i++)
            if (file_read_line(input, test_str, 16) != results[i] && strncmp(test_str, result_strings[i], 16) != 0)
                error_count++;
        fclose(input);
        if (error_count == 0)
            printf("file_read_line: OK\n");
        else
            printf("file_read_line: %d errors\n", error_count);
    }
    return check;
}

int test_check_for_error()
{
    // This unit test also requires two (or more) additional files
    int check = OK;
    int test_amount = 2;
    int error_count = 0;
    FILE *file_1 = fopen("test_file_read_line_input.txt", "r");
    FILE *file_2 = fopen("empty_file.txt", "r");
    char ch;
    fscanf(file_2, "%c", &ch); // to make file really empty
    FILE *files[] = { file_1, file_2 };
    int results[] = { ERR_READ, END_STRUCT };
    if (file_1 == NULL || file_2 == NULL)
        check = ERR_FILE;
    if (check == OK)
    {
        for (int i = 0; i < test_amount; i++)
        {
            if (check_for_error(files[i]) != results[i])
            {
                error_count++;
                printf("Test %d failed\n", i);
            }
            fclose(files[i]);
        }
        if (error_count == 0)
            printf("check_for_error: OK\n");
        else
            printf("check_for_error: %d errors\n", error_count);
    }
    return check;
}

int test_check_for_ending_chars()
{
    // This unit test also requires two (or more) additional files
    int check = OK;
    int test_amount = 2;
    int error_count = 0;
    FILE *file_windows = fopen("file_windows.txt", "r");
    FILE *file_linux = fopen("file_linux.txt", "r");
    FILE *files[] = { file_windows, file_linux };
    int results[] = { OK, OK };
    if (file_windows == NULL || file_linux == NULL)
        check = ERR_FILE;
    if (check == OK)
    {
        for (int i = 0; i < test_amount; i++)
        {
            if (check_for_ending_chars(files[i]) != results[i])
                error_count++;
            fclose(files[i]);
        }
        if (error_count == 0)
            printf("check_for_ending_chars: OK\n");
        else
            printf("check_for_ending_chars: %d errors\n", error_count);
    }
    return check;
}

int activate_unit_tests()
{
    int check = OK;
    test_arguments_valid();
    test_arguments_for_sort();
    test_arguments_for_print();
    check = test_file_read_line();
    if (check != OK)
        printf("test_file_read_line: %d error code.\n", check);
    check = test_check_for_error();
    if (check != OK)
        printf("test_check_for_error: %d error code.\n", check);
    check = test_check_for_ending_chars();
    if (check != OK)
        printf("test_check_for_error: %d error code.\n", check);
    return OK;
}
