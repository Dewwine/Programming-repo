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
    (*(this->array_ + index))->toString();
    return *(this->array_ + index);
}

void Darray::ShowAll() const
{
    File *item;
    for (unsigned int i = 0; i < size_; ++i)
    {
        item = *(this->array_ + i);
        cout << item->toString();
    }
}

void Darray::AddFile(string str)
{
    if (this->size_ >= this->max_size_)
    {
        return;
    }

    File *file = new File;
    file->fromString(str);
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
            cout << (*(this->array_ + i))->toString();
        }
    };
}

unsigned int Darray::GetSize() const
{
    return this->size_;
}

void Darray::readFromFile(string fileName)
{
    ifstream fin(fileName);

    fin.seekg(0, ios::cur); //переместил курсор на начало файла

    if (!fin.is_open()) // проверка открыт ли файл
        cout << "Файл не может быть открыт!\n";
    else
    {
        for (int i = 0; i < this->max_size_; i++)
        {
            if (!(fin.eof()))
            {
                string tmp_result;

                getline(fin, tmp_result);

                File *file = new File;
                file->fromString(tmp_result);

                *(this->array_ + i) = file;
                ++this->size_;
            }
        }
    }

    fin.close();

    this->ShowAll();
}

void Darray::writeToFile(string fileName)
{
    ofstream fout(fileName);

    if (!fout.is_open()) // проверка открыт ли файл
        cout << "Файл не может быть открыт!\n";
    else
    {
        for (int i = 0; i < this->size_; i++)
        {
            fout << (*(this->array_ + i))->toString();

            if (i != this->size_ - 1)
                fout << endl;
        }
    }
}