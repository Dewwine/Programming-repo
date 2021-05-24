/**
 * @file File.hpp
 * @brief Файл з прототипами методів оперування класом
 *
 * @author Babenko A.
 * @date 15-apr-2020
 * @version 1.0
 */

#ifndef _FILE_
#define _FILE_

#include <Permission.h>

enum FileId
{
    Video = 1,
    Image
};
/**
 * Класс файл
*/
class File
{
private:
    bool isVisible_;
    string filename_;
    float size_;
    Permission permission_;
    string extension_;

public:
    /**
     *  Конструктор за замовчуванням
     */
    File();

    /**
     *  Конструктор копіювання
     */
    File(const File &file);

    /**
     *  Конструктор з параметрами
     */
    File(bool isVisible,
         string filename,
         float size,
         const struct Permission &permission,
         string extension);

    /**
     *  Деструктор
     */
    virtual ~File() = default;

    /**
     * Повернення данних з поля екземпляру класу.
     *
     * Функція повертає поле isVisible_ 
     * @return this->isVisible_ - поле екземпляру класу
     */
    bool GetVisiblity() const;

    /**
     * Повернення данних з поля екземпляру класу.
     *
     * Функція повертає поле size_ 
     * @return this->size_ - поле екземпляру класу
     */
    float GetSize() const;

    /**
     * Повернення данних з поля екземпляру класу.
     *
     * Функція повертає поле filename_ 
     * @return this->filename_ - поле екземпляру класу
     */
    string GetFilename() const;

    /**
     * Повернення данних з поля екземпляру класу.
     *
     * Функція повертає поле read_ 
     * @return this->permission_.read_ - поле екземпляру класу
     */
    bool GetReadPermission() const;

    /**
     * Повернення данних з поля екземпляру класу.
     *
     * Функція повертає поле read_ 
     * @return this->permission_.write_ - поле екземпляру класу
     */
    bool GetWritePermission() const;

    /**
     * Повернення данних з поля екземпляру класу.
     *
     * Функція повертає поле read_ 
     * @return this->permission_.execute_ - поле екземпляру класу
     */
    bool GetExecutePermission() const;

    /**
     * Повернення данних з поля екземпляру класу.
     *
     * Функція повертає поле extension_ 
     * @return this->extension_ - поле екземпляру класу
     */
    string GetExtension() const;

    /**
     * Запис данних в поле екземпляру класу.
     *
     * Функція записує дані в поле isVisible_ 
     * @param isVisible - дані для запису
     */
    void SetVisiblity(bool isVisible);

    /**
     * Запис данних в поле екземпляру класу.
     *
     * Функція записує дані в поле size_ 
     * @param size - дані для запису
     */
    void SetSize(float size);

    /**
     * Запис данних в поле екземпляру класу.
     *
     * Функція записує дані в поле filename_ 
     * @param filename - дані для запису
     */
    void SetFilename(string filename);

    /**
     * Запис данних в поле екземпляру класу.
     *
     * Функція записує дані в поле permission_ 
     * @param permission - дані для запису
     */
    void SetPermission(struct Permission &permission);

    /**
     * Запис данних в поле екземпляру класу.
     *
     * Функція записує дані в поле permission_ 
     * @param permission - дані для запису
     */
    void SetReadPermission(bool read);

    /**
     * Запис данних в поле екземпляру класу.
     *
     * Функція записує дані в поле permission_ 
     * @param permission - дані для запису
     */
    void SetWritePermission(bool write);

    /**
     * Запис данних в поле екземпляру класу.
     *
     * Функція записує дані в поле permission_ 
     * @param permission - дані для запису
     */
    void SetExecutePermission(bool execute);

    /**
     * Запис данних в поле екземпляру класу.
     *
     * Функція записує дані в поле extension_ 
     * @param extension - дані для запису
     */
    void SetExtension(string extension);

    /**
     * Виведення параметрів на екран.
     *
     * Функція виводить дані з параметрів на екран 
     */
    virtual void PrintParams() = 0;

    /**
     * Приведення до строки.
     *
     * Функція приводить дані до строки 
     * @return str - строка екземпляру класу
     */
    virtual string toString() = 0;

    /**
     * Приведення до екземпляру.
     *
     * Функція приводить дані зі до строки екземпляру класу 
     */
    virtual void fromString(string result) = 0;

    /**
     * Оператор присвоєння
     *
     * Оператор присвоює переданий об'єкт  
     * @param file - екземпляр класу
     */
    File &operator=(const File &file);

    /**
     * Оператор порівняння
     *
     * Оператор порівнює переданий об'єкт  
     * @param file - екземпляр класу
     */
    bool operator==(const File &file) const;

    /**
     * Оператор введення
     *
     * Оператор вводить дані з потоку 
     * @param file - екземпляр класу
     */
    friend istream &operator>>(istream &in, File &file);

    /**
     * Оператор виведення
     *
     * Оператор виводить дані з потоку 
     * @param file - екземпляр класу
     */
    friend ostream &operator<<(ostream &out, const File &file);
};

#endif