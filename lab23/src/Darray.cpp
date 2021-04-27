/**
 * @file Darray.cpp
 * @brief Файл з реалізацією методів оперування класом
 *
 * @author Babenko A.
 * @date 15-apr-2020
 * @version 1.0
 */

#include <Darray.hpp>

Darray::Darray(unsigned int max_size)
{
    printf("\nВикликано конструктор масива\n");

    this->array_ = new File *[max_size];
    this->size_ = 0;
    this->max_size_ = max_size;
}

Darray::~Darray()
{
    printf("\nВикликано деструктор\n");

    while (this->size_ > 0)
    {
        RemoveFile(this->size_ - 1);
    }

    delete[] this->array_;
}

File *Darray::GetFile(unsigned int index) const
{
    if (index >= this->size_)
    {
        return nullptr;
    }
    (*(this->array_ + index))->OutputFile();
    return *(this->array_ + index);
}

void Darray::ShowAll() const
{
    File *item;
    for (unsigned int i = 0; i < size_; ++i)
    {
        item = *(this->array_ + i);
        item->OutputFile();
    }
}

void Darray::AddFile(File *file)
{
    if (this->size_ >= this->max_size_)
    {
        return;
    }

    *(this->array_ + this->size_) = file;
    ++this->size_;
}

void Darray::RemoveFile(unsigned int index)
{
    if (index >= this->size_)
    {
        return;
    }

    delete *(this->array_ + index);
    --this->size_;

    while (index < this->size_)
    {
        *(this->array_ + index) = *(this->array_ + index + 1);
        ++index;
    }

    *(this->array_ + index) = nullptr;
}

void Darray::PickBySize() const
{
    for (int i = 0; i < this->size_; i++)
    {
        if ((*(this->array_ + i))->GetSize() >= 50)
        {
            (*(this->array_ + i))->OutputFile();
        }
    };
}