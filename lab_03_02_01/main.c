#include <stdio.h>
#define N 10
#define M 10
#define MIN_N 2
#define MIN_M 2
#define OK 0
#define LENGHT_ERR -1
#define INPUT_ERR -2

int scan_matrix(int a[][M], int *n, int *m)
{
    int scan_flag = scanf("%d%d", n, m);
    if (scan_flag != 2)
        return INPUT_ERR;
    if (*n < MIN_N || *m < MIN_M || *n > N || *m > M)
        return LENGHT_ERR;
    for (int i = 0; i < *n; i++)
        for (int j = 0; j < *m; j++)
        {
            scan_flag = scanf("%d", &a[i][j]);
            if (scan_flag != 1)
                return INPUT_ERR;
        }
    return OK;
}

int sum_digits(int a)
{
    int answer = 0;
    if (a < 0)
        a = a * (-1);
    while (a > 0)
    {
        answer += a % 10;
        a /= 10;
    }
    return answer;
}

void find(int array[][M], int n, int m, int *target_i, int *target_j)
{
    int max = array[0][0], current;
    *target_i = 0;
    *target_j = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            current = sum_digits(array[i][j]);
            if (current < max)
            {
                *target_i = i;
                *target_j = j;
                max = current;
            }
        }
}

void delete_row(int array[][M], int *n, int m, int target_i)
{
    for (int i = target_i; i < *n - 1; i++)
        for (int j = 0; j < m; j++)
            array[i][j] = array[i + 1][j];
    (*n)--;
}

void delete_column(int array[][M], int n, int *m, int target_j)
{
    for (int j = target_j; j < *m - 1; j++)
        for (int i = 0; i < n; i++)
            array[i][j] = array[i][j + 1];
    (*m)--;
}

void delete(int array[][M], int *n, int *m, int target_i, int target_j)
{
    delete_row(array, n, *m, target_i);
    delete_column(array, *n, m, target_j);
}

void find_and_delete(int array[][M], int *n, int *m)
{
    int target_i, target_j;
    find(array, *n, *m, &target_i, &target_j);
    delete(array, n, m, target_i, target_j);
}

void print(int array[][M], int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            printf("%d%s", array[i][j], (j == m - 1) ? "\n" : " ");
}

int main(void)
{
    int n, m, scan_flag;
    int array[N][M] = { 0 };
    scan_flag = scan_matrix(array, &n, &m);
    if (scan_flag != OK)
        return scan_flag;
    find_and_delete(array, &n, &m);
    print(array, n, m);
    return OK;
}