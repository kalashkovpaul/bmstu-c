#include <stdio.h>
#include "matrix_io.h"
#include "matrix_operations.h"
#include "matrix.h"

int test_cut_matrixes_squared()
{
    int error_amount = 0;
    long long matrix_1[3][3] = { { 0, 1, 2 }, { 3, 4, 5 }, { 6, 7, 8 } };
    long long *m_1[3] = { matrix_1[0], matrix_1[1], matrix_1[2] };
    long long matrix_2[2][2] = { { 1, 2 }, { 3, 4 } };
    long long *m_2[2] = { matrix_2[0], matrix_2[1] };
    matrix_t mat_1 = { m_1, 3, 3 };
    matrix_t mat_2 = { m_2, 2, 2 };
    cut_matrixes(&mat_1, &mat_2);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (mat_1.matrix[i][j] != matrix_1[i][j])
                error_amount++;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            if (mat_2.matrix[i][j] != matrix_2[i][j])
                error_amount++;
    if (error_amount != 0)
        printf("Ошибка в cut_squared!\n");
    return error_amount;
}

int test_cut_matrixes_usual()
{
    int error_amount = 0;
    long long **m_1 = allocate_matrix(1, 3);
    m_1[0][0] = 0;
    m_1[0][1] = 1;
    m_1[0][2] = 2;
    long long **m_2 = allocate_matrix(3, 1);
    m_2[0][0] = 1;
    m_2[1][0] = 2;
    m_2[2][0] = 3;
    matrix_t mat_1 = { m_1, 1, 3 };
    matrix_t mat_2 = { m_2, 3, 1 };
    matrix_t mat = { NULL, 0, 0 };
    cut_matrixes(&mat_1, &mat_2);
    if (mat_1.n != 1 || mat_1.m != 1 || mat_1.matrix[0][0] != 2)
        error_amount++;
    if (mat_2.n != 1 || mat_2.m != 1 || mat_2.matrix[0][0] != 3)
        error_amount++;
    free_all_matrixes(&mat_1, &mat_2, &mat);
    if (error_amount != 0)
        printf("Ошибка в cut_usual!\n");
    return error_amount;
}

int test_even_matrixes_usual_1()
{
    int error_amount = 0;
    long long **m_1 = allocate_matrix(1, 1);
    m_1[0][0] = 5;
    long long **m_2 = allocate_matrix(2, 2);
    m_2[0][0] = 1;
    m_2[0][1] = 2;
    m_2[1][0] = 3;
    m_2[1][1] = 4;
    matrix_t mat_1 = { m_1, 1, 1 };
    matrix_t mat_2 = { m_2, 2, 2 };
    matrix_t mat = { NULL, 0, 0 };
    even_matrixes(&mat_1, &mat_2);
    if (mat_1.n != 2 || mat_1.m != 2 || mat_1.matrix[0][0] != 5 || mat_1.matrix[0][1] != 5 || mat_1.matrix[1][0] != 5 || mat_1.matrix[1][1] != 5)
        error_amount++;
    free_all_matrixes(&mat_1, &mat_2, &mat);
    if (error_amount != 0)
        printf("Ошибка в even_usual_1!\n");
    return error_amount;
}

int test_even_matrixes_usual_2()
{
    int error_amount = 0;
    long long **m_2 = allocate_matrix(1, 1);
    m_2[0][0] = 5;
    long long **m_1 = allocate_matrix(2, 2);
    m_1[0][0] = 1;
    m_1[0][1] = 2;
    m_1[1][0] = 3;
    m_1[1][1] = 4;
    matrix_t mat_1 = { m_1, 2, 2 };
    matrix_t mat_2 = { m_2, 1, 1 };
    matrix_t mat = { NULL, 0, 0 };
    even_matrixes(&mat_1, &mat_2);
    if (mat_2.n != 2 || mat_2.m != 2 || mat_2.matrix[0][0] != 5 || mat_2.matrix[0][1] != 5 || mat_2.matrix[1][0] != 5 || mat_2.matrix[1][1] != 5)
        error_amount++;
    free_all_matrixes(&mat_1, &mat_2, &mat);
    if (error_amount != 0)
        printf("Ошибка в even_usual_2!\n");
    return error_amount;
}

int test_even_matrixes_complex_1()
{
    int error_amount = 0;
    long long **m_1 = allocate_matrix(3, 3);
    long long **m_2 = allocate_matrix(2, 2);
    m_2[0][0] = 1;
    m_2[0][1] = 2;
    m_2[1][0] = 3;
    m_2[1][1] = 4;
    matrix_t mat_1 = { m_1, 3, 3 };
    matrix_t mat_2 = { m_2, 2, 2 };
    matrix_t mat = { NULL, 0, 0 };
    even_matrixes(&mat_1, &mat_2);
    if (mat_2.n != 3 || mat_2.m != 3 || mat_2.matrix[0][0] != 1 || mat_2.matrix[0][1] != 2 || mat_2.matrix[0][2] != 2 || \
        mat_2.matrix[1][0] != 3 || mat_2.matrix[1][1] != 4 || mat_2.matrix[1][2] != 4 || \
        mat_2.matrix[2][0] != 1 || mat_2.matrix[2][1] != 2 || mat_2.matrix[2][2] != 2)
        error_amount++;
    free_all_matrixes(&mat_1, &mat_2, &mat);
    if (error_amount != 0)
        printf("Ошибка в even_complex_1!\n");
    return error_amount;
}

int test_even_matrixes_complex_2()
{
    int error_amount = 0;
    long long **m_2 = allocate_matrix(3, 3);
    long long **m_1 = allocate_matrix(2, 2);
    m_1[0][0] = 1;
    m_1[0][1] = 2;
    m_1[1][0] = 3;
    m_1[1][1] = 4;
    matrix_t mat_2 = { m_2, 3, 3 };
    matrix_t mat_1 = { m_1, 2, 2 };
    matrix_t mat = { NULL, 0, 0 };
    even_matrixes(&mat_1, &mat_2);
    if (mat_1.n != 3 || mat_1.m != 3 || mat_1.matrix[0][0] != 1 || mat_1.matrix[0][1] != 2 || mat_1.matrix[0][2] != 2 || \
        mat_1.matrix[1][0] != 3 || mat_1.matrix[1][1] != 4 || mat_1.matrix[1][2] != 4 || \
        mat_1.matrix[2][0] != 1 || mat_1.matrix[2][1] != 2 || mat_1.matrix[2][2] != 2)
        error_amount++;
    free_all_matrixes(&mat_1, &mat_2, &mat);
    if (error_amount != 0)
        printf("Ошибка в even_complex_2!\n");
    return error_amount;
}

int test_operations(void)
{
    int error_amount = 0;
    error_amount += test_cut_matrixes_squared();
    error_amount += test_cut_matrixes_usual();
    error_amount += test_even_matrixes_usual_1();
    error_amount += test_even_matrixes_usual_2();
    error_amount += test_even_matrixes_complex_1();
    error_amount += test_even_matrixes_complex_2();
    return error_amount;
}