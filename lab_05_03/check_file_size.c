#include <stdio.h>
#define ERR_FILE -2

int check_file_size(FILE *file)
{
    long sz;
    if (fseek(file, 0L, SEEK_END))
        return ERR_FILE;
    sz = ftell(file);
    if (sz <= 0 || sz % sizeof(int) != 0)
        return ERR_FILE;
    return fseek(file, 0L, SEEK_SET);
}