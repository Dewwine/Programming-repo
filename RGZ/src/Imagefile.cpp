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

Imagefile::Imagefile() : File()
{
    this->imgSize_.width_ = 0;
    this->imgSize_.height_ = 0;
    this->dotsPerInch_ = 0;
}

Imagefile::Imagefile(const Imagefile &imagefile) : File(imagefile)
{
    this->imgSize_ = imagefile.imgSize_;
    this->dotsPerInch_ = imagefile.dotsPerInch_;
}

Imagefile::Imagefile(bool isVisible,
                     string filename,
                     float size,
                     const Permission &permission,
                     string extension,
                     int width,
                     int height,
                     int dotsPerInch) : File(isVisible,
                                             filename,
                                             size,
                                             permission,
                                             extension)
{
    this->SetImageSize(width, height);
    this->dotsPerInch_ = dotsPerInch;
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

void Imagefile::PrintParams()
{
    cout << endl;

    cout << "Visiblity: " << boolalpha << this->GetVisiblity() << endl;
    cout << "Filename: " << this->GetFilename() << endl;
    cout << "Size: " << this->GetSize() << endl;
    cout << "Readable: " << boolalpha << this->GetReadPermission() << endl;
    cout << "Writable: " << boolalpha << this->GetWritePermission() << endl;
    cout << "Executable: " << boolalpha << this->GetExecutePermission() << endl;
    cout << "Extension: " << this->GetExtension() << endl;
    cout << "Width: " << this->GetImageSizeWidth() << endl;
    cout << "Height: " << this->GetImageSizeHeight() << endl;
    cout << "Dots per inch: " << this->GetDotsPerInch() << endl;
}

string Imagefile::toString()
{
    stringstream result;

    result << boolalpha << this->GetVisiblity() << " "
           << this->GetFilename() << " "
           << this->GetSize() << " "
           << boolalpha << this->GetReadPermission() << " "
           << boolalpha << this->GetWritePermission() << " "
           << boolalpha << this->GetExecutePermission() << " "
           << this->GetExtension() << " "
           << this->GetImageSizeWidth() << " "
           << this->GetImageSizeHeight() << " "
           << this->GetDotsPerInch();

    return result.str();
}

void Imagefile::fromString(string str)
{
    stringstream result(str);

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

    result >>
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

    this->SetVisiblity(((tmp_isVisible == "true") ? true : false));
    this->SetSize(tmp_size);
    this->SetFilename(tmp_filename);
    this->SetReadPermission(((tmp_read == "true") ? true : false));
    this->SetWritePermission(((tmp_write == "true") ? true : false));
    this->SetExecutePermission(((tmp_execute == "true") ? true : false));
    this->SetExtension(tmp_extension);
    this->SetImageSize(tmp_imgSizeWidth, tmp_imgSizeHeight);
    this->SetDotsPerInch(tmp_dotsPerInch);
}

bool Imagefile::operator==(const Imagefile &imagefile) const
{
    return *(File *)this == imagefile &&
           this->imgSize_.height_ == imagefile.imgSize_.height_ &&
           this->imgSize_.width_ == imagefile.imgSize_.width_ &&
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
    const regex reg("^((true)|(false)) [\\w\\d]+ [\\d\\.\\d]+ ((true)|(false)) ((true)|(false)) ((true)|(false)) [\\w\\d]+ [\\d]+ [\\d]+$");

    string tmp_isVisible;
    string tmp_filename;
    float tmp_size;
    string tmp_read;
    string tmp_write;
    string tmp_execute;
    string tmp_extension;
    int tmp_img_width;
    int tmp_img_height;
    int tmp_dots_per_inch;

    in >>
        tmp_isVisible >>
        tmp_filename >>
        tmp_size >>
        tmp_read >>
        tmp_write >>
        tmp_execute >>
        tmp_extension >>
        tmp_img_width >>
        tmp_img_height >>
        tmp_dots_per_inch;
    stringstream ss;
    ss << tmp_isVisible
       << " " << tmp_filename
       << " " << tmp_size
       << " " << tmp_read
       << " " << tmp_write
       << " " << tmp_execute
       << " " << tmp_extension
       << " " << tmp_img_width
       << " " << tmp_img_height
       << " " << tmp_dots_per_inch;

    if (regex_match(ss.str(), reg))
    {

        imagefile.SetVisiblity(((tmp_isVisible == "true") ? true : false));
        imagefile.SetSize(tmp_size);
        imagefile.SetFilename(tmp_filename);
        imagefile.SetReadPermission(((tmp_read == "true") ? true : false));
        imagefile.SetWritePermission(((tmp_write == "true") ? true : false));
        imagefile.SetExecutePermission(((tmp_execute == "true") ? true : false));
        imagefile.SetExtension(tmp_extension);
        imagefile.SetImageSize(tmp_img_width, tmp_img_height);
        imagefile.SetDotsPerInch(tmp_dots_per_inch);
    }
    else
    {
        cout << "Regex doesn't match" << endl;
        imagefile.SetVisiblity(false);
        imagefile.SetSize(0);
        imagefile.SetFilename("");
        imagefile.SetReadPermission(false);
        imagefile.SetWritePermission(false);
        imagefile.SetExecutePermission(false);
        imagefile.SetExtension("");
        imagefile.SetImageSize(0, 0);
        imagefile.SetDotsPerInch(0);
    }

    return in;
}