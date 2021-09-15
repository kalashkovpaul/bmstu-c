#include <stdio.h>
#include <string.h>
#include "constants.h"
#include "good_lib.h"
#include "find_goods.h"

int is_arguments_for_find(int argc, char **agrv)
{
    return (argc == 4 && ((strcmp(agrv[1], "ft") == 0)));
}

int print_good(the_good good)
{
    printf("%s\n", good.name);
    printf("%s\n", good.maker);
    printf("%u\n", good.price);
    printf("%u\n", good.amount);
    return OK;
}

int is_ended_with(char *str, char *substr, int sub_length)
{
    int str_len = strlen(str);
    if (sub_length > str_len)
        return 0;
    return 0 == strncmp(str + str_len - sub_length, substr, sub_length);
}

int find_goods(char *file_src, char *substr)
{
    FILE *f_src = fopen(file_src, "r");
    if (f_src == NULL)
        return ERR_FILE;
    the_good array[TXT_SIZE] = { 0 };
    int i = 0, check = OK, length;
    check = read_array(f_src, array, &length);
    if (check != OK)
    {
        fclose(f_src);
        return check;
    }
    int counter = 0;
    int substr_len = strlen(substr);
    for (i = 0; i < length; i++)
    {
        if (is_ended_with(array[i].name, substr, substr_len))
        {
            counter++;
            print_good(array[i]);
        }
    }
    if (counter == 0)
    {
        fclose(f_src);
        return ERR_FILE;
    }
    fclose(f_src);
    return OK;
}