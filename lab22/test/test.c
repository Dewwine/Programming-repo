/**
 * @file test.c
 * @brief Файл з тестами на реалізації функцій оперування тваринами
 *
 * @author Babenko A.
 * @date 20-feb-2020
 * @version 1.0
 */

#include "list.h"
#include "data.h"

unsigned short test_read_list_from_file()
{
	clock_t start = clock();

    #define __TNAME__ "test_read_list_from_file"

	#ifdef DEBUG
    printf(" Name of test function: %s\n", __TNAME__);
	#endif

	unsigned short is_success = 1;

 	int N = count_lines("test.txt");

	DblLinkedList *list = NULL;
  	list = createDblLinkedList();
	  list->size = N;
  	read_list_from_file(list, "test.txt");
		
	char expected_result1[] = "file1";
	char expected_result2[] = "file2";

	if ((strcmp(list->head->myfile.filename, expected_result1) != 0))
	{
		printf("\nThe name of first file was expected is %s, but read_list_from_file() function returned %s\n", expected_result1, list->head->myfile.filename);
		is_success = 0;
	}

	if ((strcmp(list->head->next->myfile.filename, expected_result2) != 0))
	{
		printf("\nThe name of second file was expected is %s, but read_list_from_file() function returned %s\n", expected_result2, list->head->next->myfile.filename);
		is_success = 0;
	}

	clock_t end = clock();
	float time_spent = (float)(end - start) / CLOCKS_PER_SEC; 

	#ifdef DEBUG
	printf(" Time of test working: %f sec\n", time_spent);
	#endif

	return is_success;
}

/**
 * Точка входу модуля тестування.
 *
 * Запускає розроблені функції верифікації функцій роботи з структурой
 * {@link file}.
 *
 * По завершенню тестів виводиться на екран резюмуюча інформація про стан
 * проходження тестів.
 *
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */
int main()
{
	clock_t start = clock();

	srand((unsigned int)time(0));
	unsigned short is_success = 1;
	is_success &= test_read_list_from_file();

	if (is_success)
	{
		printf("\nCongratulations! All tests succeed!\n");
	}
	else
	{
		printf("\nSome tests failed. Check logs, fix errors and try again\n");
	}

	clock_t end = clock();
	float time_spent = (float)(end - start) / CLOCKS_PER_SEC; 

	#ifdef DEBUG
	printf(" Time of all tests working: %f sec\n", time_spent);
	#endif

	return !is_success;
} 