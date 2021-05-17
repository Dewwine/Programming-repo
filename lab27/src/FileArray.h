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

/**
 * Класс колекції файлів
*/
class FileArray
{
private:
    File **array_;
    unsigned int size_;
    int *file_type;

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
    void AddFile(File *file, int index);

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
     * Повернення данних з поля екземпляру класу.
     *
     * Функція повертає поле size_ 
     * @return this->size_ - поле екземпляру класу
     */
    unsigned int GetSize() const;

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

    File *operator[](int index) const;

    // friend ostream &operator<<(ostream &out, const FileArray &array);

    // friend istream &operator>>(istream &in, FileArray &array);
};

#endif