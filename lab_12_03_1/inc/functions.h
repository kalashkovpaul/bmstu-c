#ifndef _DYNAMIC_ARRAY_H_

#define _DYNAMIC_ARRAY_H_

#include <stdlib.h>

int read_array(char *filename, int **arr, int **end_arr);
int key(const int *pb_src, const int *pe_arr, int **pb_dst, int **pe_dst);
int compare(const void *p_1, const void *p_2);
int file_print_array(char *filename, int *arr, int *arr_end);
void free_array(int *arr, int *end_arr);

#endif