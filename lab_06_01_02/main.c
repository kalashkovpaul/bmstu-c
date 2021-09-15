#include <stdio.h>
#include "constants.h"
#include "item_lib.h"
#include "item.h"
//#include "unit_tests.h"

int main(int argc, char **argv)
{
    //activate_unit_tests();
    int check = ERR_IO, mask[STRUCT_AMOUNT] = { 0 };
    item items[STRUCT_AMOUNT];
    int items_amount = 0;
    if (arguments_valid(argc))
        check = read_items(argv[1], items, &items_amount);
    if (check == OK)
    {
        if (arguments_for_sort(argc))
        {
            check = sort_items(items, items_amount);
            if (check == OK)
                check = print_all(items, items_amount);
        }
        else if (arguments_for_print(argv[2]))
            check = print_all(items, items_amount);
        else
        {
            check = find_items(items, items_amount, mask, argv[2]);
            if (check == OK)
                check = print_results(items, items_amount, mask);
        }
    }
    return check;
}