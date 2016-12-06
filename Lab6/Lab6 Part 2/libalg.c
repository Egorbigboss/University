#include "libalg.h"

size_t get_len_in_base(long long num, unsigned char base)
{
    num = num < 0 ? -num : num;
    if (base <= 0)
        return ERROR_BASE_INVALID;
    size_t len = 1;
    for (size_t i = base; i <= num; i *= base)
        ++len;
    return len;
}

char *number_to_string(long long num, unsigned char base, int *error)
{
    if (base > 36)
    {
        *error = ERROR_BASE;
        return NULL;
    }
    // get len of number
    size_t len = get_len_in_base(num, base);
    if (!len)
    {
        *error = ERROR_BASE;
        return NULL;
    }

    len = num < 0 ? len + 1 : len;
    char *tmp = malloc(sizeof(char) * (len + 1));
    if (!tmp)
    {
        *error = ERROR_ALLOC;
        return NULL;
    }
    if (num < 0)
    {
        tmp[0] = '-';
        num = -num;
    }
    tmp[len--] = '\0';

    while (num != 0)
    {
        unsigned int digit = num % base;
        if (digit < 10)
            tmp[len--] = '0' + digit;
        else
            tmp[len--] = 'A' + digit - 10;
        num /= base;
    }
    return tmp;
}

// %s %llX $d
int my_vprintf(char *buf, size_t size, const char *format,va_list ap)
{
    size_t str_form = strlen(format);
    size_t pos = 0;

    for (register size_t i = 0; i < str_form && pos < size; ++i)
    {
        if (format[i] == '%')
        {
            if (format[i + 1] == 's')
            {
                // s - string
                char *tmp = va_arg(ap, char *);
                //strncat(buf, tmp, size - pos);
                strncpy(buf + pos, tmp, size - pos);
                pos += strlen(tmp);
                i += 1;
            }
            else if (format[i + 1] == 'i')
            {
                // i - integer
                int x = va_arg(ap, int);
                int error;
                char *from = number_to_string(x, 10, &error);
                strncpy(buf + pos, from, size - pos);
                pos += strlen(from);
                free(from);
                i += 1;
            }
            else if (format[i + 1] == 'l' && format[i + 2] == 'l' && format[i + 3] == 'X')
            {
                // llX
                long long int x = va_arg(ap, long long int);
                int error;
                char *from = number_to_string(x, 16, &error);
                strncpy(buf + pos, from, size - pos);
                pos += strlen(from);
                free(from);
                i += 3;
            }
            else
            {
                // other
                buf[pos++] = '%';
            }
        }
        else
        {
            buf[pos++] = format[i];
        }
    }
    buf[pos] = '\0';
    return pos;
}

int my_snprintf(char *buf, size_t size, const char *format, ...)
{
    va_list ap;
    va_start(ap, format);
    int tmp = my_vprintf(buf, size, format, ap);
    va_end(ap);
    return tmp;
}
