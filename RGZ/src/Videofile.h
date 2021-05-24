/**
 * @file Videofile.hpp
 * @brief Файл з реалізацією методів оперування класом
 *
 * @author Babenko A.
 * @date 15-apr-2020
 * @version 1.0
 */

#ifndef _VIDEOFILE_
#define _VIDEOFILE_

#include <File.h>

class Videofile : public File
{
public:
    typedef enum
    {
        res360 = 360,
        res480 = 480,
        res720 = 720,
        res1080 = 1080
    } resolutionType;

private:
    resolutionType resolution_;
    int frameRate_;

public:
    /**
     *  Конструктор за замовчуванням
     */
    Videofile();

    /**
     *  Конструктор копіювання
     */
    Videofile(const Videofile &videofile);

    /**
     *  Конструктор з параметрами
     */
    Videofile(bool isVisible,
              string filename,
              float size,
              const Permission &permission,
              string extension,
              int resolution,
              int frameRate);

    /**
     * Запис данних в поле екземпляру класу.
     *
     * Функція записує дані в поле resolution_ 
     * @param resolution - дані для запису
     */
    void SetResolution(int resolution);

    /**
     * Запис данних в поле екземпляру класу.
     *
     * Функція записує дані в поле frameRate_ 
     * @param frameRate - дані для запису
     */
    void SetFramerate(int frameRate);

    /**
     * Повернення данних з поля екземпляру класу.
     *
     * Функція повертає поле dotsPerInch_ 
     * @return this->resolution_ - поле екземпляру класу
     */
    int GetResolution() const;

    /**
     * Повернення данних з поля екземпляру класу.
     *
     * Функція повертає поле dotsPerInch_ 
     * @return this->frameRate_ - поле екземпляру класу
     */
    int GetFramerate() const;

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
    virtual string toString() final;

    /**
     * Приведення до екземпляру.
     *
     * Функція приводить дані зі до строки екземпляру класу 
     */
    virtual void fromString(string result) final;

    /**
     * Оператор порівняння
     *
     * Оператор порівнює переданий об'єкт  
     * @param file - екземпляр класу
     */
    bool operator==(const Videofile &videofile) const;

    /**
     * Оператор введення
     *
     * Оператор вводить дані з потоку 
     * @param file - екземпляр класу
     */
    friend ostream &operator<<(ostream &out, const Videofile &videofile);

    /**
     * Оператор виведення
     *
     * Оператор виводить дані з потоку 
     * @param file - екземпляр класу
     */
    friend istream &operator>>(istream &in, Videofile &videofile);
};

#endif