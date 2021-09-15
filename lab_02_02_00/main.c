#include <stdio.h>
#define N 10
#define MIN_N 2
#define OK 0
#define LENGHT_ERR -1
#define INPUT_ERR -2

int scan(int a[], int *size)
{
    int input = scanf("%d", size);
    if (input != 1)
        return INPUT_ERR;
    if (*size > N || *size < MIN_N)
        return LENGHT_ERR;
    for (int i = 0; i < *size; i++)
    {
        input = scanf("%d", &a[i]);
        if (input != 1)
            return INPUT_ERR;
    }
    return OK;
}

double arithmetic_mean(const int a[], int size)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += a[i];
    }
    sum /= size;
    return sum;
}

int bigger_than_key(const int a[], int b[], int size, double key)
{
    int size_b = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] > key)
            b[size_b++] = a[i];
    }
    return size_b;
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
    int b[N] = { 0 };
    int size_a, s, size_b;
    double a_mean;
    s = scan(a, &size_a);
    if (s != OK)
        return s;
    a_mean = arithmetic_mean(a, size_a);
    size_b = bigger_than_key(a, b, size_a, a_mean);
    if (print(b, size_b) == INPUT_ERR)
        return INPUT_ERR;
    else 
        return OK;
}