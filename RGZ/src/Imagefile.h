/**
 * @file Imagefile.hpp
 * @brief Файл з реалізацією методів оперування класом
 *
 * @author Babenko A.
 * @date 15-apr-2020
 * @version 1.0
 */

#ifndef _IMAGEFILE_
#define _IMAGEFILE_

#include <File.h>

struct imageSize
{
    imageSize();
    imageSize(int width, int height);
    int width_;
    int height_;
};

class Imagefile : public File
{
private:
    imageSize imgSize_;
    int dotsPerInch_;

public:
    /**
     *  Конструктор за замовчуванням
     */
    Imagefile();

    /**
     *  Конструктор копіювання
     */
    Imagefile(const Imagefile &imagefile);

    /**
     *  Конструктор з параметрами
     */
    Imagefile(bool isVisible,
              string filename,
              float size,
              const Permission &permission,
              string extension,
              int width,
              int height,
              int dotsPerInch);

    /**
     * Запис данних в поле екземпляру класу.
     *
     * Функція записує дані в поле width_ и height_
     * @param width - дані для запису
     * @param height - дані для запису
     */
    void SetImageSize(int width, int height);

    /**
     * Запис данних в поле екземпляру класу.
     *
     * Функція записує дані в поле extension_ 
     * @param dotsPerInch - дані для запису
     */
    void SetDotsPerInch(int dotsPerInch);

    /**
     * Повернення данних з поля екземпляру класу.
     *
     * Функція повертає поле width_ 
     * @return this->imgSize_.width_ - поле екземпляру класу
     */
    int GetImageSizeWidth() const;

    /**
     * Повернення данних з поля екземпляру класу.
     *
     * Функція повертає поле height_ 
     * @return this->imgSize_.height_ - поле екземпляру класу
     */
    int GetImageSizeHeight() const;

    /**
     * Повернення данних з поля екземпляру класу.
     *
     * Функція повертає поле dotsPerInch_ 
     * @return this->dotsPerInch_ - поле екземпляру класу
     */
    int GetDotsPerInch() const;

    /**
     * Виведення параметрів на екран.
     *
     * Функція виводить дані з параметрів на екран 
     */
    void PrintParams() override final;

    /**
     * Приведення до строки.
     *
     * Функція приводить дані до строки 
     * @return str - строка екземпляру класу
     */
    virtual string toString() override final;

    /**
     * Приведення до екземпляру.
     *
     * Функція приводить дані зі до строки екземпляру класу 
     */
    virtual void fromString(string result) override final;

    /**
     * Оператор порівняння
     *
     * Оператор порівнює переданий об'єкт  
     * @param file - екземпляр класу
     */
    bool operator==(const Imagefile &imagefile) const;

    /**
     * Оператор введення
     *
     * Оператор вводить дані з потоку 
     * @param file - екземпляр класу
     */
    friend ostream &operator<<(ostream &out, const Imagefile &imagefile);

    /**
     * Оператор виведення
     *
     * Оператор виводить дані з потоку 
     * @param file - екземпляр класу
     */
    friend istream &operator>>(istream &in, Imagefile &imagefile);
};

#endif