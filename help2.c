#include <stdio.h>
#include <stdbool.h>

int compare_bool_arrays_bitwise(const bool* arr1, const bool* arr2, int size1, int size2) {
    int i = 0, j = 0;

    while (i < size1 && !arr1[i]) i++;
    while (j < size2 && !arr2[j]) j++;

    if (i == size1 && j == size2) return 0; // оба нули
    if (i == size1) return -1; // первое число ноль, второе нет
    if (j == size2) return 1;  // второе число ноль, первое нет

    // Определяем фактическую длину чисел (без ведущих нулей)
    int len1 = size1 - i;
    int len2 = size2 - j;

    if (len1 > len2) return 1;
    if (len1 < len2) return -1;


    for (int k = 0; k < len1; k++) {
        bool bit1 = arr1[i + k];
        bool bit2 = arr2[j + k];
        
        if (bit1 && !bit2) return 1;
        if (!bit1 && bit2) return -1;
    }
    
    return 0; // числа равны
}


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool* simple_add(const bool* a, int size_a,
                 const bool* b, int size_b,
                 int* result_size) {
    
    // 1. Размер результата = максимальный размер + 1
    int max = (size_a > size_b) ? size_a : size_b;
    *result_size = max + 1;
    
    // 2. Выделяем память для результата
    bool* res = (bool*)malloc(*result_size * sizeof(bool));
    
    // 3. Заполняем нулями
    for (int i = 0; i < *result_size; i++) {
        res[i] = false;
    }
    
    // 4. Индексы для обхода с конца
    int i = size_a - 1;  // конец первого числа
    int j = size_b - 1;  // конец второго числа  
    int k = *result_size - 1;  // конец результата
    bool carry = false;  // перенос
    
    // 5. Складываем пока есть что складывать
    while (i >= 0 || j >= 0 || carry) {
        // Берём текущие биты
        bool bit1 = (i >= 0) ? a[i] : false;
        bool bit2 = (j >= 0) ? b[j] : false;
        
        // Считаем сумму
        int sum = 0;
        if (bit1) sum++;
        if (bit2) sum++;
        if (carry) sum++;
        
        // Пишем результат
        res[k] = (sum % 2 == 1);
        
        // Считаем перенос
        carry = (sum >= 2);
        
        // Двигаемся дальше
        i--; j--; k--;
    }
    
    return res;
}

// Пример использования
int main() {
    // Тестовые данные
    bool num1[] = {false, true, false, true};  // 0101 = 5
    bool num2[] = {false, false, true, true};  // 0011 = 3
    
    int result_size;
    bool* result = simple_add(num1, 4, num2, 4, &result_size);
    
    // Выводим результат
    printf("Результат: ");
    for (int i = 0; i < result_size; i++) {
        printf("%d", result[i] ? 1 : 0);
    }
    printf("\n");
    
    // Освобождаем память
    free(result);
    
    return 0;
}




/* 

#include <stdlib.h>  // для malloc/free

 bool* dynamic_arr = malloc(5 * sizeof(bool));

 if (dynamic_arr == NULL) {
        printf("Ошибка выделения памяти!\n");
        return 1;

free(dynamic_arr); 
*/

