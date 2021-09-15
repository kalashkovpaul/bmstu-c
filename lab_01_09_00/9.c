// ���. ������ 1, ������ 8
// �����: �������� ����� ��7-16�, ������� 8, ������� ������ 0

#include <stdio.h>
#include <math.h>

float gx()
{
    int ix, n = 1;
    float x = 0, sum = 0;
    ix = scanf("%f", &x);
    if (ix != 1)
    {
        return -1;
    }
    while (x >= 0)
    {
        sum += x / n;
        ix = scanf("%f", &x);
        if (ix != 1)
        {
            return -1;
        }
        n++;
    }
    return sqrt(sum);
}

int main(void)
{
    float result = gx();
    if (result < 0)
    {
        return -1;
    }
    else
    {
        printf("%f", result);
        return 0;
    }
}