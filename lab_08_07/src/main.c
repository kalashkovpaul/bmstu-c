#include <stdio.h>
#include "constants.h"
#include "matrix.h"
#include "matrix_io.h"
#include "matrix_operations.h"

int main(void)
{
    matrix_t a = { NULL, 0, 0 }, b = { NULL, 0, 0 }, c = { NULL, 0, 0 };
    int check = OK;
    check = read_matrixes(&a, &b);
    if (check == OK)
    {
        check = cut_matrixes(&a, &b);
        if (check == OK)
        {
            check = even_matrixes(&a, &b);
            if (check == OK)
            {
                check = multiply_matrixes(a, b, &c);
                if (check == OK)
                    print_result(c);
            }
        }
    }
    free_all_matrixes(&a, &b, &c);
    return check;
}