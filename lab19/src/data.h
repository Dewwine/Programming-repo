#ifndef _BABENKO_19_
#define _BABENKO_19_

/**
 * @file data.h
 * @brief Файл з описом структури файлу, перерахуванням доступів файлу та функцій
 * оперування ними
 *
 * @author Babenko A.
 * @date 20-feb-2020
 * @version 1.0
 */

#include "list.h"

bool bool_input(char *str);

char * bool_output(bool b);

int randomer();

float random_float();

bool random_bool();

int count_lines(char *filename);

void read_list_from_file(list *p_begin, char *filename, int N);

void write_list_to_file(list *p_begin, char *filename, int N);

void output_list(list *p_begin, int N);

void output_node(list *p);

void find_list(list *p_begin, int N);

void push(list **p_begin);

void add_to_list(list **p_begin, int index);

void remove_from_list(list **p_begin, int index);





#endif