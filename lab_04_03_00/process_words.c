#include "constants.h"
#include "process_words.h"
#include <string.h>

int process_words(char words[MAX_WORD_NUM][MAX_WORD_LEN + 1], int number_of_words, char result[])
{
    char first_word[MAX_WORD_LEN + 1];
    strcpy(first_word, words[number_of_words - 1]);
    for (int i = number_of_words - 2; i >= 0; i--)
    {
        if (strcmp(first_word, words[i]) != 0)
        {
            strcat(result, " ");
            del_char_like_first(words[i]);
            strcat(result, words[i]);
        }
    }
    if (strcmp(result, "Result:") == 0)
        return EMPTY_STR_ERR;
    return OK;
}

int split(char words[MAX_WORD_NUM][MAX_WORD_LEN + 1], char *string, int length, int *number_of_words)
{
    int i = 0, len = 0;
    char splitters[NUM_OF_SPLITTERS] = { ' ', ',', ';', ':', '-', '.', '!', '?', '\n' };
    char *wptr = strtok(string, splitters);
    while (wptr != NULL)
    {
        len = strlen(wptr);
        if (len > MAX_WORD_LEN)
            return WORD_LEN_ERR;
        strncpy(words[i], wptr, len);
        i++;
        wptr = strtok(NULL, splitters);
    }
    *number_of_words = i;
    return OK;
}

void shift(char *string)
{
    while (*string)
    {
        *string = *(string + 1);
        string++;
    }
}

void del_char_like_first(char *string)
{
    char ch = *(string++);
    while (*string)
    {
        if (*string == ch)
        {
            shift(string);
        }
        else
            string++;
    }
}