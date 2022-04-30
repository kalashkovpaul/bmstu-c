#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "matrix.h"
#include "constants.h"
#include "matrix_io.h"

int cut_matrix(matrix_t *matrix);
int cut_matrix_by_rows(matrix_t *matrix);
int cut_matrix_by_columns(matrix_t *matrix);
int find_row_with_min(matrix_t *matrix);
void shift_rows(matrix_t *matrix, int shift_index);
int change_matrix_to_square(matrix_t *matrix);
int find_column_with_min(matrix_t *matrix);
void shift_columns(matrix_t *matrix, int shift_index);
int expand_matrix(matrix_t *matrix, int size);
void copy_square_matrix(long long int **dst, long long int **src, int size);
void fill_rows(long long int **matrix, int old_size, int size);
void fill_columns(long long int  **matrix, int old_size, int size);
long long int get_mlt_of_column(long long int **matrix, int i, int j);
long long int get_max_of_row(long long int **matrix, int i, int j);
int multiply_matrixes(matrix_t a, matrix_t b, matrix_t *c);
void multiply(long long int **first_matrix, long long int **second_matrix, long long int **result, int size);

int cut_matrixes(matrix_t *a, matrix_t *b)
{
    int check = OK;
    check = cut_matrix(a);
    if (check == OK)
        check = cut_matrix(b);
    return check;
}

int cut_matrix(matrix_t *matrix)
{
    int check = OK;
    if (matrix->n > matrix->m)
        check = cut_matrix_by_rows(matrix);
    else if (matrix->n < matrix->m)
        check = cut_matrix_by_columns(matrix);
    return check;
}

int cut_matrix_by_rows(matrix_t *matrix)
{
    int removable_index = 0;
    while (matrix->n != matrix->m)
    {
        removable_index = find_row_with_min(matrix);
        shift_rows(matrix, removable_index);
        matrix->n -= 1;
    }
    int check = change_matrix_to_square(matrix);
    return check;
}

int find_row_with_min(matrix_t *matrix)
{
    int result = 0;
    long long min = matrix->matrix[0][0];
    for (int i = 0; i < matrix->m; i++)
        for (int j = 0; j < matrix->n; j++)
            if (matrix->matrix[j][i] < min)
            {
                min = matrix->matrix[j][i];
                result = j;
            }
    return result;
}

void shift_rows(matrix_t *matrix, int shift_index)
{
    for (int i = shift_index; i < matrix->n - 1; i++)
        for (int j = 0; j < matrix->m; j++)
            matrix->matrix[i][j] = matrix->matrix[i + 1][j];
    for (int j = 0; j < matrix->m; j++)
        matrix->matrix[matrix->n - 1][j] = 0;
}

int change_matrix_to_square(matrix_t *matrix)
{
    int check = OK;
    long long int **square_matrix = allocate_matrix(matrix->n, matrix->m);
    if (square_matrix)
    {
        for (int i = 0; i < matrix->n; i++)
            for (int j = 0; j < matrix->m; j++)
                square_matrix[i][j] = matrix->matrix[i][j];
        free(matrix->matrix[0]);
        free(matrix->matrix);
        matrix->matrix = square_matrix;
    }
    else
        check = ERR_MEMORY;
    return check;
}

int cut_matrix_by_columns(matrix_t *matrix)
{
    int removable_index = 0;
    while (matrix->n != matrix->m)
    {
        removable_index = find_column_with_min(matrix);
        shift_columns(matrix, removable_index);
        matrix->m -= 1;
    }
    int check = change_matrix_to_square(matrix);
    return check;
}

int find_column_with_min(matrix_t *matrix)
{
    int result = 0;
    long long min = matrix->matrix[0][0];
    for (int i = 0; i < matrix->m; i++)
        for (int j = 0; j < matrix->n; j++)
            if (matrix->matrix[j][i] < min)
            {
                min = matrix->matrix[j][i];
                result = i;
            }
    return result;
}

void shift_columns(matrix_t *matrix, int shift_index)
{
    for (int i = 0; i < matrix->n; i++)
        for (int j = shift_index; j < matrix->m - 1; j++)
            matrix->matrix[i][j] = matrix->matrix[i][j + 1];
    for (int i = 0; i < matrix->n; i++)
        matrix->matrix[i][matrix->m - 1] = 0;
}

int even_matrixes(matrix_t *a, matrix_t *b)
{
    int check = OK;
    if (a->n > b->n)
        check = expand_matrix(b, a->n);
    else if (a->n < b->m)
        check = expand_matrix(a, b->n);
    return check;
}

int expand_matrix(matrix_t *matrix, int size)
{
    int check = OK;
    long long int **expanded_matrix = allocate_matrix(size, size);
    if (expanded_matrix)
    {
        copy_square_matrix(expanded_matrix, matrix->matrix, matrix->n);
        fill_rows(expanded_matrix, matrix->n, size);
        fill_columns(expanded_matrix, matrix->m, size);
        free(matrix->matrix[0]);
        free(matrix->matrix);
        matrix->n = size;
        matrix->m = size;
        matrix->matrix = expanded_matrix;
    }
    else
        check = ERR_MEMORY;
    return check;
}

void copy_square_matrix(long long int **dst, long long int **src, int size)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            dst[i][j] = src[i][j];
}

void fill_rows(long long int **matrix, int old_size, int size)
{
    long long int element = 0;
    for (int i = old_size; i < size; i++)
        for (int j = 0; j < old_size; j++)
        {
            element = get_mlt_of_column(matrix, i, j);
            if (element < 0)
                element *= -1;
            element = (long long int)floor(pow(element, 1.0 / i));
            matrix[i][j] = element;
        }
}

long long int get_mlt_of_column(long long int **matrix, int i, int j)
{
    long long int result = 1;
    for (int index = 0; index < i; index++)
        result *= matrix[index][j];
    return result;
}

void fill_columns(long long int **matrix, int old_size, int size)
{
    for (int i = 0; i < size; i++)
        for (int j = old_size; j < size; j++)
        {
            matrix[i][j] = get_max_of_row(matrix, i, j);
        }
}

long long int get_max_of_row(long long int **matrix, int i, int j)
{
    long long int max = matrix[i][0];
    for (int index = 0; index < j; index++)
        if (matrix[i][index] > max)
            max = matrix[i][index];
    return max;
}

int multiply_matrixes(matrix_t a, matrix_t b, matrix_t *c)
{
    int p = 0, y = 0;
    int check = 0;
    check = scanf("%d%d", &p, &y);
    if (check == 2 && p >= 0 && y >= 0)
    {
        check = OK;
        long long int **result = allocate_matrix(a.n, a.n);
        long long int **tmp = allocate_matrix(a.n, a.n);
        if (result && tmp)
        {
            for (int i = 0; i < a.n; i++)
                result[i][i] = 1;
            for (int i = 0; i < p; i++)
            {
                memset(tmp[0], 0, a.n * a.n * sizeof(int));
                copy_square_matrix(tmp, result, a.n);
                multiply(tmp, a.matrix, result, a.n);
            }
            for (int i = 0; i < y; i++)
            {
                memset(tmp[0], 0, a.n * a.n * sizeof(int));
                copy_square_matrix(tmp, result, a.n);
                multiply(tmp, b.matrix, result, a.n);
            }
            free(tmp[0]);
            free(tmp);
            tmp = NULL;
            c->n = a.n;
            c->m = a.n;
            c->matrix = result;
        }
        else
            check = ERR_MEMORY;
    }
    else
        check = ERR_POWER;
    return check;
}

void multiply(long long int **first_matrix, long long int **second_matrix, long long int **result, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < size; k++)
                result[i][j] += first_matrix[i][k] * second_matrix[k][j];
        }
    }
}