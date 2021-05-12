// /**
//  * @file Imagefile.cpp
//  * @brief Файл з реалізацією методів оперування класом
//  *
//  * @author Babenko A.
//  * @date 15-apr-2020
//  * @version 1.0
//  */

#include <Imagefile.h>

imageSize::imageSize()
{
    this->width_ = 0;
    this->height_ = 0;
}

imageSize::imageSize(int width, int height)
{
    this->width_ = width;
    this->height_ = height;
}

Imagefile::Imagefile()
{
    this->imgSize_.width_ = 0;
    this->imgSize_.height_ = 0;
    this->dotsPerInch_ = 0;
}

Imagefile::Imagefile(const Imagefile &imagefile)
{
    *(File *)this = imagefile;
    this->imgSize_ = imagefile.imgSize_;
    this->dotsPerInch_ = imagefile.dotsPerInch_;
}

Imagefile::Imagefile(File &file, int width, int height, int dotsPerInch)
{
    *(File *)this = file;
    this->SetImageSize(width, height);
    this->dotsPerInch_ = dotsPerInch;
}

Imagefile::~Imagefile()
{
}

void Imagefile::SetImageSize(int width, int height)
{
    this->imgSize_.width_ = width;
    this->imgSize_.height_ = height;
}

void Imagefile::SetDotsPerInch(int dotsPerInch)
{
    this->dotsPerInch_ = dotsPerInch;
}

int Imagefile::GetImageSizeWidth() const
{
    return this->imgSize_.width_;
}
int Imagefile::GetImageSizeHeight() const
{
    return this->imgSize_.height_;
}

int Imagefile::GetDotsPerInch() const
{
    return this->dotsPerInch_;
}

Imagefile &Imagefile::operator=(const Imagefile &imagefile)
{
    *(File *)this = imagefile;

    this->imgSize_ = imagefile.imgSize_;
    this->dotsPerInch_ = imagefile.dotsPerInch_;

    return *this;
}

bool Imagefile::operator==(const Imagefile &imagefile) const
{
    return *(File *)this == imagefile &&
           this->imgSize_.width_ == imagefile.imgSize_.width_ &&
           this->imgSize_.height_ == imagefile.imgSize_.height_ &&
           this->dotsPerInch_ == imagefile.dotsPerInch_;
}

ostream &operator<<(ostream &out, const Imagefile &imagefile)
{
    out << boolalpha << imagefile.GetVisiblity() << " "
        << imagefile.GetFilename() << " "
        << imagefile.GetSize() << " "
        << boolalpha << imagefile.GetReadPermission() << " "
        << boolalpha << imagefile.GetWritePermission() << " "
        << boolalpha << imagefile.GetExecutePermission() << " "
        << imagefile.GetExtension() << " "
        << imagefile.GetImageSizeWidth() << " "
        << imagefile.GetImageSizeHeight() << " "
        << imagefile.GetDotsPerInch();

    return out;
}

istream &operator>>(istream &in, Imagefile &imagefile)
{
    const regex reg("^((true)|(false)) [\\w\\d]+ [\\d\\.\\d]+ ((true)|(false)) ((true)|(false)) ((true)|(false)) [\\w\\d]+ [\\d]+ [\\d]+ [\\d]+$");

    string tmp_isVisible;
    string tmp_filename;
    float tmp_size;
    string tmp_read;
    string tmp_write;
    string tmp_execute;
    string tmp_extension;
    int tmp_imgSizeWidth;
    int tmp_imgSizeHeight;
    int tmp_dotsPerInch;

    in >>
        tmp_isVisible >>
        tmp_filename >>
        tmp_size >>
        tmp_read >>
        tmp_write >>
        tmp_execute >>
        tmp_extension >>
        tmp_imgSizeWidth >>
        tmp_imgSizeHeight >>
        tmp_dotsPerInch;
    stringstream ss;
    ss << tmp_isVisible
       << " " << tmp_filename
       << " " << tmp_size
       << " " << tmp_read
       << " " << tmp_write
       << " " << tmp_execute
       << " " << tmp_extension
       << " " << tmp_imgSizeWidth
       << " " << tmp_imgSizeHeight
       << " " << tmp_dotsPerInch;

    if (regex_match(ss.str(), reg))
    {

        imagefile.SetVisiblity(((tmp_isVisible == "true") ? true : false));
        imagefile.SetSize(tmp_size);
        imagefile.SetFilename(tmp_filename);
        imagefile.SetPermission(*new Permission(((tmp_read == "true") ? true : false),
                                                ((tmp_write == "true") ? true : false),
                                                ((tmp_execute == "true") ? true : false)));
        imagefile.SetExtension(tmp_extension);
        imagefile.SetImageSize(tmp_imgSizeWidth, tmp_imgSizeHeight);
        imagefile.SetDotsPerInch(tmp_dotsPerInch);
    }
    else
    {
        cout << "Regex doesn't match" << endl;
        imagefile.SetVisiblity(false);
        imagefile.SetSize(0);
        imagefile.SetFilename("");
        imagefile.SetPermission(*new Permission(false, false, false));
        imagefile.SetExtension("");
        imagefile.SetImageSize(0, 0);
        imagefile.SetDotsPerInch(0);
    }

    return in;
}