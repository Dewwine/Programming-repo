// /**
//  * @file Videofile.cpp
//  * @brief Файл з реалізацією методів оперування класом
//  *
//  * @author Babenko A.
//  * @date 15-apr-2020
//  * @version 1.0
//  */

#include <Videofile.h>

Videofile::Videofile() : File()
{
    this->resolution_ = res360;
    this->frameRate_ = 0;
}

Videofile::Videofile(const Videofile &videofile) : File(videofile)
{
    this->frameRate_ = videofile.frameRate_;
    this->resolution_ = videofile.resolution_;
}

Videofile::Videofile(bool isVisible,
                     string filename,
                     float size,
                     const Permission &permission,
                     string extension,
                     int resolution,
                     int frameRate) : File(isVisible,
                                           filename,
                                           size,
                                           permission,
                                           extension)
{
    this->frameRate_ = frameRate;
    this->SetResolution(resolution);
}

void Videofile::SetResolution(int resolution)
{
    switch (resolution)
    {
    case 360:
        this->resolution_ = res360;
        break;
    case 480:
        this->resolution_ = res480;
        break;
    case 720:
        this->resolution_ = res720;
        break;
    case 1080:
        this->resolution_ = res1080;
        break;

    default:
        break;
    }
}

void Videofile::SetFramerate(int frameRate)
{
    this->frameRate_ = frameRate;
}

int Videofile::GetResolution() const
{
    return this->resolution_;
}

int Videofile::GetFramerate() const
{
    return this->frameRate_;
}

void Videofile::PrintParams()
{
    cout << endl;

    cout << "Visiblity: " << boolalpha << this->GetVisiblity() << endl;
    cout << "Filename: " << this->GetFilename() << endl;
    cout << "Size: " << this->GetSize() << endl;
    cout << "Readable: " << boolalpha << this->GetReadPermission() << endl;
    cout << "Writable: " << boolalpha << this->GetWritePermission() << endl;
    cout << "Executable: " << boolalpha << this->GetExecutePermission() << endl;
    cout << "Extension: " << this->GetExtension() << endl;
    cout << "Resolution: " << this->GetResolution() << endl;
    cout << "Framerate: " << this->GetFramerate() << endl;
}

string Videofile::toString()
{
    stringstream result;

    result << boolalpha << this->GetVisiblity() << " "
           << this->GetFilename() << " "
           << this->GetSize() << " "
           << boolalpha << this->GetReadPermission() << " "
           << boolalpha << this->GetWritePermission() << " "
           << boolalpha << this->GetExecutePermission() << " "
           << this->GetExtension() << " "
           << this->GetResolution() << " "
           << this->GetFramerate();

    return result.str();
}

void Videofile::fromString(string str)
{
    stringstream result(str);

    string tmp_isVisible;
    string tmp_filename;
    float tmp_size;
    string tmp_read;
    string tmp_write;
    string tmp_execute;
    string tmp_extension;
    int tmp_resolution;
    int tmp_framerate;

    result >>
        tmp_isVisible >>
        tmp_filename >>
        tmp_size >>
        tmp_read >>
        tmp_write >>
        tmp_execute >>
        tmp_extension >>
        tmp_resolution >> tmp_framerate;

    this->SetVisiblity(((tmp_isVisible == "true") ? true : false));
    this->SetSize(tmp_size);
    this->SetFilename(tmp_filename);
    this->SetReadPermission(((tmp_read == "true") ? true : false));
    this->SetWritePermission(((tmp_write == "true") ? true : false));
    this->SetExecutePermission(((tmp_execute == "true") ? true : false));
    this->SetExtension(tmp_extension);
    this->SetResolution(tmp_resolution);
    this->SetFramerate(tmp_framerate);
}

bool Videofile::operator==(const Videofile &videofile) const
{
    return *(File *)this == videofile &&
           this->resolution_ == videofile.resolution_ &&
           this->frameRate_ == videofile.frameRate_;
}

ostream &operator<<(ostream &out, const Videofile &videofile)
{
    out << boolalpha << videofile.GetVisiblity() << " "
        << videofile.GetFilename() << " "
        << videofile.GetSize() << " "
        << boolalpha << videofile.GetReadPermission() << " "
        << boolalpha << videofile.GetWritePermission() << " "
        << boolalpha << videofile.GetExecutePermission() << " "
        << videofile.GetExtension() << " "
        << videofile.GetResolution() << " "
        << videofile.GetFramerate();

    return out;
}

istream &operator>>(istream &in, Videofile &videofile)
{
    const regex reg("^((true)|(false)) [\\w\\d]+ [\\d\\.\\d]+ ((true)|(false)) ((true)|(false)) ((true)|(false)) [\\w\\d]+ [\\d]+ [\\d]+$");

    string tmp_isVisible;
    string tmp_filename;
    float tmp_size;
    string tmp_read;
    string tmp_write;
    string tmp_execute;
    string tmp_extension;
    int tmp_resolution;
    int tmp_framerate;

    in >>
        tmp_isVisible >>
        tmp_filename >>
        tmp_size >>
        tmp_read >>
        tmp_write >>
        tmp_execute >>
        tmp_extension >>
        tmp_resolution >>
        tmp_framerate;
    stringstream ss;
    ss << tmp_isVisible
       << " " << tmp_filename
       << " " << tmp_size
       << " " << tmp_read
       << " " << tmp_write
       << " " << tmp_execute
       << " " << tmp_extension
       << " " << tmp_resolution
       << " " << tmp_framerate;

    if (regex_match(ss.str(), reg))
    {

        videofile.SetVisiblity(((tmp_isVisible == "true") ? true : false));
        videofile.SetSize(tmp_size);
        videofile.SetFilename(tmp_filename);
        videofile.SetReadPermission(((tmp_read == "true") ? true : false));
        videofile.SetWritePermission(((tmp_write == "true") ? true : false));
        videofile.SetExecutePermission(((tmp_execute == "true") ? true : false));
        videofile.SetExtension(tmp_extension);
        videofile.SetResolution(tmp_resolution);
        videofile.SetFramerate(tmp_framerate);
    }
    else
    {
        cout << "Regex doesn't match" << endl;
        videofile.SetVisiblity(false);
        videofile.SetSize(0);
        videofile.SetFilename("");
        videofile.SetReadPermission(false);
        videofile.SetWritePermission(false);
        videofile.SetExecutePermission(false);
        videofile.SetExtension("");
        videofile.SetResolution(720);
        videofile.SetFramerate(0);
    }

    return in;
}