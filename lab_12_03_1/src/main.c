#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "constants.h"
#include "functions.h"
#include "arguments.h"
#include "sort.h"

int main(int argc, char **argv)
{
    int check, *arr = NULL, *end_arr = NULL;
    int *array_after_key = NULL, *end_array_after_key = NULL;
    void (*mysort)(void *, size_t, size_t, int (*)(const void*, const void*));
    check = are_arguments_valid(argc, argv);
    char *error = NULL;
    void *handle = NULL;
    handle = dlopen("libsort.so", RTLD_LAZY);
    if (handle == NULL)
        check = ERR_DL;
    *(void **) &mysort = dlsym(handle, "mysort");
    if ((error = dlerror()) != NULL)
        check = ERR_DL;
    if (check == OK)
    {
        check = read_array(argv[1], &arr, &end_arr);
        if (check == OK)
        {
            if (are_arguments_for_filter(argc, argv))
            {
                check = key(arr, end_arr, &array_after_key, &end_array_after_key);
                array_after_key = malloc(check * sizeof(int));
                end_array_after_key = array_after_key + check;
                if (array_after_key)
                    check = OK;
                else
                    check = ERR_MEMORY;
                if (check == OK)
                {
                    check = key(arr, end_arr, &array_after_key, &end_array_after_key);
                    if (check == OK)
                    {
                        mysort(array_after_key, end_array_after_key - array_after_key, sizeof(int), compare);
                        check = file_print_array(argv[2], array_after_key, end_array_after_key);
                    }
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