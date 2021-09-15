#include <stdio.h>
#include <string.h>
#include "good_lib.h"
#include "good.h"
#include "constants.h"  

int file_read_line(FILE *file, char *str, int max_length)
{
    char ch = 0;
    int i = 0;
    fscanf(file, "%c", &ch);
    while (ch != '\n' && ch != '\r' && ch != EOF && !feof(file))
    {
        if (i < max_length - 1)
            str[i++] = ch;
        else
        {
            //printf("Reading line error\n");
            return ERR_LENGTH;
        }
        fscanf(file, "%c", &ch);
    }

    if (ch == '\r')
        fscanf(file, "%c", &ch);
    str[i] = '\0';
    if (i <= 0)
        return ERR_LENGTH;
    return OK;
}

int take_good_from_txt(FILE *f_src, the_good *good)
{
    int check;
    check = file_read_line(f_src, (*good).name, NAME_LENGTH);
    if (check != OK)
    {
        if (feof(f_src))
            return END_STRUCT;
        else
            return ERR_READ;
    }
    check = file_read_line(f_src, (*good).maker, MAKER_LENGTH);
    if (check != OK)
        return ERR_READ;
    check = fscanf(f_src, "%u", &(*good).price);
    if (check == 1)
    {
        char ch;
        check = fscanf(f_src, "%c", &ch);
        if (check == 1 && ch == '\r')
            check = fscanf(f_src, "%c", &ch);
    }
    else if (check != 1)
        return ERR_READ;
    check = fscanf(f_src, "%u", &(*good).amount);
    if (check == 1)
    {
        char ch;
        check = fscanf(f_src, "%c", &ch);
        if (check == 1 && ch == '\r')
            check = fscanf(f_src, "%c", &ch);
    }
    else if (check != 1)
        return ERR_READ;
    return OK;
}

int f_print_good(FILE *f_dst, the_good good)
{
    fprintf(f_dst, "%s\n", good.name);
    fprintf(f_dst, "%s\n", good.maker);
    fprintf(f_dst, "%u\n", good.price);
    fprintf(f_dst, "%u\n", good.amount);
    return OK;
}

int compare(the_good good_1, the_good good_2)
{
    if (good_1.price > good_2.price)
        return 1;
    if (good_1.price < good_2.price)
        return 0;
    return (good_1.amount > good_2.amount);
}

int read_array(FILE *file, the_good array[], int *length)
{
    int i = 0, check = OK;
    while (check != END_STRUCT && check != ERR_READ)
    {
        check = take_good_from_txt(file, &array[i]);
        if (check == OK)
            i++;
        else
        {
            if (check != END_STRUCT)
            {
                return ERR_READ;
            }
        }
    }
    *length = i;
    if (*length == 0)
        return ERR_LENGTH;
    return OK;
}