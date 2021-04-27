/**
 * @file Darray.hpp
 * @brief Файл з прототипами методів оперування класом
 *
 * @author Babenko A.
 * @date 15-apr-2020
 * @version 1.0
 */

#ifndef _Darray_
#define _Darray_

#include <File.hpp>
/**
 * Класс колекції файлів
*/
class Darray
{
private:
    File **array_;
    unsigned int size_;
    unsigned int max_size_;

public:
    /**
     *  Конструктор с параметрами
     */
    Darray(unsigned int max_size = 4);

    /**
     *  Деструктор
     */
    ~Darray();

    /**
     *  Додавання екземпляру класу у колекцію.
     *
     * Функція додає елемент в динамічний масив 
     * @param file - показчик на екземпляр класу, який буде додано
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
     * Повернення файлу з колекції.
     *
     * Функція повертає елемент з динамічного масиву за індексом 
     * @param index - індекс екземпляру класу, який буде видано
     * @return *(this->array_ + index) - шуканий елемент
     */
    File *GetFile(unsigned int index) const;

    /**
     * Виведення всіх файлів колекції.
     *
     * Функція виводить всі елементи динамічного масиву 
     */
    void ShowAll() const;

    /**
     * Виведення файлів колекції > 50kb.
     *
     * Функція виводить всі елементи динамічного масиву > 50kb 
     */
    void PickBySize() const;
};

#endif