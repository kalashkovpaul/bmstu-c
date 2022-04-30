#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int check = 0;
    int length = 0;
    scanf("%d", &length);
    FILE *f;
    if (argc == 2 && (f = fopen(argv[1], "w")) != NULL)
    {
        for (int i = 0; i < length; i++)
            fprintf(f, "%d ", rand() % 10000 - 5000);
    }
    else
        check = -1;
    return check;
}