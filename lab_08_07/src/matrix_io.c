#include <stdio.h>
#include <stdlib.h>
#include "constants.h"
#include "matrix.h"
#include "matrix_io.h"

int scan_matrix(matrix_t *matrix);
int scan_elements(matrix_t *matrix);
void free_matrix(matrix_t *matrix);

int read_matrixes(matrix_t *a, matrix_t*b)
{
    int check = OK;
    check = scan_matrix(a);
    if (check == OK)
        check = scan_matrix(b);
    return check;
}

int scan_matrix(matrix_t *matrix)
{
    int n = 0, m = 0;
    int check = 0;
    check = scanf("%d%d", &n, &m);
    if (check == 2 && n > 0 && m > 0)
    {
        matrix->n = n;
        matrix->m = m;
        matrix->matrix = allocate_matrix(matrix->n, matrix->m);
        if (matrix->matrix)
            check = scan_elements(matrix);
        else
            check = ERR_MEMORY;
        if (check != OK)
            free_matrix(matrix);
    }
    else
        check = ERR_SIZES;
    return check;
}

int scan_elements(matrix_t *matrix)
{
    int check = OK;
    int i = 0, j = 0;
    for (i = 0; i < matrix->n && check == OK; i++)
    {
        check = 1;
        for (j = 0; j < matrix->m && check == 1; j++)
        {
            check = scanf("%lld", &(matrix->matrix[i][j]));
        }
        if (check != 1)
            check = ERR_ELEMENTS;
        else
            check = OK;
    }
    return check;
}

long long int **allocate_matrix(int n, int m)
{
    long long int **ptrs, *data;
    ptrs = malloc(n * sizeof(long long int *));
    data = calloc(n * m, sizeof(long long int));
    if (!data)
    {
        free(ptrs);
        ptrs = NULL;
    }
    if (ptrs != NULL)
    {
        for (int i = 0; i < n; i++)
            ptrs[i] = data + i * m;
    }
    return ptrs;
}

void free_matrix(matrix_t *matrix)
{
    matrix->n = 0;
    matrix->m = 0;
    if (matrix->matrix != NULL)
        free(matrix->matrix[0]);
    free(matrix->matrix);
    matrix->matrix = NULL;
}

void print_result(matrix_t matrix)
{
    for (int i = 0; i < matrix.n; i++)
    {
        for (int j = 0; j < matrix.m - 1; j++)
            printf("%lld ", matrix.matrix[i][j]);
        printf("%lld\n", matrix.matrix[i][matrix.m - 1]);
    }
}

void free_all_matrixes(matrix_t *a, matrix_t *b, matrix_t *c)
{
    free_matrix(a);
    free_matrix(b);
    free_matrix(c);
}