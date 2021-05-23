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
     *  Деструктор
     */
    // ~Videofile();

    void SetResolution(int resolution);

    void SetFramerate(int frameRate);

    int GetResolution() const;

    int GetFramerate() const;

    void PrintParams() override final;

    virtual string toString() final;

    virtual void fromString(string result) final;

    bool operator==(const Videofile &videofile) const;

    friend ostream &operator<<(ostream &out, const Videofile &videofile);

    friend istream &operator>>(istream &in, Videofile &videofile);
};

#endif