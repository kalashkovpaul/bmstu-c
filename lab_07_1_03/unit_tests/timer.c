#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "functions.h"
#include "constants.h"


void measure_time(int *arr, int *end_arr, \
void (*mysort)(void *, size_t, size_t, int (*compar)(const void*, const void*)))
{
    int64_t time;
    struct timeval tv_start, tv_stop;
    gettimeofday(&tv_start, NULL);
    mysort(arr, end_arr - arr, sizeof(int), compare);
    gettimeofday(&tv_stop, NULL);
    time = (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL + (tv_stop.tv_usec - tv_start.tv_usec);
    printf("time = %ld mcs\n", time);
}

int main(int argc, char **argv)
{
    int *arr_1 = NULL, *end_arr_1 = NULL;
    int *arr_2 = NULL, *end_arr_2 = NULL;
    int check = (argc != 2 || read_array(argv[1], &arr_1, &end_arr_1) || read_array(argv[1], &arr_2, &end_arr_2));
    if (check == OK)
    {
        printf("mysort: ");
        measure_time(arr_1, end_arr_1, mysort);
        printf("qsort: ");
        measure_time(arr_2, end_arr_2, qsort); 
    }
    else
        check = ERR_ARG;
    free_array(arr_1, end_arr_1);
    free_array(arr_2, end_arr_2);
    return check;
}


