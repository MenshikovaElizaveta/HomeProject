#include "count.h"

int countstr(const char* S, const char* S1, int lenS, int lenS1) {
    int count = 0;
    const char* tempS = S;
    const char* tempS1 = S1;

    if (lenS1 ==0 || lenS < lenS1){
        return 0;
    }

    while ((tempS = strstr(tempS, tempS1)) != NULL){
        count++;
        tempS++;
    }

    return count;
}