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
    printf("\nВикликано конструктор за замовччуванням\n");

    isVisible_ = false;
    size_ = 0;
    filename_ = "empty";
    permission_ = new Permission(false, false, false);
    extension_ = "empty";
}

File::File(const File &file)
{
    printf("\nВикликано конструктор копіювання\n");

    this->isVisible_ = file.isVisible_;
    this->size_ = file.size_;
    this->filename_ = file.filename_;
    this->permission_ = new Permission(file.permission_);
    this->extension_ = file.extension_;
}

File::File(bool isVisible, float size, string filename, Permission *permission, string extension)
{
    printf("\nВикликано конструктор з аргументами\n");

    this->isVisible_ = isVisible;
    this->size_ = size;
    this->filename_ = filename;
    this->permission_ = permission;
    this->extension_ = extension;
}

File::~File()
{
    printf("\nВикликано деструктор\n");

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

void File::OutputFile() const
{
    printf("\n\n\n\n");

    printf("Visibility: %s\n", this->GetVisiblity() ? "true" : "false");
    printf("Filename: %s\n", this->GetFilename().c_str());
    printf("File size: %.3f kb\n", this->GetSize());
    printf("Readable: %s\n", this->GetPermission()->read_ ? "true" : "false");
    printf("Writeable: %s\n", this->GetPermission()->write_ ? "true" : "false");
    printf("Executable: %s\n", this->GetPermission()->execute_ ? "true" : "false");
    printf("File extension: %s\n", this->GetExtension().c_str());
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