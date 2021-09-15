#include <stdio.h>
#include <string.h>
#include "item_lib.h"
#include "constants.h"
#include "item.h"

int arguments_valid(int argc)
{
    return (argc == 2 || argc == 3);
}

int arguments_for_sort(int argc)
{
    return (argc == 2);
}

char *strupr(char *str)
{
    int i = 0;
    while (str[i] != 0)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 'a' - 'A';
        i++;
    }        
    return str;
}

int arguments_for_print(char *prefix)
{
    char dummy[MAX_LENGTH] = { 0 };
    strcpy(dummy, prefix);
    return (strcmp(strupr(dummy), "ALL") == 0);
}

int file_read_line(FILE *file, char *str, int max_length)
{
    int check = OK;
    char ch = 0;
    int i = 0;
    fscanf(file, "%c", &ch);
    while (check == OK && ch != '\n' && ch != '\r' && ch != EOF && !feof(file))
        if (i < max_length - 1)
        {
            str[i++] = ch;
            fscanf(file, "%c", &ch);
        }
        else
            check = ERR_LENGTH;
    if (ch == '\r')
        fscanf(file, "%c", &ch);
    str[i] = '\0';
    if (i <= 0)
        check = ERR_LENGTH;
    return check;
}

int check_for_error(FILE *file)
{
    int check = OK;
    if (feof(file))
        check = END_STRUCT;
    else
        check = ERR_READ;
    return check;
}

int check_for_ending_chars(FILE *file)
{
    int check;
    char ch;
    check = fscanf(file, "%c", &ch);
    if (check == 1 && ch == '\r')
        check = fscanf(file, "%c", &ch);
    return OK;
}

int take_item_from_txt(FILE *f_src, item *current_item)
{
    int check;
    check = file_read_line(f_src, current_item->name, NAME_LENGTH + 1);
    if (check != OK)
        check = check_for_error(f_src);
    else
    {
        check = fscanf(f_src, "%lf", &current_item->mass);
        if (check == 1 && current_item->mass > 0)
            check = check_for_ending_chars(f_src);
        else
            check = ERR_READ;
        if (check == OK)
        {
            check = fscanf(f_src, "%lf", &current_item->volume);
            if (check == 1 && current_item->volume > 0)
                check = check_for_ending_chars(f_src);
            else
                check = ERR_READ;
        }
    }
    return check;
}

void print_item(item current_item)
{
    printf("%s\n", current_item.name);
    printf("%f\n", current_item.mass);
    printf("%f\n", current_item.volume);
}

int scan_items(FILE *file_name, item items[], int *length)
{
    int i = 0, check = OK;
    while (check == OK)
    {
        check = take_item_from_txt(file_name, (items + i));
        if (check == OK)
            i++;
        if (i > STRUCT_AMOUNT)
            check = ERR_LENGTH;
    }
    if (check == OK || check == END_STRUCT)
    {
        *length = i;
        if (*length == 0)
            check = ERR_LENGTH;
        else
            check = OK;
    }
    return check;
}

int read_items(char *name, item *items, int *length)
{
    int check = OK;
    FILE *f_src = fopen(name, "r");
    if (f_src == NULL)
        check = ERR_FILE;
    if (check == OK)
    {
        check = scan_items(f_src, items, length);
        fclose(f_src);
    }
    return check;
}

int compare(item first, item second)
{
    return ((first.mass / first.volume - second.mass / second.volume) > 0);
}

int sort_items(item *items, int length)
{
    int i, j;
    item t = { 0 };
    for (i = 1; i < length; i++)
    {
        for (j = i; j > 0 && compare(items[j - 1], items[j]); j--)
        {
            t = items[j - 1];
            items[j - 1] = items[j];
            items[j] = t;
        }
    }
    return OK;
}

int print_all(item *items, int length)
{
    for (int i = 0; i < length; i++)
        print_item(items[i]);
    return OK;
}

int if_begins_with(char *string, char *prefix)
{
    int i = 0, check;
    while (string[i] != 0 && prefix[i] != 0 && string[i] == prefix[i])
        i++;
    if (prefix[i] == 0)
        check = 1;
    else
        check = 0;
    return check;
}

int find_items(item *items, int length, int *mask, char *prefix)
{
    for (int i = 0; i < length; i++)
        mask[i] = if_begins_with(items[i].name, prefix);
    return OK;
}

int print_results(item *items, int length, int *mask)
{
    for (int i = 0; i < length; i++)
        if (mask[i])
            print_item(items[i]);
    return OK;
}