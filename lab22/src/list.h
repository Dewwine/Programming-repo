#ifndef _BABENKO_18_
#define _BABENKO_18_

/**
 * @file list.h
 * @brief Файл з описом структури файлу, перерахуванням доступів файлу та функцій
 * оперування ними
 *
 * @author Babenko A.
 * @date 20-mar-2020
 * @version 1.0
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h> 
#include <regex.h> 

#define DEBUG printf("\n Date: %s\n Time: %s\n Name of function: %s\n\n", __DATE__, __TIME__, __FUNCTION__)

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
    char filename[20];
    float size;
    struct permission access;
    char extension[4];
} file;

/**
 * Структура «Вузол»
 */
typedef struct _Node
{
    file myfile;
    struct _Node *next;
    struct _Node *prev;
} Node;

/**
 * Структура «список»
 */
typedef struct _DblLinkedList
{
    size_t size;
    Node *head;
    Node *tail;
} DblLinkedList;

/**
 * Створення двохзв'язного списку.
 *
 * Функція створює двохзв'язний список та повертає покажчик на перший його елемент
 * @return покажчик на перший елемент списку
 */
DblLinkedList *createDblLinkedList();

/**
 * Видалення двохзв'язного списку.
 *
 * Функція очищає пам'ять яка була використана для двохзв'язного списку
 */
void deleteDblLinkedList(DblLinkedList **list);

#endif