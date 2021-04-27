/**
 * @file Darray.cpp
 * @brief Файл з реалізацією методів оперування класом
 *
 * @author Babenko A.
 * @date 15-apr-2020
 * @version 1.0
 */

#include <File.hpp>

// using std::cout;
// using std::endl;
// using std::stringstream;

File::File()
{
    printf("\nВикликано конструктор за замовччуванням\n");

    isVisible_ = false;
    size_ = 0;
    filename_ = "empty";
    permission_ = new Permission(false, false, false);
    extension_ = "empty";
}

File::File(const File &file)
{
    cout << "\nВикликано конструктор копіювання" << endl;

    this->isVisible_ = file.isVisible_;
    this->size_ = file.size_;
    this->filename_ = file.filename_;
    this->permission_ = new Permission(file.permission_);
    this->extension_ = file.extension_;
}

File::File(bool isVisible, float size, string filename, Permission *permission, string extension)
{
    cout << "\nВикликано конструктор з аргументами" << endl;

    this->isVisible_ = isVisible;
    this->size_ = size;
    this->filename_ = filename;
    this->permission_ = permission;
    this->extension_ = extension;
}

File::~File()
{
    cout << "\nВикликано деструктор\n"
         << endl;

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

struct Permission *File::GetPermission() const
{
    return this->permission_;
}

string File::GetExtension() const
{
    return this->extension_;
}

string File::toString()
{
    stringstream result;

    result << endl
           << "Visibility: " << boolalpha << this->isVisible_ << endl
           << "Filename: " << this->filename_ << endl
           << "File size: " << this->size_ << "kb" << endl
           << "Readable: " << boolalpha << this->permission_->read_ << endl
           << "Writeable: " << boolalpha << this->permission_->write_ << endl
           << "Executable: " << boolalpha << this->permission_->execute_ << endl
           << "File extension: " << this->extension_ << endl
           << endl;

    return result.str();
}

void File::fromString(string str)
{
    stringstream result(str);

    string tmp_isVisible;
    string tmp_filename;
    float tmp_size;
    string tmp_read;
    string tmp_write;
    string tmp_execute;
    string tmp_extension;

    result >> tmp_isVisible >> tmp_size >> tmp_filename >> tmp_read >> tmp_write >> tmp_execute >> tmp_extension;

    this->SetVisiblity(((tmp_isVisible == "true") ? true : false));
    this->SetSize(tmp_size);
    this->SetFilename(tmp_filename);
    this->SetPermission(new Permission(((tmp_read == "true") ? true : false),
                                       ((tmp_write == "true") ? true : false),
                                       ((tmp_execute == "true") ? true : false)));
    this->SetExtension(tmp_extension);
}


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

void File::SetPermission(Permission *permission)
{
    if (this->permission_ != nullptr)
    {
        delete this->permission_;
    }

    this->permission_ = permission;
}

void File::SetExtension(string extension)
{
    this->extension_ = extension;
}