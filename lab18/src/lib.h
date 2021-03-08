#ifndef _BABENKO_15_
#define _BABENKO_15_

/**
 * @file lib.h
 * @brief Файл з описом структури файлу, перерахуванням доступів файлу та функцій
 * оперування ними
 *
 * @author Babenko A.
 * @date 20-feb-2020
 * @version 1.0
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Структура «Доступи»
 */
struct permission
{
    bool read;
    bool write;
    bool execute;
};

/**
 * Структура «Файл»
 */
typedef struct
{
    bool isVisible;
    char *filename[20];
    float size;
    struct permission access;
    char *extension[4];
} file;

/**
 * Переведення строки до булевого типу
 *
 * Функція переводить передану строку в булевий тип даних
 * @param str строка для переводу
 * @return значення true або false
 */
bool bool_input(char *str);

/**
 * Переведення булевого типу в строку
 *
 * Функція переводить переданий булевий тип даних в строку
 * @param b булевий тип даних для переводу
 * @return строку "true" або "false"
 */
char * bool_output(bool b);

/**
 * Вивід до екрану вмісту масиву з даними про файли.
 *
 * Функція у циклі виводить дані на екран про кожний елемент масиву
 * з даними про файл у наступному форматі:
 * "Параметр: значення"
 * @param arr масив з даними про файли, які необхідно вивести на екран
 * @param N кількість файлів у переданому масиві
 */
void output(file *arr, int N);

/**
 * Генерація псевдовипадкових чисел
 *
 * Функція генерує псевдовипадкове число
 * @return псевдовипадкове число типу int
 */
int randomer();

/**
 * Генерація псевдовипадкових чисел
 *
 * Функція генерує псевдовипадкове число
 * @return псевдовипадкове число типу float
 */
float random_float();

/**
 * Генерація псевдовипадкових чисел
 *
 * Функція генерує псевдовипадкове булеве значення
 * @return псевдовипадкове булеве значення
 */
bool random_bool();

/**
 * Створення даних про тварину.
 *
 * Функція генерує та повертає масив файлів з випадковими значеннями його полів
 * @param arr структура {@link file} для заповнення
 */
void generation(file *arr, int N);

char * insert(char *s1, char *s2, int pos);

char * reduce(char *s1, int start, int end);

file * add_struct(file * files, int N);

file * remove_struct(file * files, int n);

void test(file *files, int N);

#endif