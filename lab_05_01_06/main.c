#include <stdio.h>
#include "process.h"
#define OK 0

int main(void)
{
    int result = 0, check;
    check = process(stdin, &result);
    if (check == OK)
        printf("Result: %d", result);
    return check;
}