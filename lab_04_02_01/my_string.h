#include "constants.h"

int my_strncmp(char *string1, char *string2, int length);
void my_strncpy(char *string1, char *string2, int length_of_string2);
void swap_strings(char *string1, char *string2);
int smaller(char *string1, char *string2);
void sort_strings(char words[MAX_WORD_NUM][MAX_WORD_LEN + 1], int number_of_words);
int my_split(char words[MAX_WORD_NUM][MAX_WORD_LEN + 1], char *string, int length, int *number_of_words);
int split(char words[MAX_WORD_NUM][MAX_WORD_LEN + 1], char *string, int length, int *number_of_words);