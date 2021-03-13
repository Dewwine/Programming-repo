/**
 * @file list.c
 * @brief Файл з реалізацією функцій оперування файлами
 *
 * @author Babenko A.
 * @date 20-feb-2020
 * @version 1.0
 */

#include "list.h"

list *create_list(int N)
{
    list *p_begin = NULL;
    list *p = NULL;

    p_begin = (list *)malloc(sizeof(list));
    p = p_begin;
    p->next = NULL;

    for (int i = 0; i < N; i++)
    {
        p->next = (list *)malloc(sizeof(list));
        p = p->next;
        p->next = NULL;
    }
    return p_begin;
}