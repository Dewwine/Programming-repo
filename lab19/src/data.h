#ifndef _BABENKO_19_
#define _BABENKO_19_

/**
 * @file data.h
 * @brief Файл з описом структури файлу, перерахуванням доступів файлу та функцій
 * оперування ними
 *
 * @author Babenko A.
 * @date 20-mar-2020
 * @version 1.0
 */

#include "list.h"

/**
 * Переведення строки до булевого типу.
 *
 * Функція переводить передану строку в булевий тип даних
 * @param str строка для переводу
 * @return значення true або false
 */
bool bool_input(char *str);

/**
 * Переведення булевого типу в строку.
 *
 * Функція переводить переданий булевий тип даних в строку
 * @param b булевий тип даних для переводу
 * @return строку "true" або "false"
 */
char *bool_output(bool b);

/**
 * Генерація псевдовипадкових чисел.
 *
 * Функція генерує псевдовипадкове число
 * @return псевдовипадкове число типу int
 */
int randomer();

/**
 * Генерація псевдовипадкових чисел.
 *
 * Функція генерує псевдовипадкове число
 * @return псевдовипадкове число типу float
 */
float random_float();

/**
 * Генерація псевдовипадкових чисел.
 *
 * Функція генерує псевдовипадкове булеве значення
 * @return псевдовипадкове булеве значення
 */
bool random_bool();

/**
 * Підрахування кількості строк.
 *
 * Функція рахує кількість строк у переданому файлі.
 * @param filename назва файлу
 * @return кількість строк у файлі
 */
int count_lines(char *filename);

/**
 *  Зчитування з файлу.
 * 
 *  Функція зчитує список з файлу
 *  @param list - показчик на структуру, в якій зберігається розмір списку та показчики на його голову та хвіст
 *  @param filename - назва файлу, з якого зчитується інформація 
 */
void read_list_from_file(DblLinkedList *list, char *filename);

/**
 *  Записування у файл.
 * 
 *  Функція записує список у файл
 *  @param list - показчик на структуру, в якій зберігається розмір списку та показчики на його голову та хвіст
 *  @param filename - назва файлу, у який записується інформація 
 */
void write_list_to_file(DblLinkedList *list, char *filename);

/**
 *  Виведення на екран всього списку відразу.
 * 
 *  Функції виводять інформацію зі списку на екран
 *  @param list - показчик на структуру, в якій зберігається розмір списку та показчики на його голову та хвіст
 */
void output_list(DblLinkedList *list);

/**
 *  Виведення одного елементу (вузла) списку.
 * 
 *  Функції виводять інформацію з одного елементу списку
 *  @param node - елемент списку
 */
void output_node(Node *node);

/**
 *  Пошук файлу за критерієм.
 * 
 *  Функція шукає заданий файл за певним критерієм
 *  @param list - показчик на структуру, в якій зберігається розмір списку та показчики на його голову та хвіст
 */
void find_list(DblLinkedList *list);

/**
 * Отримання елементу списку.
 *
 * Функція повертає показчик на шуканий вузол списку
 * @param list - показчик на структуру, в якій зберігається розмір списку та показчики на його голову та хвіст
 * @param index - індекс елементу
 * @return tmp - шуканий вузол
 */
Node *getNth(DblLinkedList *list, size_t index);

/**
 *  Додавання структури у список.
 *
 * Функція додає елемент в список на місце індексу, де буде відбуватися додавання
 * @param list - показчик на структуру, в якій зберігається розмір списку та показчики на його голову та хвіст
 * @param index - індекс 
 */
void add_to_list(DblLinkedList *list, int index);

/**
 *  Видалення структури зі списку.
 *
 * Функція видаляє структуру з певної позиції масиву
 * @param list - показчик на структуру, в якій зберігається розмір списку та показчики на його голову та хвіст
 * @param index - індекс
 */
void remove_from_list(DblLinkedList *list, int index);

/** 
 * Сортування списку.
 *
 * Функція сортує список за певними критеріями
 * @param list - показчик на структуру, в якій зберігається розмір списку та показчики на його голову та хвіст
 */
void sort_by_criterion(DblLinkedList *list);

#endif