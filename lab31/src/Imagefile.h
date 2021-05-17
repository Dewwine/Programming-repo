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
     *  Деструктор
     */
    // ~Imagefile();

    void SetImageSize(int width, int height);

    void SetDotsPerInch(int dotsPerInch);

    int GetImageSizeWidth() const;

    int GetImageSizeHeight() const;

    int GetDotsPerInch() const;

    void PrintParams() override final;

    virtual string toString() override final;

    virtual void fromString(string result) override final;
};

#endif