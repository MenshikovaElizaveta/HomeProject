#include "numsys.h"

void binary_sys(int8_t dec, char* bin)
{
    unsigned int bit = 0b10000000;
    for (int i = 0; i < 8; i++) {
        bin[i] = (dec & bit) ? '1' : '0';
        bit >>= 1;
    }
    bin[8] = '\0';
}

void add_binary_num(char* bin1, char* bin2, char* result_bin)
{
    int car = 0;
    for (int i = 7; i >= 0; i--) {
        int bit1 = bin1[i] - '0';
        int bit2 = bin2[i] - '0';
        int sum = bit1 + bit2 + car;
        result_bin[i] = (sum % 2) + '0';
        car = sum / 2;
    }
    result_bin[8] = '\0';
}

int8_t decimal_sys(char* bin)
{
    int8_t dec = 0;
    for (int i = 0; i < 8; i++) {
        dec = (dec << 1) | (bin[i] - '0');
    }

    if (bin[0] == '1') {
        dec = dec - 256;
    }

    return dec;
}
