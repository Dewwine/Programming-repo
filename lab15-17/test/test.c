/**
 * @file test.c
 * @brief Файл з тестами на реалізації функцій оперування тваринами
 *
 * @author Babenko A.
 * @date 20-feb-2020
 * @version 1.0
 */

#include "lib.h"

/**
 * Верифікація роботи функції {@link pick_by_size}
 * на основі кількості структур > 50 kb що записані в тестовому файлі 
 *
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */
unsigned short test_pick_by_size()
{
	unsigned short is_success = 1;
	file testFiles[10];
	read_from_file(testFiles, 10, "test.txt");
	int N = 6;
	int K = pick_by_size(testFiles, 10, 50);
	if (N != K) {
		printf("\nThe number of files > 50 kb was expected to be %d, but the function returned: %d\n", N, K);
		is_success = 0;
	}
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
	srand((unsigned int)time(0));
	unsigned short is_success = 1;
	is_success &= test_pick_by_size();

	if (is_success) {
		printf("\nCongratulations! All tests succeed!\n");
	} else {
		printf("Some tests failed. Check logs, fix errors and try again\n");
	}
	return !is_success;
}