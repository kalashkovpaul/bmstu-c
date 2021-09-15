#include <stdio.h>
#include "sort_goods.h"
#include "find_goods.h"
#include "append_good.h"
#include "constants.h"

int main(int argc, char **argv)
{
    int check = OK;
    if (is_arguments_for_sort(argc, argv))
        check = sort_text(argv[2], argv[3]);
        //return ERR_ARG;
    else if (is_arguments_for_find(argc, argv))
        check = find_goods(argv[2], argv[3]);
        //return ERR_ARG;
    else if (is_arguments_for_append(argc, argv))
        //return ERR_ARG;
        check = append_good(argv[2]);
    else
        return ERR_ARG;
    return check;
}