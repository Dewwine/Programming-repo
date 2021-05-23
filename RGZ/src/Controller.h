/**
 * @file Controller.h
 * @brief Файл з прототипами методів оперування класом
 *
 * @author Babenko A.
 * @date 15-apr-2020
 * @version 1.0
 */

#ifndef _Controller_
#define _Controller_

#include <FileArray.h>

/**
 * Класс контроллер
*/
class Controller : public FileArray
{
public:
  /**
   * Читання з файлу.
   *
   * Функція читає масив елементів з файлу
   * @param path - назва файлу з якого буде виконано читання
   */
  void readFromFile(string path);

  /**
   * Запис в файл.
   *
   * Функція записує масив елементів з файлу
   * @param path - назва файлу в який буде виконано запис
   */
  void writeToFile(string path);

  /**
   * Виведення файлів колекції > 50kb.
   *
   * Функція виводить всі елементи динамічного масиву > 50kb
   */
  void PickBySize() const;

  void PickAllPermission();

  void PickLessPixels();

  void SortBySize();

  void SortByFileName();

  void SortBySortExtension();
};

#endif