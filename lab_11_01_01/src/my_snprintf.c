#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define MAX_LENGTH 20 // INT_MIN = -2147483648

#define OK 0
#define ERR_WRONG_ARGUMENTS -1
#define ERR_MEMORY -2
#define NULL_ARGUMENTS 1


int my_itoa(long long int number, char *str, int base);

int my_strlen(char *str);

void reverse_str(char *str);

void swap_char(char *left, char *right);

int my_itohex(unsigned int number, char **str);

void my_strncpy(char *dst, char *src, int n);

int my_snprintf(char *restrict s, size_t n, const char *restrict format, ...)
{
    int result = 0;
    if (format == NULL)
        result = ERR_WRONG_ARGUMENTS;
    size_t result_index = 0;
    size_t format_index = 0;
    size_t i = 0;
    size_t str_len = 0;
    long long int number = 0;
    unsigned long long int hex = 0;
    char str[MAX_LENGTH] = { 0 };
    char *tmp_str = NULL;
    char ch = 0;
    va_list values;
    va_start(values, format);
    while (result == OK && format[format_index] != 0)
    {
        if (format[format_index] == '%')
        {
            format_index++;
            switch (format[format_index])
            {
                case 'c':
                    ch = va_arg(values, int);
                    format_index++;
                    if (n > 0 && result_index < n - 1 && s != NULL)
                        s[result_index] = ch;
                    result_index++;
                    break;
                case 'd':
                    number = va_arg(values, int);
                    format_index++;
                    result = my_itoa(number, str, 10);
                    i = 0;
                    str_len = my_strlen(str);
                    if (result == OK)
                    {
                        if (n > 0 && s != NULL)
                            my_strncpy(s + result_index, str, n - result_index);
                        result_index += str_len;
                    }
                    break;
                case 's':
                    tmp_str = va_arg(values, char *);
                    format_index++;
                    i = 0;
                    str_len = my_strlen(tmp_str);
                    while (result == OK && i < str_len)
                    {
                        if (n > 0 && result_index < n - 1 && s != NULL)
                            s[result_index] = tmp_str[i];
                        i++;
                        result_index++;
                    }
                    break;
                case 'x':
                    hex = va_arg(values, unsigned int);
                    format_index++;
                    result = my_itoa(hex, str, 16);
                    i = 0;
                    str_len = my_strlen(str);
                    if (result == OK)
                    {
                        if (n > 0 && s != NULL)
                            my_strncpy(s + result_index, str, n - result_index);
                        result_index += str_len;
                    }
                    break;
                default:
                    result = ERR_WRONG_ARGUMENTS;
                    break;
            }
        }
        else
        {
            if (s != NULL && (s != NULL || n != 0) && n > 0 && result_index < n - 1)
                s[result_index] = format[format_index];
            result_index++;
            format_index++;
        }
    }
    va_end(values);
    if (result == OK && format[0] == 0 && n == 0)
        result_index = 0;
    else if (s != NULL && n != 0)
        s[n > 0 && result_index > n - 1 ? n - 1 : result_index] = 0;
    return result != OK ? result : (int) result_index;
}

int my_itoa(long long int number, char *str, int base)
{
    int result = OK;
    if (str)
    {
        char cur = 0;
        int i = 0, rem = 0;
        int is_negative = number < 0;
        if (is_negative)
            number *= -1;
        do
        {
            rem = number % base;
            cur = rem > 9 ? rem - 10 + 'a' : rem + '0';
            number /= base;
            str[i++] = cur;
        }
        while (number > 0);
        if (is_negative)
            str[i++] = '-';
        str[i++] = 0;
        reverse_str(str);
    }
    else
        result = ERR_WRONG_ARGUMENTS;
    return result;
}


int my_strlen(char *str)
{
    int length = 0;
    char *cur = str;
    while (*cur != 0)
    {
        cur++;
        length++;
    }
    return length;
}

void reverse_str(char *str)
{
    int length = my_strlen(str);
    char *start = str;
    char *end = str + length - 1;
    while (start < end)
    {
        swap_char(start, end);
        start++;
        end--;
    }
}

void swap_char(char *left, char *right)
{
    char tmp = *left;
    *left = *right;
    *right = tmp;
}

void my_strncpy(char *dst, char *src, int n)
{
    int i = 0;
    int str_len = my_strlen(src);
    while (i < str_len && i < n - 1)
    {
        dst[i] = src[i];
        i++;
    }
}
