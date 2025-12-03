#include <stdio.h>

int main() {
    int a, b, c, i;
    int quantity = 1;
    int counter[27] = {0};
    
    for (i = 0; i < 27; ++i) {
        for (a = 0; a < 10; ++a) {
            for (b = 0; b < 10; ++b) {
                for (c = 0; c < 10; ++c) {
                    if ((a + b + c) == i) {
                        ++counter[i];
                    }
                }
            }
        }
        quantity = quantity + counter[i] * counter[i];
    }
    
    printf("%d\n", quantity);
    return 0;
}
