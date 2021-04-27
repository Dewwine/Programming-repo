/**
 * @file Darray.cpp
 * @brief Файл з реалізацією методів оперування класом
 *
 * @author Babenko A.
 * @date 15-apr-2020
 * @version 1.0
 */

#include <File.hpp>

File::File()
{
    // cout << "\nВикликано конструктор за замовччуванням\n";

    isVisible_ = false;
    filename_ = "empty";
    size_ = 0;
    permission_ = nullptr;
    extension_ = "empty";
}

File::File(const File &file)
{
    // cout << "\nВикликано конструктор копіювання" << endl;

    this->isVisible_ = file.isVisible_;
    this->filename_ = file.filename_;
    this->size_ = file.size_;
    this->permission_ = new Permission(file.permission_->read_, file.permission_->write_, file.permission_->execute_);
    this->extension_ = file.extension_;
}

File::File(bool isVisible, string filename, float size, const Permission &permission, string extension)
{
    // cout << "\nВикликано конструктор з аргументами" << endl;

    this->isVisible_ = isVisible;
    this->filename_ = filename;
    this->size_ = size;
    this->permission_ = new Permission(permission);
    this->extension_ = extension;
}

File::~File()
{
    if (this->permission_ != nullptr)
    {
        delete this->permission_;
    }
}

bool File::GetVisiblity() const
{
    return this->isVisible_;
}

float File::GetSize() const
{
    return this->size_;
}

string File::GetFilename() const
{
    return this->filename_;
}

struct Permission &File::GetPermission() const
{
    return *this->permission_;
}

string File::GetExtension() const
{
    return this->extension_;
}

// void File::fromString(string str)
// {
//     stringstream result(str);

//     string tmp_isVisible;
//     // string tmp_filename;
//     // float tmp_size;
//     string tmp_read;
//     string tmp_write;
//     string tmp_execute;
//     // string tmp_extension;

//     result >> this->isVisible_ >> this->size_ >> this->filename_ >> tmp_read >> tmp_write >> tmp_execute >> this->extension_;

//     this->SetVisiblity(((tmp_isVisible == "true") ? true : false));
//     // this->SetSize(tmp_size);
//     // this->SetFilename(tmp_filename);
//     this->SetPermission(*new Permission(((tmp_read == "true") ? true : false),
//                                         ((tmp_write == "true") ? true : false),
//                                         ((tmp_execute == "true") ? true : false)));
//     // this->SetExtension(tmp_extension);

//     result >> *this;
// }

void File::SetVisiblity(bool isVisible)
{
    this->isVisible_ = isVisible;
}

void File::SetSize(float size)
{
    this->size_ = size;
}

void File::SetFilename(string filename)
{
    this->filename_ = filename;
}

void File::SetPermission(struct Permission &permission)
{
    if (this->permission_ != nullptr)
    {
        delete this->permission_;
    }

    this->permission_ = &permission;
}

void File::SetExtension(string extension)
{
    this->extension_ = extension;
}

File &File::operator=(const File &file)
{
    if (this != &file)
    {
        this->isVisible_ = file.isVisible_;
        this->filename_ = file.filename_;
        this->size_ = file.size_;
        this->permission_->read_ = file.permission_->read_;
        this->permission_->write_ = file.permission_->write_;
        this->permission_->execute_ = file.permission_->execute_;
        this->extension_ = file.extension_;
    }

    return *this;
}

bool File::operator==(const File &file) const
{
    return (this == &file) ||
           (this->isVisible_ == file.isVisible_ &&
            this->filename_ == file.filename_ &&
            this->size_ == file.size_ &&
            this->permission_->read_ == file.permission_->read_ &&
            this->permission_->write_ == file.permission_->write_ &&
            this->permission_->execute_ == file.permission_->execute_ &&
            this->extension_ == file.extension_);
}

istream &operator>>(istream &in, File &file)
{
    const regex reg ("^((true)|(false)) [\\w\\d]+ [\\d\\.\\d]+ ((true)|(false)) ((true)|(false)) ((true)|(false)) [\\w\\d]+$");

    string tmp_isVisible;
    string tmp_filename;
    float tmp_size;
    string tmp_read;
    string tmp_write;
    string tmp_execute;
    string tmp_extension;

    in >> tmp_isVisible >> tmp_filename >> tmp_size >> tmp_read >> tmp_write >> tmp_execute >> tmp_extension;
    stringstream ss;
    ss << tmp_isVisible
        << " " << tmp_filename 
        << " " << tmp_size
        << " " << tmp_read 
        << " " << tmp_write 
        << " " << tmp_execute 
        << " " << tmp_extension;

    if (regex_match(ss.str(), reg)) {

        file.SetVisiblity(((tmp_isVisible == "true") ? true : false));
        file.SetSize(tmp_size);
        file.SetFilename(tmp_filename);
        file.SetPermission(*new Permission(((tmp_read == "true") ? true : false),
                                            ((tmp_write == "true") ? true : false),
                                            ((tmp_execute == "true") ? true : false)));
        file.SetExtension(tmp_extension);
    } else {
        cout << "Regex doesn't match" << endl;
        file.SetVisiblity(false);
        file.SetSize(0);
        file.SetFilename("");
        file.SetPermission(*new Permission(false, false, false));
        file.SetExtension("");
    }

    return in;

}

ostream &operator<<(ostream &out, const File &file)
{
    out << boolalpha << file.isVisible_ << " "
        << file.filename_ << " "
        << file.size_ << " "
        << boolalpha << file.permission_->read_ << " "
        << boolalpha << file.permission_->write_ << " "
        << boolalpha << file.permission_->execute_ << " "
        << file.extension_;

    return out;
}
