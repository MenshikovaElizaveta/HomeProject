#include <stdio.h>

int main() {
    int quantity = 0;
    int counter[28] = {0};
    
    for (int a = 0; a < 10; ++a) {
        for (int b = 0; b < 10; ++b) {
            for (int c = 0; c < 10; ++c) {
                ++counter[a + b + c];
            }
        }
    }

    for( int i = 0; i < 28; i++){
        quantity = quantity + counter[i] * counter[i];
    }
    
    printf("%d\n", quantity);
    return 0;
}
