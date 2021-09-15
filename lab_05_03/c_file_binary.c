#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define OK 0
#define ERR_IO -1
#define ERR_WB -2
#define P_ARGC 4

int is_digit(char ch)
{
    return (ch >= '0' && ch <= '9');
}

int str_is_digit(char *str)
{   
    int result = 1;

    while (*str)
    {
        if (!is_digit(*str))
            result = 0;
        str++;
    }
    return result;
}

int c_is_arguments(int argc, char **argv)
{
    return ((argc == P_ARGC) && (strcmp(argv[1], "c") == 0) && (str_is_digit(argv[2])));
}

int c_file_binary(char *filename, char *str_number)
{
    errno = OK;
    long int number = strtol(str_number, NULL, 10);
    
    if (errno != OK)
    {
        return ERR_IO;
    }   
    FILE *file = fopen(filename, "wb");

    if (file == NULL)
    {
        return ERR_IO;
    }

    if (number <= 0)
    {
        return ERR_IO;
    }

    int element, check = 0;

    for (int i = 0; i < number; i++)
    {
        element = rand();
        check = fwrite(&element, sizeof(int), 1, file);
        if (check != 1)
            return ERR_WB;
    }
    fclose(file);
    return OK;
}