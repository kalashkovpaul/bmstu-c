#ifndef SORT_H_

#define SORT_H_

#include <stdio.h>

void mysort(void *base, size_t nmemb, size_t size, int (*compar)(const void*, const void*));

#endif