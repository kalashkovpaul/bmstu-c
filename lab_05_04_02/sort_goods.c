#include <stdio.h>
#include <string.h>
#include "good.h"
#include "good_lib.h"
#include "constants.h"
#include "sort_goods.h"

int is_arguments_for_sort(int argc, char **agrv)
{
    return (argc == 4 && ((strcmp(agrv[1], "st") == 0)));
}

int set_good_to_txt(FILE *f_dst, the_good good)
{
    fprintf(f_dst, "%s\n", good.name);
    fprintf(f_dst, "%s\n", good.maker);
    fprintf(f_dst, "%u\n", good.price);
    fprintf(f_dst, "%u\n", good.amount);
    return OK;
}

int sort_text(char *file_src, char *file_dst)
{
    FILE *f_src = fopen(file_src, "r");
    if (f_src == NULL)
        return ERR_FILE;
    the_good array[TXT_SIZE] = { 0 };
    int i = 0, j = 0, check = OK, length;
    check = read_array(f_src, array, &length);
    fclose(f_src);
    if (check != OK)
        return check;
    FILE *f_dst = fopen(file_dst, "w");
    the_good t = { 0 };
    for (i = 1; i < length; i++)
    {
        for (j = i; j > 0 && compare(array[j], array[j - 1]); j--)
        {
            t = array[j - 1];
            array[j - 1] = array[j];
            array[j] = t;
        }
    }
    for (i = 0; i < length; i++)
    {
        check = f_print_good(f_dst, array[i]);
        if (check != OK)
        {
            fclose(f_dst);
            return check;
        }
    }
    fclose(f_dst);
    return OK;
}