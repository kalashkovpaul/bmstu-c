#include <stdio.h>
#include <inttypes.h>
#include <sys/time.h>
#define N 10000
#define N_ten 50
#define N_hundreds 500
#define N_thousands 10000
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
    while (negative >= 0 && a < end);
    return answer;
}

int process_1(int a[], int len)
{
    int answer = 0, iteration = 1, index = 0;
    int negative = a[index];
    do 
    {
        iteration *= a[index];
        if (a[index] < 0)
            negative = a[index];
        answer += iteration;
        index += 1;
    }
    while (negative >= 0 && index < len);
    return answer;
}

int process_2(int *a, int len)
{
    int answer = 0, iteration = 1, index = 0;
    int negative = *(a + index);
    do 
    {
        iteration *= *(a + index);
        if (*(a + index) < 0)
            negative = *(a + index);
        answer += iteration;
        index += 1;
    }
    while (negative >= 0 && index < len);
    return answer;
}

void print(int64_t *oper, int64_t *pro_1, int64_t *pro_2, int length, int iterations)
{
    printf("For lenght %d and %d iterations:\n", length, iterations);
    printf("Time for operation: %" PRId64 " microseconds \n", *oper);
    printf("Time for process_1: %" PRId64 " microseconds \n", *pro_1);
    printf("Time for process_2: %" PRId64 " microseconds \n", *pro_2);
}

void timer(int *a, int64_t *oper, int64_t *pro_1, int64_t *pro_2, int length, int iterations)
{
    struct timeval tv_start, tv_stop;
    int *end = a + length;
    gettimeofday(&tv_start, NULL);
    for (int i = 0; i < iterations; i++)
        operation(a, end);
    gettimeofday(&tv_stop, NULL);
    *oper = (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL + (tv_stop.tv_usec - tv_start.tv_usec);
    gettimeofday(&tv_start, NULL);
    for (int i = 0; i < iterations; i++)
        process_1(a, length);
    gettimeofday(&tv_stop, NULL);
    *pro_1 = (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL + (tv_stop.tv_usec - tv_start.tv_usec);
    gettimeofday(&tv_start, NULL);
    for (int i = 0; i < iterations; i++)
        process_2(a, length);
    gettimeofday(&tv_stop, NULL);
    *pro_2 = (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL + (tv_stop.tv_usec - tv_start.tv_usec);
    print(oper, pro_1, pro_2, length, iterations);
}

int main(void)
{
    int a[N], i, j;
    int iterations[] = {10, 50, 100, 500, 1000, 5000};
    int lengths[] = {50, 500, 1000, 5000, 10000, 20000};
    int64_t oper, pro_1, pro_2;
    for (i = 0; i < N; i++)
        a[i] = i;
    for (i = 0; i < 6; i++)
        for (j = 0; j < 6; j++)
            timer(a, &oper, &pro_1, &pro_2, lengths[i], iterations[j]);
    return OK;
}