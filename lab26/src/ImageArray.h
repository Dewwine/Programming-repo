/**
 * @file ImageArray.hpp
 * @brief Файл з прототипами методів оперування класом
 *
 * @author Babenko A.
 * @date 15-apr-2020
 * @version 1.0
 */

#ifndef _ImageArray_
#define _ImageArray_

#include <Imagefile.h>
/**
 * Класс колекції файлів
*/
class ImageArray
{
private:
    Imagefile **array_;
    unsigned int size_;
    unsigned int max_size_;

public:
    /**
     *  Конструктор с параметрами
     */
    ImageArray(unsigned int max_size = 4);

    /**
     *  Деструктор
     */
    ~ImageArray();

    /**
     *  Додавання екземпляру класу у колекцію.
     *
     * Функція додає елемент в динамічний масив 
     * @param str - строка, яка буде додана
     */
    void AddFile(string str);

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
    Imagefile *GetFile(unsigned int index) const;

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

    Imagefile *operator[](int index) const;

    friend ostream &operator<<(ostream &out, const ImageArray &array);

    friend istream &operator>>(istream &in, ImageArray &array);
};

#endif