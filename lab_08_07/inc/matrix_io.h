#ifndef MATRIX_IO_H_

#define MATRIX_IO_H_

#include "matrix.h"

int read_matrixes(matrix_t *a, matrix_t*b);
long long int **allocate_matrix(int n, int m);
void print_result(matrix_t matrix);
void free_all_matrixes(matrix_t *a, matrix_t *b, matrix_t *c);

#endif