#include <stdio.h>
#define N 10
#define M 10
#define MIN_N 0
#define MIN_M 0
#define OK 0
#define LENGHT_ERR -1
#define INPUT_ERR -2

int create_square_matrix(int a[][N], int *n, int *m)
{
    int scan_flag = scanf("%d%d", n, m);
    if (scan_flag != 2)
        return INPUT_ERR;
    if (*n != *m)
        return LENGHT_ERR;
    if ((*n == MIN_N && *m != MIN_M) || (*m == MIN_M && *n != MIN_N))
        return LENGHT_ERR;
    if (*n < MIN_N || *m < MIN_M || *n > N || *m > M)
        return LENGHT_ERR;
    return OK;
}

void fill_spiral(int array[][M], int n, int m)
{
    int number = 1, first = 0, penultimate = n - 1, index, i;
    while (first < penultimate)
    {
        index = first;
        for (i = first; i < penultimate; i++)
            array[index][i] = number++;
        index = penultimate;
        for (i = first; i < penultimate; i++)
            array[i][index] = number++;
        index = penultimate;
        for (i = penultimate; i > first; i--)
            array[index][i] = number++;
        index = first;
        for (i = penultimate; i > first; i--)
            array[i][index] = number++;
        first++;
        penultimate--;
    }
    if (n % 2 == 1)
        array[n / 2][n / 2] = number;
}

void print(int array[][M], int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            printf("%d%s", array[i][j], (j == m - 1) ? "\n" : " ");
}

int main(void)
{
    int n, m, create_flag;
    int array[N][M] = { 0 };
    create_flag = create_square_matrix(array, &n, &m);
    if (create_flag != OK)
        return create_flag;
    fill_spiral(array, n, m);
    print(array, n, m);
    return OK;
}