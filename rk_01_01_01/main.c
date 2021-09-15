#include <stdio.h>
#define OK 0
#define INPUT_ERR -1

int find_min(int number)
{
    int min = 10;
    while (number > 0)
    {
        if (number % 10 < min)
        {
            min = number % 10;
        }
        number /= 10;
    }
    return min;
}

int find_max(int number)
{
    int max = -1;
    while (number > 0)
    {
        if (number % 10 > max)
        {
            max = number % 10;
        }
        number /= 10;
    }
    return max;
}

int scan(int *number)
{
    int check = scanf("%d", number);
    if (check != 1 || *number <= 0)
        return INPUT_ERR;
    return OK;
}

int main()
{
    int number, check, answer;
    check = scan(&number);
    if (check != OK)
        return check;
    answer = find_min(number) + find_max(number);
    printf("%d", answer);
    return OK;
}
