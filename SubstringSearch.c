#include <stdio.h>
#include <string.h>
#include <stdbool.h>


int countstr(char S[], char S1[]) {
    int k = 0;
    int lenS = strlen(S);
    int lenS1 = strlen(S1);

    if (lenS1 ==0 || lenS < lenS1){
        return 0;
    }

    for(int i = 0; i < lenS - lenS1 + 1; i++){
        bool contin = true;
        for( int j = 0; j < lenS1; j++){
            if (S[i + j] != S1[j]){
                contin = false;
                break;
            }
        }
        if (contin){
            k++;
        }
    }

    return k;
}

int main(void) {
    char S[100], S1[100];
    
    printf("Введите строку S: ");
    fgets(S, sizeof(S), stdin);
    S[strcspn(S, "\n")] = '\0';
    printf("Введите строку S1: ");
    fgets(S1, sizeof(S1), stdin);
    S1[strcspn(S1, "\n")] = '\0';
    printf("содержится %d вхождений подстроки", countstr(S, S1));

  return 0;
}
