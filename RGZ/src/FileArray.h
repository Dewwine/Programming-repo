/**
 * @file FileArray.h
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
public:
    vector<File *> filesVector;

public:
    /**
     * Конструктор з параметрами
     */
    FileArray(unsigned int N = 4);

    /**
     * Деструктор
     */
    ~FileArray();

    /**
     * Додавання екземпляру класу у колекцію.
     *
     * Функція додає елемент в динамічний масив 
     * @param file - екземпляр класу, який буде доданий
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
     * Виведення всіх екземплярів класу з колекції.
     *
     * Функція виводить всі елементи з динамічного масиву 
     */
    void ShowAll();

    /**
     * Видалення всіх екземплярів класу з колекції.
     *
     * Функція видаляє всі елементи з динамічного масиву 
     */
    void Clear();
};

#endif