#include <stdio.h>
#include <math.h>
#define N 10
#define OK 0
#define LENGHT_ERR -1
#define INPUT_ERR -2

int scan(int a[], int *size)
{
    if (scanf("%d", size) != 1)
        return INPUT_ERR;
    if (*size > 10 || *size < 1)
        return LENGHT_ERR;
    else
    {
        for (int i = 0; i < *size; i++)
        {
            if (scanf("%d", &a[i]) != 1)
                return INPUT_ERR;
        }
        return OK;
    }
}

double geometric_mean(const int a[], int size, double *answer)
{
    double s = 1;
    int n = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] > 0)
        {
            s *= a[i];
            n += 1;
        }
    }
    if (n > 0)
    {
        s = pow(s, 1.0 / n);
        *answer = s;
        return OK;
    }
    else 
        return INPUT_ERR;
}

void print(double answer)
{
    printf("%lf", answer);
}

int main(void)
{
    int a[N];
    int size, s;
    double answer;
    s = scan(a, &size);
    if (s != OK)
        return s;
    s = geometric_mean(a, size, &answer);
    if (s != OK)
        return s;
    else
        print(answer);
    return OK;
}