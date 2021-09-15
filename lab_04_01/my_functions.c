#include <stdio.h>
#include "my_functions.h"
#define MAX_LEN 256
#define OK 0
#define STR_LEN_ERR -1

int read_line(char *string, int size, int *length)
{
    int ch, i = 0;
    while ((ch = getchar()) != '\n' && ch != EOF)
        if (i < size - 1)
            string[i++] = ch;
        else
            return STR_LEN_ERR;
    string[i] = '\0';
    *length = i;
    return OK;
}

char *my_strpbrk(char *string1, char *string2)
{
    char *current_string2 = string2;
    while (*string1)
    {
        while (*current_string2)
        {
            if (*string1 == *current_string2)
                return string1;
            current_string2++;
        }
        current_string2 = string2;
        string1++;
    }
    return NULL;
}