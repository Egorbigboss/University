#include "libalg.h"
#include <string.h>

void test_get_len_in_base(long long int num, unsigned char base, size_t res)
{
    static unsigned int i = 1;
    printf("test get_len_in_base [%d]: %s\tnum = %lld, base = %d\n", i++,
           get_len_in_base(num, base) == res ? "OK" : "FAIL", num, base);
}

void tests_get_len_in_base(void)
{
    // base 10
    test_get_len_in_base(0, 10, 1);
    test_get_len_in_base(1, 10, 1);
    test_get_len_in_base(9, 10, 1);
    test_get_len_in_base(10, 10, 2);
    test_get_len_in_base(100, 10, 3);

    // base 16
    test_get_len_in_base(0, 16, 1);
    test_get_len_in_base(1, 16, 1);
    test_get_len_in_base(15, 16, 1);
    test_get_len_in_base(16, 16, 2);
    test_get_len_in_base(100, 16, 2);

    // base 2
    test_get_len_in_base(0, 2, 1);
    test_get_len_in_base(1, 2, 1);
    test_get_len_in_base(2, 2, 2);
    test_get_len_in_base(3, 2, 2);
    test_get_len_in_base(5, 2, 3);

    printf("\n");
}

void test_number_to_string(long long num, unsigned char base, char *res)
{
    int error = 0;
    static unsigned int i = 1;
    char *tmp = number_to_string(num, base, &error);
    printf("test number_to_string [%d]: %s\tstring = \"%s\"\n", i++,
           strcmp(tmp, res) == 0 ? "OK" : "FAIL", res);
    free(tmp);
}

void tests_number_to_string(void)
{
    test_number_to_string(1, 10, "1");
    test_number_to_string(9, 10, "9");
    test_number_to_string(10, 10, "10");
    test_number_to_string(-12, 10, "-12");

    test_number_to_string(1, 16, "1");
    test_number_to_string(10, 16, "A");
    test_number_to_string(15, 16, "F");
    test_number_to_string(16, 16, "10");
    test_number_to_string(-10, 16, "-A");
    test_number_to_string(-16, 16, "-10");
    printf("\n");;
}

void test_my_vprintf(char *res, size_t size, const char *format, ...)
{
    char buf[255] = "";

    va_list ap;
    va_start(ap, format);
    my_vprintf(buf, size, format, ap);
    va_end(ap);

    static unsigned int i = 1;
    printf("test my_vprintf [%d]: %s\tbuf = \"%s\"\n", i++,
           strcmp(buf, res) == 0 ? "OK" : "FAIL", buf);
}

void tests_my_vprintf(void)
{
    test_my_vprintf("1", 1, "123");
    test_my_vprintf("12", 2, "123");
    test_my_vprintf("123", 100, "123");

    test_my_vprintf("123 2", 100, "123 %i", 2);
    test_my_vprintf("123 A", 100, "123 %llX", (long long)10);
    test_my_vprintf("123 F", 100, "123 %llX", (long long)15);
    test_my_vprintf("123 Liza", 100, "123 %s", "Liza");
    test_my_vprintf("666 -> 11", 100, "%i %s %llX", 666, "->", (long long int)17);

    printf("\n");
}



void tests_my_snprintf(void)
{
    size_t size = 90;
    char buf1[255] = "";
    char buf2[255] = "";
    int n1 = 0;
    int n2 = 0;
    int i = 0;

    // test1
    {
    char format[255] = "%i";
    n1 = my_snprintf(buf1, size, format, 1);
    n2 = snprintf(buf2, size, format, 1);
    printf("test my_snprintf [%d]: %s\tbuf1 = \"%s\" buf2 = \"%s\"\n", i++,
           strcmp(buf1, buf2) == 0 && n1 == n2 ? "OK" : "FAIL", buf1, buf2);
    }

    // test2
    {
    char format[255] = "%i %i";
    n1 = my_snprintf(buf1, size, format, 1, 2);
    n2 = snprintf(buf2, size, format, 1, 2);
    printf("test my_snprintf [%d]: %s\tbuf1 = \"%s\" buf2 = \"%s\"\n", i++,
           strcmp(buf1, buf2) == 0 && n1 == n2 ? "OK" : "FAIL", buf1, buf2);
    }


    // test3
    {
    char format[255] = "> %s";
    n1 = my_snprintf(buf1, size, format, "test");
    n2 = snprintf(buf2, size, format, "test");
    printf("test my_snprintf [%d]: %s\tbuf1 = \"%s\" buf2 = \"%s\"\n", i++,
           strcmp(buf1, buf2) == 0 && n1 == n2 ? "OK" : "FAIL", buf1, buf2);
    }

    // test4
    {
    char format[255] = "%llX";
    n1 = my_snprintf(buf1, size, format, (long long int)1);
    n2 = snprintf(buf2, size, format, (long long int)1);
    printf("test my_snprintf [%d]: %s\tbuf1 = \"%s\" buf2 = \"%s\"\n", i++,
           strcmp(buf1, buf2) == 0 && n1 == n2 ? "OK" : "FAIL", buf1, buf2);
    }

    // test5
    {
    char format[255] = "%llX";
    n1 = my_snprintf(buf1, size, format, (long long int)15);
    n2 = snprintf(buf2, size, format, (long long int)15);
    printf("test my_snprintf [%d]: %s\tbuf1 = \"%s\" buf2 = \"%s\"\n", i++,
           strcmp(buf1, buf2) == 0 && n1 == n2 ? "OK" : "FAIL", buf1, buf2);
    }

    // test6
    {
    char format[255] = "%llX";
    n1 = my_snprintf(buf1, size, format, (long long int)16);
    n2 = snprintf(buf2, size, format, (long long int)16);
    printf("test my_snprintf [%d]: %s\tbuf1 = \"%s\" buf2 = \"%s\"\n", i++,
           strcmp(buf1, buf2) == 0 && n1 == n2 ? "OK" : "FAIL", buf1, buf2);
    }



    printf("\n");
}

int main(void)
{
    tests_get_len_in_base();
    tests_number_to_string();
    tests_my_vprintf();
    tests_my_snprintf();

    return 0;
}
