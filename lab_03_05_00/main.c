#include <stdio.h>
#define N 10
#define M 10
#define MIN_N 0
#define MIN_M 0
#define OK 0
#define LENGHT_ERR -1
#define INPUT_ERR -2
#define NO_PRIME -3

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

int is_prime(int number)
{
    if (number <= 1)
        return 0;
    for (int i = 2; i <= number / 2; ++i)
        if (number % i == 0)
            return 0;
    return 1;
}

void reverse(int array[], int length)
{
    int t, i;
    for (i = 0; i < length / 2; i++)
    {
        t = array[i];
        array[i] = array[length - i - 1];
        array[length - i - 1] = t;
    }
}

void find_proper_elements(int array[][M], int n, int m, int answer[], int *length_answer)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (is_prime(array[i][j]))
                answer[(*length_answer)++] = array[i][j];
        }
}

void replace_proper_elements(int array[][M], int n, int m, const int answer[])
{
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (is_prime(array[i][j]))
                array[i][j] = answer[index++];
}

void print(int array[][M], int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            printf("%d%s", array[i][j], (j == m - 1) ? "\n" : " ");
}

int main(void)
{
    int n, m, scan_flag, answer_length = 0;
    int array[N][M] = { 0 };
    int answer[N * M] = { 0 };
    scan_flag = scan_matrix(array, &n, &m);
    if (scan_flag != OK)
        return scan_flag;
    find_proper_elements(array, n, m, answer, &answer_length);
    if (answer_length == 0)
        return NO_PRIME;
    reverse(answer, answer_length);
    replace_proper_elements(array, n, m, answer);
    print(array, n, m);
    return OK;
}