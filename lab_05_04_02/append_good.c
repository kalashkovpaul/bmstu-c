#include <stdio.h>
#include <string.h>
#include "good.h"
#include "good_lib.h"
#include "constants.h"
#include "append_good.h"

int is_arguments_for_append(int argc, char **argv)
{
    return (argc == 3 && ((strcmp(argv[1], "at") == 0)));
}

int append_good(char *file_src)
{
    FILE *file = fopen(file_src, "r");
    if (file == NULL)
        return ERR_FILE;
    the_good array[TXT_SIZE] = { 0 };
    int i = 0, check = OK, length;
    check = read_array(file, array, &length);
    if (check != OK)
        return check;
    the_good new_good;
    check = take_good_from_txt(stdin, &new_good);
    if (check != OK)
    {
        return ERR_READ;
    }
    file = fopen(file_src, "w");
    i = 0;
    while (compare(array[i], new_good) && i < length)
    {
        f_print_good(file, array[i]);
        i++;
    }
    f_print_good(file, new_good);
    while (i < length)
    {
        f_print_good(file, array[i]);
        i++;
    }
    fclose(file);
    return OK;
}