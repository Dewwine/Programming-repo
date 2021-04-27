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

#include <Permission.hpp>

/**
 * Класс файл
*/
class File
{
private:
    bool isVisible_;
    string filename_;
    float size_;
    Permission *permission_;
    string extension_;

public:
    /**
     *  Конструктор за замовчуванням
     */
    File();

    /**
     *  Конструктор копіювання
     */
    File(const File& file);

    /**
     *  Конструктор з параметрами
     */
    File(bool isVisible,
         string filename,
         float size,
         const struct Permission& permission,
         string extension);

    /**
     *  Деструктор
     */
    ~File();

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
     * Функція повертає поле permission_ 
     * @return this->permission_ - поле екземпляру класу
     */
    struct Permission& GetPermission() const;
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
    void SetPermission(struct Permission& permission);
    /**
     * Запис данних в поле екземпляру класу.
     *
     * Функція записує дані в поле extension_ 
     * @param extension - дані для запису
     */
    void SetExtension(string extension);

    /**
     * Виведення файлу колекції.
     *
     * Функція виводить всі елементи динамічного масиву в строку
     */
    string toString() const;

    /**
     * Введення файлу колекції.
     *
     * Функція вводить всі елементи динамічного масиву зі строки 
     */
    // void fromString(string str);


    File& operator=(const File& file);
    
    bool operator==(const File& file) const;

    friend istream& operator>>(istream& in, File& file);

    friend ostream& operator<<(ostream& out, const File& file);

};

#endif