#include "numsys.h"
#include "tests/test_num.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc == 2 && strcmp(argv[1], "--test") == 0) {
        if (!run_tests()) {
            printf("The tests failed.\n");
            return 1;
        }
        return 0;
    }

    int8_t num1, num2, sumdec;
    char bin1[9], bin2[9], sumbin[9];

    printf("Enter two numbers between -128 and 127: ");
    scanf("%d %d", &num1, &num2);

    binary_sys(num1, bin1);
    binary_sys(num2, bin2);
    add_binary_num(bin1, bin2, sumbin);
    sumdec = decimal_sys(sumbin);

    printf("These numbers are in binary notation: %s %s\n", bin1, bin2);
    printf("Their sum is in binary form: %s\n", sumbin);
    printf("Their sum in decimal notation: %d", sumdec);

    return 0;
}
