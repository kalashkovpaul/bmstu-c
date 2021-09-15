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

int find_min(int row[], int m)
{
    int index_of_min = 0;
    for (int j = 1; j < m; j++)
        if (row[j] < row[index_of_min])
            index_of_min = j;
    return row[index_of_min];
}

void create_comparator_array(int array[][M], int answer[], int n, int m)
{
    for (int i = 0; i < n; i++)
        answer[i] = find_min(array[i], m);
}

void swap_arrays(int array_one[], int array_two[], int n)
{
    int t;
    for (int i = 0; i < n; i++)
    {
        t = array_one[i];
        array_one[i] = array_two[i];
        array_two[i] = t;
    }
}
void sort(int array[][M], int answer[], int n, int m)
{
    int min_position;
    for (int i = 0; i < n; i++)
    {
        min_position = i;
        for (int j = i + 1; j < n; j++)
            if (answer[min_position] < answer[j])
                min_position = j;
        swap_arrays(array[min_position], array[i], m);
        int tmp = answer[min_position];
        answer[min_position] = answer[i];
        answer[i] = tmp;
    }
}

void sort_rows_by_condition(int array[][M], int answer[], int n, int m)
{
    create_comparator_array(array, answer, n, m);
    sort(array, answer, n, m);
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
    int answer[N] = { 0 };
    scan_flag = scan_matrix(array, &n, &m);
    if (scan_flag != OK)
        return scan_flag;
    sort_rows_by_condition(array, answer, n, m);
    print(array, n, m);
    return OK;
}