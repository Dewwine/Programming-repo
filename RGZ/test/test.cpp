/**
 * @file test.cpp
 * @brief Файл з тестами на реалізації функцій оперування класом
 *
 * @author Babenko A.
 * @date 15-apr-2020
 * @version 1.0
 */

#include "File.h"

// unsigned short TestGetFile()
// {
//     unsigned short is_success = 1;

//     Darray array(1);

//     array.AddFile(new File(true, 50.0f, "file1", new Permission(true, true, false), "txt"));

//     string expected_result = "txt";

//     if (array.GetFile(0)->GetExtension() != expected_result)
//     {
//         is_success = 0;
//         printf("\nThe extension was expected is %s, but GetFile() function returned %s\n", expected_result.c_str(), array.GetFile(0)->GetExtension().c_str());
//     }

//     if (array.GetFile(1) != nullptr)
//     {
//         is_success = 0;
//         printf("\nElement 1 of array != nullptr\n");
//     }

//     array.RemoveFile(0);

//     if (array.GetFile(0) != nullptr)
//     {
//         is_success = 0;
//         printf("\nElement 0 after removing of array != nullptr\n");
//     }

//     return is_success;
// }

/**
 * Точка входу модуля тестування.
 *
 * Запускає розроблені функції верифікації функцій роботи з классов
 * {@link File}.
 *
 * По завершенню тестів виводиться на екран резюмуюча інформація про стан
 * проходження тестів.
 *
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */
int main()
{
    unsigned short is_success = 1;
    // is_success &= TestGetFile();

    // if (is_success)
    // {
    //     printf("\nCongratulations! All tests succeed!\n");
    // }
    // else
    // {
    //     printf("\nSome tests failed. Check logs, fix errors and try again\n");
    // }

    return !is_success;
}