/**
 * @file FileArray.hpp
 * @brief Файл з прототипами методів оперування класом
 *
 * @author Babenko A.
 * @date 15-apr-2020
 * @version 1.0
 */

#ifndef _FileArray_
#define _FileArray_

#include <File.h>
#include <Videofile.h>
#include <Imagefile.h>

using std::vector;

/**
 * Класс колекції файлів
*/
class FileArray
{
public:
    vector<File *> files;

public:
    /**
     *  Конструктор с параметрами
     */
    FileArray(unsigned int N = 4);

    /**
     *  Деструктор
     */
    ~FileArray();

    /**
     *  Додавання екземпляру класу у колекцію.
     *
     * Функція додає елемент в динамічний масив 
     * @param str - строка, яка буде додана
     */
    void AddFile(File *file);

    /**
     * Видалення екземпляру класу з колекцію.
     *
     * Функція видаляє елемент з динамічного масиву 
     * @param index - індекс екземпляру класу, який буде видалено
     */
    void RemoveFile(unsigned int index);

    /**
     * Виведення файлів колекції > 50kb.
     *
     * Функція виводить всі елементи динамічного масиву > 50kb 
     */
    void PickBySize() const;

    /**
     * Читання з файлу.
     *
     * Функція читає масив елементів з файлу 
     * @param fileName - назва файлу з якого буде виконано читання
     */
    void readFromFile(string fileName);

    /**
     * Запис в файл.
     *
     * Функція записує масив елементів з файлу 
     * @param fileName - назва файлу в який буде виконано запис
     */
    void writeToFile(string filename);

    void ShowAll();

    friend ostream &operator<<(ostream &out, FileArray &array);

    void SortBySize();

    void ConcVec(vector<File *> v2);
};

#endif