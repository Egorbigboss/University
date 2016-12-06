#ifndef LIBALG_H_INCLUDED
#define LIBALG_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#define ERROR_BASE_INVALID 0
#define ERROR_ALLOC 1
#define ERROR_BASE 2

/*
    Get len of number in base
    in: num - number
        base - base of number
    out: len of number in base
*/
size_t get_len_in_base(long long num, unsigned char base);


/*
    Create string number from number
    in: num - number
        base - base of number
    out: string with number
*/
char *number_to_string(long long num, unsigned char base, int *error);


/*
    Print format string to buffer
    in: buf - buffer
        size - size of buffer
        format - string format
        ap - list of arguments for formating string
    out: number of writing
*/
int my_vprintf(char *buf, size_t size, const char *format, va_list ap);


/*
    Print format string to buffer
    in: buf - buffer
        size - size of buffer
        format - string format
        ... - arguments for formating string
    out: number of writing
*/
int my_snprintf(char *buf, size_t size, const char *format, ...);


#endif // LIBALG_H_INCLUDED
