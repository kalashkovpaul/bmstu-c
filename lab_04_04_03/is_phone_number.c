#include "is_phone_number.h"
#include "my_string.h"

int my_lfind(char *string, char ch)
{
    int i = 0;
    while (string[i])
    {
        if (string[i] == ch)
            return i;
        i++;
    }
    return -1;
}

int is_digit(char ch)
{
    return (ch >= '0' && ch <= '9');
}

int is_digit_sequence(char *string, int index, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (is_digit(string[index++]) == 0)
            return 0;
    }
    return 1;
}

int is_phone_number(char *string, int length)
{
    my_strip(string, length);
    int lbracket_index = my_lfind(string, '('), index = 0;
    int rbracket_index = my_lfind(string, ')');
    if (rbracket_index == -1)
        return 0;
    if (rbracket_index - lbracket_index != 4)
        return 0;
    if (lbracket_index == -1)
        return 0;
    if (string[index] != '+' && string[index] != '(')
        return 0;
    if (string[index] == '+')
    {
        index++;
        while (string[index] != '(')
        {
            if (is_digit(string[index]) == 0)
                return 0;
            index++;
        }
    }
    index++;
    while (string[index] != ')')
    {
        if (is_digit(string[index]) == 0)
            return 0;
        index++;
    }
    index++;
    if (string[index] != '-')
        return 0;
    index++;
    if (!is_digit_sequence(string, index, 3))
        return 0;
    index += 3;
    if (string[index] != '-')
        return 0;
    index++;
    if (!is_digit_sequence(string, index, 2))
        return 0;
    index += 2;
    if (string[index] != '-')
        return 0;
    index++;
    if (!is_digit_sequence(string, index, 2))
        return 0;
    index += 2;
    if (string[index] != 0)
        return 0;
    return 1;
}