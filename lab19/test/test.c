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

// unsigned short test_insert()
// {
// 	unsigned short is_success = 1;

// 	char *str1 = (char *)malloc(sizeof(char));
// 	char *str2 = (char *)malloc(sizeof(char));
// 	int n = 4;

// 	str1 = "abrakadabra";
// 	str2 = "TEXT2";

// 	char expected_result[] = "abraTEXT2kadabra";

// 	if (strcmp(insert(str1, str2, n), expected_result) != 0)
// 	{
// 		printf("\nThe string was expected is %s, but insert() function returned %s\n", expected_result, insert(str1, str2, n));
// 		is_success = 0;
// 	}

// 	return is_success;
// }

// unsigned short test_reduce()
// {
// 	unsigned short is_success = 1;

// 	char *str1 = (char *)malloc(sizeof(char));
// 	int n1 = 4,
// 		n2 = 8;

// 	str1 = "abrakadabra";

// 	char expected_result[] = "abrara";

// 	if (strcmp(reduce(str1, n1, n2), expected_result) != 0)
// 	{
// 		printf("\nThe string was expected is %s, but reduce() function returned %s\n", expected_result, reduce(str1, n1, n2));
// 		is_success = 0;
// 	}

// 	return is_success;
// }

// unsigned short test_add_struct()
// {
// 	unsigned short is_success = 1;
	
// 	int n = 3,
// 		sum = 0,
// 		result = 4;

// 	file *test_array = calloc(n, sizeof(file));
// 	generation(test_array, n);

// 	add_struct(test_array, n);

// 	for (int i = 0; i < n + 1; i++)
// 	{
// 		if (test_array[i].size != 0)
// 		{
// 			sum += 1;
// 		}
// 	}

// 	if (sum != result)
// 	{
// 		printf("\nCount of array was expected is %d, but add_struct() function returned %d\n", result, sum);
// 		is_success = 0;
// 	}
// 	free(test_array);
// 	return is_success;
// }

// unsigned short test_remove_struct()
// {
// 	unsigned short is_success = 1;
	
// 	int n = 3,
// 		sum = 0,
// 		result = 2;

// 	file *test_array = calloc(n, sizeof(file));
// 	generation(test_array, n);

// 	remove_struct(test_array, n);

// 	for (int i = 0; i < n; i++)
// 	{
// 		if (test_array[i].size != 0)
// 		{
// 			sum += 1;
// 		}
// 	}

// 	if (sum != result)
// 	{
// 		printf("\nCount of array was expected is %d, but remove_struct() function returned %d\n", result, sum);
// 		is_success = 0;
// 	}
// 	free(test_array);
// 	return is_success;
// }

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
	// srand((unsigned int)time(0));
	// unsigned short is_success = 1;
	// is_success &= test_insert();
	// is_success &= test_reduce();
	// is_success &= test_add_struct();
	// is_success &= test_remove_struct();

	// if (is_success)
	// {
	// 	printf("\nCongratulations! All tests succeed!\n");
	// }
	// else
	// {
	// 	printf("\nSome tests failed. Check logs, fix errors and try again\n");
	// }
	// return !is_success;
}