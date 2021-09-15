#include "my_string.h"

int my_strncmp(char *string1, char *string2, int length)
{
    int result = 1;
    for (int i = 0; i < length; i++)
        if (*(string1++) != *(string2++))
            result = 0;
    return result;
}

void my_strncpy(char *string1, char *string2, int length_of_string2)
{
    for (int i = 0; i <= length_of_string2; i++)
        *(string1++) = *(string2++);
}

void swap_strings(char *string1, char *string2)
{
    char tmp;
    do
    {
        tmp = *string1;
        *string1 = *string2;
        *string2 = tmp;
        string1++;
        string2++;
    }
    while (*string1 != 0 || *string2 != 0);
}

int smaller(char *string1, char *string2)
{
    int i = 0;
    while (string1[i] != 0 && string2[i] != 0 && string1[i] == string2[i])
        i++;
    if ((string2[i] == 0 && string1[i] == 0) || string2[i] > string1[i])
        return 1;
    return 0;
}

void sort_strings(char words[MAX_WORD_NUM][MAX_WORD_LEN + 1], int number_of_words)
{
    int min_position;
    for (int i = 0; i < number_of_words; i++)
    {
        min_position = i;
        for (int j = i + 1; j < number_of_words; j++)
            if (smaller(words[j], words[min_position]))
                min_position = j;
        swap_strings(words[min_position], words[i]);
    }
}

int end_of_the_word(char ch)
{
    char splitters[NUM_OF_SPLITTERS] = { ' ', ',', ';', ':', '-', '.', '!', '?', '\n' };
    for (int i = 0; i < NUM_OF_SPLITTERS; i++)
        if (ch == splitters[i])
            return 1;
    return 0;
}

void add_if_single(char words[MAX_WORD_NUM][MAX_WORD_LEN + 1], char *word, int length_of[], int *index, int length)
{
    int i = *index, single = 1;
    for (int compareble = 0; compareble < i; compareble++)
        if (length_of[compareble] == length &&
            my_strncmp(words[compareble], word, length_of[compareble]))
            single = 0;
    if (single)
    {
        word[length] = '\0';
        my_strncpy(words[i], word, length);
        length_of[i] = length;
        (*index)++;
    }
}

int my_split(char words[MAX_WORD_NUM][MAX_WORD_LEN + 1], char *string, int length, int *number_of_words)
{
    int length_of[MAX_WORD_NUM] = { 0 }, index_of_word = 0, length_of_word = 0;
    char word[MAX_WORD_LEN + 1] = { 0 };
    while (*string)
    {
        if (end_of_the_word(*string))
        {
            if (length_of_word != 0)
            {
                add_if_single(words, word, length_of, &index_of_word, length_of_word);
                length_of_word = 0;
            }
        }
        else
        {
            word[length_of_word] = *string;
            length_of_word++;
        }
        if (length_of_word > MAX_WORD_LEN)
            return WORD_LEN_ERR;
        string++;
    }
    if (index_of_word == 0)
    {
        *number_of_words = 0;
        return WORD_LEN_ERR;
    }
    if (length_of_word != 0)
        add_if_single(words, word, length_of, &index_of_word, length_of_word);
    *number_of_words = index_of_word;
    return OK;
}