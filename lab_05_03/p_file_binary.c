#include <stdio.h>
#include <string.h>
#ifndef _CHECK_FILE_SIZE_H_

#define _CHECK_FILE_SIZE_H_
#include "check_file_size.h"

#endif
#define OK 0
#define ERR_IO -1
#define ERR_FILE -2
#define P_ARGC 3

int p_is_arguments(int argc, char **argv)
{
    return ((argc == P_ARGC) && (strcmp(argv[1], "p") == 0));
}

int p_file_binary(char *filename)
{
    FILE *file = fopen(filename, "rb");

    if (file == NULL)
    {
        return ERR_IO;
    }

    if (check_file_size(file) != OK)
    {
        return ERR_FILE;
    }

    int check = 1, element;

    while (check)
    {
        check = fread(&element, sizeof(int), 1, file);
        if (check == 1)
            printf("%d\n", element);
    }
    fclose(file);
    return OK;
}