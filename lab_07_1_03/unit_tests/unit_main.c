#include <stdio.h>
#include "check_key.h"
#include "check_mysort.h"

int main(void)
{
    int error_amount = 0;
    error_amount += check_key();
    error_amount += check_mysort();
    printf("Error amount = %d", error_amount);
    return error_amount;
}