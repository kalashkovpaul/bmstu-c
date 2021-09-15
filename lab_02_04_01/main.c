#include <stdio.h>
#define N 10
#define OK 0
#define INPUT_ERR -1
#define SPECIAL 100

int scan(int a[], int *size)
{
    int j = 0, in, input;
    for (int i = 0; i < N + 1; i++)
    {
        input = scanf("%d", &in);
        if (input != 1)
            break;
        else
        {
            if (j != N)
            {
                a[i] = in;
            }
            j++;
        }       
    }
    if (j == 11)
    {
        *size = 10;
        return SPECIAL;
    }
    else
    {
        *size = j;
        return OK;
    }
}

int sort(int a[], int size)
{
    int t;
    for (int i = 1; i < size; i++)     
        for (int j = i; j > 0 && a[j - 1] > a[j]; j--) 
        {
            t = a[j - 1];
            a[j - 1] = a[j];
            a[j] = t;
        }
    return OK;
}

int print(int b[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", b[i]);
    }
    return OK;
}

int main(void)
{
    int a[N];
    int size, code;
    code = scan(a, &size);
    if (size == 0)
        return INPUT_ERR;
    sort(a, size);
    print(a, size);
    return code;
}