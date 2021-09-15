#include <stdio.h>
#define N 10
#define MIN_N 1
#define OK 0
#define LENGHT_ERR -1
#define INPUT_ERR -2

int scan(int a[], int *size)
{
    int input = scanf("%d", size);
    if (input != 1)
        return INPUT_ERR;
    else if (*size > N || *size < MIN_N)
        return LENGHT_ERR;
    else
    {
        for (int i = 0; i < *size; i++)
        {
            input = scanf("%d", &a[i]);
            if (input != 1)
            return INPUT_ERR;
        }
        return OK;
    }
}

int fib(int *n, int *previous, int *fibon)
{
    if (*n == 0 || *n == 1)
        return (*n)++;
    else
    {
        int t;
        t = *fibon;
        *fibon += *previous;
        *previous = t;
        *n = *n + 1;
        return *fibon + *previous;
    }
}

int insert_element(const int a[], int b[], int size)
{
    int j = 0, n = 0, previous = 1, fibon = 0;
    for (int i = 0; i < size; i++)
    {
        b[j++] = a[i];
        if (a[i] % 3 == 0)
        {
            b[j++] = fib(&n, &previous, &fibon);
        }
    }
    return j;
}

int print(int b[], int size)
{
    if (size == 0)
        return INPUT_ERR;
    for (int i = 0; i < size; i++)
    {
        printf("%d ", b[i]);
    }
    return OK;
}

int main(void)
{
    int a[N] = { 0 };
    int b[2 * N] = { 0 };
    int size, s, j;
    s = scan(a, &size);
    if (s != OK)
        return s;
    j = insert_element(a, b, size);
    if (print(b, j) == INPUT_ERR)
        return INPUT_ERR;
    else 
        return OK;
}