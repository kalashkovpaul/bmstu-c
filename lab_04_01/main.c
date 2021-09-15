#include <stdio.h>
#include <string.h>
#include "my_functions.h"
#define MAX_LEN 256
#define OK 0
#define STR_LEN_ERR -1

int main(void)
{
    char string1[MAX_LEN + 1], string2[MAX_LEN + 1];
    int length1 = 0, length2 = 0;
    int check = read_line(string1, MAX_LEN + 1, &length1);
    if (check != OK)
        return check;
    check = read_line(string2, MAX_LEN + 1, &length2);
    if (check != OK)
        return check;
    char *answer = strpbrk(string1, string2);
    char *my_answer = my_strpbrk(string1, string2);
    if (answer != NULL)
        printf("%c\n", *answer);
    if (my_answer != NULL)
        printf("%c\n", *my_answer);
    check = (answer != my_answer);
    return check;
}
