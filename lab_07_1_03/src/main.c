#include <stdio.h>
#include <stdlib.h>
#include "constants.h"
#include "functions.h"
#include "arguments.h"

int main(int argc, char **argv)
{
    int check, *arr = NULL, *end_arr = NULL;
    int *array_after_key = NULL, *end_array_after_key = NULL;
    check = are_arguments_valid(argc, argv);
    if (check == OK)
    {
        check = read_array(argv[1], &arr, &end_arr);
        if (check == OK)
        {
            if (are_arguments_for_filter(argc, argv))
            {
                check = key(arr, end_arr, &array_after_key, &end_array_after_key);
                if (check == OK)
                {
                    mysort(array_after_key, end_array_after_key - array_after_key, sizeof(int), compare);
                    check = file_print_array(argv[2], array_after_key, end_array_after_key);
                }
            }
            else
            {
                mysort(arr, end_arr - arr, sizeof(int), compare);
                check = file_print_array(argv[2], arr, end_arr);
            }
        }
    }
    free_array(arr, end_arr);
    free_array(array_after_key, end_array_after_key);
    return check;
}