#include "count.h"
#include <stdio.h>
#include <string.h>

int main(void) {
    char S[100], S1[100];
    int lenS, lenS1;

    printf("Введите строку S: ");
    fgets(S, sizeof(S), stdin);

    S[strcspn(S, "\n")] = '\0';
    lenS = strlen(S);

    printf("Введите строку S1: ");
    fgets(S1, sizeof(S1), stdin);

    S1[strcspn(S1, "\n")] = '\0';
    lenS1 = strlen(S1);

    printf("содержится %d вхождений подстроки", countstr(S, S1, lenS, lenS1));

  return 0;
}