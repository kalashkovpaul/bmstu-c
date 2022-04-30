#include <stdio.h>

void swap(void *a, void *b, size_t size)
{
    char *a_ptr = a;
    char *b_ptr = b;
    char t;
    size_t i = 0;
    while (i < size)
    {
        t = *a_ptr;
        *a_ptr = *b_ptr;
        *b_ptr = t;
        a_ptr++;
        b_ptr++;
        i++;
    }
}

void mysort(void *base, size_t nmemb, size_t size, int (*compar)(const void*, const void*))
{
    char *base_beg = base;
    char *base_end = base_beg + nmemb * size;
    char *ptr_i = base_beg + size;
    char *ptr_j = ptr_i;
    while (ptr_i < base_end)
    {
        ptr_j = ptr_i;
        while (ptr_j > base_beg && compar(ptr_j - size, ptr_j) > 0)
        {
            swap(ptr_j - size, ptr_j, size);
            ptr_j -= size;
        }
        ptr_i += size;
    }
}