#include <stdarg.h>

int func(int nums, ...)
{
    int count = 0; // Перемення для подсчёта количества пар
    int arr[nums]; // Массив для записи чисел, переданных в функцию
    va_list args;  // Объявление списка аргуметов
    va_start(args, nums); // Начало работы со списком аргументов
    for (int i = 0; i < nums; i++) { 
        arr[i] = va_arg(args, int); // Запись чисел переданных в функцию в массив
    }
    for (int i = 0; i < nums; i++) {
        if (arr[i] < arr[i+1]) {    // Сравнение первого и следующего числа из массива
            count++;                // Увеличение количества пар на 1
        }
    }
    va_end(args);   // Конец работы со списком аргументов
    return count;   // Возвращение результата
}

int main()
{
    printf("%d\n",func(5, 6, 5, 4, 5, 6)); // Вызов функции
    return 0;
}