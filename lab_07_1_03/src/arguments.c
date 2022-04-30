#include "constants.h"

int are_arguments_valid(int argc, char **argv)
{
    int check = ERR_ARG;
    if (argc == 3 || (argc == 4 && argv[3][0] == 'f' && argv[3][1] == 0))
        check = OK;
    return check;
}

int are_arguments_for_filter(int argc, char **argv)
{
    return (argc == 4 && argv[3][0] == 'f' && argv[3][1] == 0);
}