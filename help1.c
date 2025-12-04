#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(void){
    int size1, size2;
    scanf("%d", &size1);
    scanf("%d", &size2);
    bool number1[size1], number2[size2];

    for(int i = 0; i < size1; i++) {
        int bit;
        scanf("%d", &bit);
        number1[i] = (bit != 0);
    }

    for(int i = 0; i < size2; i++) {
        int bit;
        scanf("%d", &bit);
        number2[i] = (bit != 0);
    }

    int count1 = 0, count2 = 0;

    while(count1 < size1 && !number1[count1]) {
    count1++;
    }

    while(count2 < size2 && !number2[count2]) {
    count2++;
    }

    if(count1 > 0){

        for( int i = 0; i < size1 - count1; i++){
            number1[i] = number1[i + count1];
        }

        size1 = size1 - count1;
    }
    
    if(count2 > 0){

        for( int i = 0; i < size2 - count2; i++){
            number2[i] = number2[i + count2];
        }

        size2 = size2 - count2;
    }

    if(size1 > size2){
        printf("Первое число больше");
    }
    
    else if (size2 > size1){
        printf("Второе число больше");
    }

    else{

        for(int i = 0; i < size1; i++){

            if( number1[i] && !number2[i]){
                printf("Первое число больше");
                exit(0);
            }

            if( !number1[i] && number2[i]){
                printf("Второе число больше");
                exit(0);
            }
        }

        printf("Числа равны");
    }
    
    return 0;
}




/* Подсказочки:

#include <stdint.h>

int8_t   a;   // ТОЧНО 8 бит, со знаком (-128..127)
uint8_t  b;   // ТОЧНО 8 бит, без знака (0..255)
int16_t  c;   // ТОЧНО 16 бит
uint16_t d;   // ТОЧНО 16 бит, без знака


Сщздание именнованных констант


#define MAX_BITS 32  // Создаем константу MAX_BITS со значением 32



#include <stdlib.h>

bool *arr1 = malloc(size1 * sizeof(bool));
bool *arr2 = malloc(size2 * sizeof(bool));
// ... ввод ...
free(arr1);
free(arr2);



пособы создания и работы с булевыми массивами:


#include <stdbool.h>  // необходимо подключить
#include <stdio.h>

int main() {
    // Создание булевого массива
    bool arr[5] = {true, false, true, false, true};
    
    // Инициализация всех элементов
    bool flags[10] = {false};  // все элементы false
    bool all_true[5] = {true};  // первый true, остальные false
    
    // Доступ к элементам
    arr[2] = false;
    if (arr[0]) {
        printf("Первый элемент истинный\n");
    }
    
    // Вывод массива
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %s\n", i, arr[i] ? "true" : "false");
    }
    
    return 0;
}


#include <stdlib.h> для функции exit()



*/
