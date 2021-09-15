#include <stdio.h>
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

void shift(char *string)
{
    while (*string)
    {
        *string = *(string + 1);
        string++;
    }
}

void my_strip(char *string, int length)
{
    while (*string == ' ' || *string == '\t' || *string == '\n' || *string == '\r' || *string == '\f' || *string == '\v')
    {
        shift(string);
        length--;
    }
    while (string[length - 1] == ' ' || string[length - 1] == '\t' || string[length - 1] == '\n' 
        || string[length - 1] == '\r' || string[length - 1] == '\f' || string[length - 1] == '\v')
        length--;
    string[length] = 0;
}