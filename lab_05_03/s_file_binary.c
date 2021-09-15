#include <stdio.h>
#include <string.h>
#ifndef _CHECK_FILE_SIZE_H_

#define _CHECK_FILE_SIZE_H_
#include "check_file_size.h"

#endif
#define OK 0
#define ERR_IO -1
#define ERR_FILE -2
#define S_AGRC 3

int s_is_arguments(int argc, char **argv)
{
    return ((argc == S_AGRC) && (strcmp(argv[1], "s") == 0));
}

int how_many_numbers(FILE *file)
{
    int check = 1, element, result = 0;

    while (check)
    {
        check = fread(&element, sizeof(int), 1, file);
        if (check == 1)
            result++;
    }
    return result;
}

int get_number_by_pos(FILE *file, int pos, int *number)
{
    fseek(file, (pos * sizeof(int)), SEEK_SET);
    int check, num;
    check = fread(&num, sizeof(int), 1, file);
    if (check)
    {
        *number = num;
        return OK;
    }
    return check;
}

int set_number_by_pos(FILE *file, int pos, int number)
{
    fseek(file, (pos * sizeof(int)), SEEK_SET);
    int check = fwrite(&number, sizeof(int), 1, file);
    return (!check);
}

int swap_by_pos(FILE *file, int pos_1, int pos_2)
{
    int t, num_1;
    int check = get_number_by_pos(file, pos_1, &t);
    if (check != OK)
        return check;
    check = get_number_by_pos(file, pos_2, &num_1);
    if (check != OK)
        return check;
    check = set_number_by_pos(file, pos_1, num_1);
    if (check != OK)
        return check;
    check = set_number_by_pos(file, pos_2, t);
    return check;
}

int insection_sort(FILE *file, int count)
{
    int check, number_1, number_2;
    for (int i = 1; i < count; i++)
    {
        int j = i;
        while (j > 0)
        {
            check = get_number_by_pos(file, (j - 1), &number_1);
            if (check != OK)
                return check;
            check = get_number_by_pos(file, j, &number_2);
            if (check != OK)
                return check;
            if (number_1 <= number_2)
                break;
            check = swap_by_pos(file, (j - 1), j);
            if (check != OK)
                return check;
            j--;
        }
    }
    return OK;
}

int s_file_binary(char *filename)
{
    FILE *file = fopen(filename, "r+b");

    if (file == NULL)
    {
        return ERR_IO;
    }

    if (check_file_size(file) != OK)
    {
        return ERR_FILE;
    }

    int count = how_many_numbers(file);
    int check = insection_sort(file, count);
    fclose(file);
    return check;
}