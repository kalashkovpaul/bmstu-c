#include <stdio.h>
#include <string.h>
#include "constants.h"
#include "io.h" 
#include "my_string.h"

int main(void)
{
    char string[MAX_STR_LEN + 1];
    char words[MAX_WORD_NUM][MAX_WORD_LEN + 1] = { { 0 } };
    int length, check, number_of_words = 0;
    check = read_line(string, MAX_STR_LEN + 1, &length);
    if (check != OK)
        return check;
    check = my_split(words, string, length, &number_of_words);
    if (check != OK)
        return check;
    sort_strings(words, number_of_words);
    print(words, number_of_words);
    return OK;
}