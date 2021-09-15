#include <stdio.h>
#define OK 0
#define INPUT_ERR -1
#define LEN_ERR -2
#define MAX_LEN 100
#define MIN_LEN 0

int scan(int array[], int *length)
{
    int check = scanf("%d", length);
    if (check != 1)
        return INPUT_ERR;
    if (*length < MIN_LEN || *length > MAX_LEN)
        return LEN_ERR;
    for (int i = 0; i < *length; i++)
    {
        check = scanf("%d", &array[i]);
        if (check != 1)
            return INPUT_ERR;
    }
    return OK;
}

void delete(int array[], int *length, int index)
{
    for (int i = index; i < *length - 1; i++)
        array[i] = array[i + 1];
    (*length)--;
}

void find_and_delete(int array[], int *length, int number)
{
    int kratnost = 0, i = 0;
    while (i < *length)
    {    
        if (array[i] % number == 0)
            kratnost++;
        if (kratnost % 2 == 0 && array[i] % number == 0)
        {
            delete(array, length, i);
            i--;
        }
        i++;
    }        
}    

void print(const int array[], int length)
{
    if (length != 0)
    {
        for (int i = 0; i < length - 1; i++)
            printf("%d ", array[i]);
        printf("%d\n", array[length - 1]);
    }
}

int main(void)
{
    int array[MAX_LEN] = { 0 };
    int length, check, number;
    check = scan(array, &length);
    if (check != OK)
        return check;
    check = scanf("%d", &number);
    if (check != 1)
        return INPUT_ERR;
    find_and_delete(array, &length, number);
    print(array, length);
    return OK;
}
    