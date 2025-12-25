#include "test_num.h"
#include "numsys.h"
#include <stdbool.h>

bool test_simple()
{
    int8_t num1 = 5;
    int8_t num2 = 3;
    int8_t sumdec;
    char bin1[9], bin2[9], sumbin[9];

    binary_sys(num1, bin1);
    binary_sys(num2, bin2);

    bool res1 = (strcmp(bin1, "00000101") == 0) && (strcmp(bin2, "00000011") == 0);

    add_binary_num(bin1, bin2, sumbin);

    bool res2 = (strcmp(sumbin, "00001000") == 0);

    sumdec = decimal_sys(sumbin);

    bool res3 = (sumdec == 8);

    return res1 && res2 && res3;
}

bool test_negative_positive()
{
    int8_t num1 = 10;
    int8_t num2 = -7;
    int8_t sumdec;
    char bin1[9], bin2[9], sumbin[9];

    binary_sys(num1, bin1);
    binary_sys(num2, bin2);

    bool res1 = (strcmp(bin1, "00001010") == 0) && (strcmp(bin2, "11111001") == 0);

    add_binary_num(bin1, bin2, sumbin);

    bool res2 = (strcmp(sumbin, "00000011") == 0);

    sumdec = decimal_sys(sumbin);

    bool res3 = (sumdec == 3);

    return res1 && res2 && res3;
}

bool test_reverse()
{
    int8_t num1 = 1;
    int8_t num2 = -1;
    int8_t sumdec;
    char bin1[9], bin2[9], sumbin[9];

    binary_sys(num1, bin1);
    binary_sys(num2, bin2);

    bool res1 = (strcmp(bin1, "00000001") == 0) && (strcmp(bin2, "11111111") == 0);

    add_binary_num(bin1, bin2, sumbin);

    bool res2 = (strcmp(sumbin, "00000000") == 0);

    sumdec = decimal_sys(sumbin);

    bool res3 = (sumdec == 0);

    return res1 && res2 && res3;
}

bool test_zero()
{
    int8_t num1 = 0;
    int8_t num2 = 0;
    int8_t sumdec;
    char bin1[9], bin2[9], sumbin[9];

    binary_sys(num1, bin1);
    binary_sys(num2, bin2);

    bool res1 = (strcmp(bin1, "00000000") == 0) && (strcmp(bin2, "00000000") == 0);

    add_binary_num(bin1, bin2, sumbin);

    bool res2 = (strcmp(sumbin, "00000000") == 0);

    sumdec = decimal_sys(sumbin);

    bool res3 = (sumdec == 0);

    return res1 && res2 && res3;
}

bool run_tests() { return test_simple() && test_negative_positive() && test_reverse() && test_zero(); }
