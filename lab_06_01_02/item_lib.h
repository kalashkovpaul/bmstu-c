#ifndef _ITEM_LIB_H_

#define _ITEM_LIG_H_

#include <stdio.h>
#include "item.h"

int arguments_valid(int argc);
int arguments_for_sort(int argc);
int arguments_for_print(char *prefix);
int read_items(char *name, item *items, int *length);
int sort_items(item *items, int length);
int print_all(item *items, int length);
int find_items(item *items, int length, int *mask, char *prefix);
int print_results(item *items, int length, int *mask);
int file_read_line(FILE *file, char *str, int max_length);
int check_for_error(FILE *file);
int check_for_ending_chars(FILE *file);

#endif