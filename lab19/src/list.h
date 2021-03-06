#ifndef _BABENKO_18_
#define _BABENKO_18_

/**
 * @file list.h
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
    char filename[20];
    float size;
    struct permission access;
    char extension[4];
} file;

typedef struct _Node
{
    file myfile;
    struct _Node *next;
    struct _Node *prev;
} Node;

typedef struct _DblLinkedList
{
    size_t size;
    Node *head;
    Node *tail;
} DblLinkedList;

DblLinkedList *createDblLinkedList();

void deleteDblLinkedList(DblLinkedList **list);

#endif