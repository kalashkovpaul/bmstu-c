#include <stdio.h>
#include "constants.h"
#include "io.h"

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

void print(char result[])
{
    printf("%s\n", result);
}
