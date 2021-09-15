/*
    Формат создания нового файла ./a.exe c <number> <filename>
    Целочисленный тип: int
    Алгоритм сортировки: вставками
    Направление сортировки: возрастание
*/
#include <stdio.h>
#include <stdlib.h>
#include "c_file_binary.h"
#include "p_file_binary.h"
#include "s_file_binary.h"
#define OK 0
#define ERR_NO_ARG -3

int main(int argc, char **argv)
{
    int check;
    if (c_is_arguments(argc, argv))
        check = c_file_binary(argv[3], argv[2]);
    else if (p_is_arguments(argc, argv))
        check = p_file_binary(argv[2]);
    else if (s_is_arguments(argc, argv))
        check = s_file_binary(argv[2]);
    else
        check = ERR_NO_ARG;
    if (check != OK)
        return check;
    return check;
}