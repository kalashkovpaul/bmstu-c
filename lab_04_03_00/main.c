#include "process_words.h"
#include "io.h"
#include "constants.h"

int main(void)
{
    char string[MAX_STR_LEN + 1];
    char result[MAX_STR_LEN + 1] = "Result:";
    char words[MAX_WORD_NUM][MAX_WORD_LEN + 1] = { { 0 } };
    int length, check, number_of_words = 0;
    check = read_line(string, MAX_STR_LEN + 1, &length);
    if (check != OK)
        return check;
    check = split(words, string, length, &number_of_words);
    if (check != OK)
        return check;
    check = process_words(words, number_of_words, result);
    if (check != OK)
        return check;
    print(result);
    return OK;
}