#include <stdio.h>
#define N 10
#define OK 0
#define LENGHT_ERR -1
#define INPUT_ERR -2

int scan(int *a, int *len)
{
    int *end;
    int input = scanf("%d", len);
    end = a + *len;
    if (input == 1 && (*len > 10 || *len < 1))
    return LENGHT_ERR;
    else if (input != 1)
    return INPUT_ERR;
    else
    {
        while (a < end)
        {
            input = scanf("%d", a);
            if (input != 1)
            return INPUT_ERR;
            a += 1;
        }
        return OK;
    }
}

int operation(int *a, int *end)
{
    int answer = 0, iteration = 1;
    int negative = *a;
    do 
    {
        iteration *= *a;
        if (*a < 0)
            negative = *a;
        answer += iteration;
        a += 1;
    }
    while (negative > 0 && a < end);
    return answer;
}

void print(int answer)
{
    printf("%d", answer);
}

int main(void)
{
    int a[N] = { 0 };
    int *end = NULL, len, s, answer;
    s = scan(a, &len);
    end = a + len;
    if (s == LENGHT_ERR)
    return LENGHT_ERR;
    if (s == INPUT_ERR)
    return INPUT_ERR;
    answer = operation(a, end);
    print(answer);
    return OK;
}