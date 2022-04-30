#include "stdio.h"

#include "array.h"
#include "constants.h"

int fill_array_with_fib(int *array, int n)
{
    int i = 0;
    if (n > 0 && array != NULL)
    {
        array[i++] = 0;
        if (n > 1)
            array[i++] = 1;
        while (i < n && i < MAX_LENTH)
        {
            array[i] = array[i - 1] + array[i - 2];
            i++;
        }        
    }
    return i;
}

int is_unique(int array[], int n, int element)
{
    int unique = 1;
    int i = 0;
    while (i < n && unique)
    {
        if (array[i] == element)
            unique = 0;
        i++;
    }
    return unique;
}

int transfer_unique(int *src, int *dst, int n)
{
    int i = 0, j = 0;
    while (i < n)
    {
        if (is_unique(src, i, src[i]))
        {
            if (dst != NULL)
                dst[j] = src[i];
            j++;
        }
        i++;
    }
    return j;
}