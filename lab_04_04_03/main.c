#include <stdio.h>
#include "constants.h"
#include "my_string.h"
#include "is_phone_number.h"

int main(void)
{
    char string[MAX_STR_LEN + 1];
    int length, check, result;
    check = read_line(string, MAX_STR_LEN + 1, &length);
    if (check != 0)
        return check;
    result = is_phone_number(string, length);
    if (result)
        printf("YES\n");
    else 
        printf("NO\n");
    return OK;
}