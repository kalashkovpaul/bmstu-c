#include <stdio.h>
#define N 10
#define M 10
#define MIN_N 0
#define MIN_M 0
#define OK 0
#define LENGHT_ERR -1
#define INPUT_ERR -2

int scan_square_matrix(int a[][N], int *n, int *m)
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
    for (int i = 0; i < *n; i++)
        for (int j = 0; j < *n; j++)
        {
            scan_flag = scanf("%d", &a[i][j]);
            if (scan_flag != 1)
                return INPUT_ERR;
        }
    return OK;
}

void swap_elements(int array[][N], int n)
{
    int t, i, j;
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n - i; j++)
        {
            t = array[j][i];
            array[j][i] = array[j][n - i - 1];
            array[j][n - i - 1] = t;
        }
    }
}

void print(int array[][M], int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            printf("%d%s", array[i][j], (j == n - 1) ? "\n" : " ");
}

int main(void)
{
    int n, m, scan_flag;
    int array[N][M] = { 0 };
    scan_flag = scan_square_matrix(array, &n, &m);
    if (scan_flag != OK)
        return scan_flag;
    swap_elements(array, n);
    print(array, n, m);
    return OK;
}