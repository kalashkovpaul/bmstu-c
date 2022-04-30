#include <stdio.h>

#include "test_my_snprintf.h"

int main()
{
    int error_count = 0;
    error_count += activate_test_my_snprintf();
    printf("Total: %d\n", error_count);
    return error_count;
}