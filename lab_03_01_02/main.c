#include <stdio.h>
#define N 10
#define M 10
#define MIN_N 0
#define MIN_M 0
#define OK 0
#define LENGHT_ERR -1
#define INPUT_ERR -2

int scan_matrix(int a[][M], int *n, int *m)
{
    int scan_flag = scanf("%d%d", n, m);
    if (scan_flag != 2)
        return INPUT_ERR;
    if ((*n == MIN_N && *m != MIN_M) || (*m == MIN_M && *n != MIN_N))
        return LENGHT_ERR;
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

int condition(int a[][M], int k, int n)
{
    int result = 1;
    if (n == 1)
        result = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i][k] * a[i - 1][k] >= 0)
        {
            result = 0;
            break;
        }
    }
    return result;
}

void fold_by_columns(int a[][M], int answer[], int n, int m)
{
    for (int k = 0; k < m; k++)
        answer[k] = condition(a, k, n);
}

void print(int answer[], int m)
{
    for (int k = 0; k < m; k++)
        printf("%d ", answer[k]);
}

int main(void)
{
    int n, m, scan_flag;
    int array[N][M] = { 0 };
    int answer[M] = { 0 };
    scan_flag = scan_matrix(array, &n, &m);
    if (scan_flag != OK)
        return scan_flag;
    fold_by_columns(array, answer, n, m);
    print(answer, m);
    return OK;
}