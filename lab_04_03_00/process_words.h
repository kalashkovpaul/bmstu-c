#include "constants.h"
int process_words(char words[MAX_WORD_NUM][MAX_WORD_LEN + 1], int number_of_words, char result[]);
int split(char words[128][17], char *string, int length, int *number_of_words);
void del_char_like_first(char *string);