#include <stdio.h>
#include "good.h"

int f_print_good(FILE *f_dst, the_good good);
int compare(the_good good_1, the_good good_2);
int take_good_from_txt(FILE *f_src, the_good *good);
int read_array(FILE *file, the_good array[], int *length);