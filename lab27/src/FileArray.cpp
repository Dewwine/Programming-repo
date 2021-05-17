/**
 * @file FileArray.cpp
 * @brief Файл з реалізацією методів оперування класом
 *
 * @author Babenko A.
 * @date 15-apr-2020
 * @version 1.0
 */

#include <FileArray.h>

FileArray::FileArray(unsigned int N)
{
    cout << "\nВикликано конструктор масива\n";
    this->size_ = N;
    this->file_type = new int[this->size_];

    for (int i = 0; i < this->size_; i++)
    {
        this->file_type[i] = 2;
    }

    this->array_ = new File *[N];
}

FileArray::~FileArray()
{
    cout << "\nВикликано деструктор\n";

    delete[] this->array_;
    delete[] this->file_type;
}

void FileArray::AddFile(File *file, int index)
{
    this->size_++;
    File **temp_arr = new File *[this->size_];
    int *file_type_temp = new int[this->size_];

    for (unsigned int i = 0, j = 0; i < this->size_; i++)
    {
        if (i == index - 1)
            temp_arr[i] = file;
        else
            temp_arr[i] = this->array_[j++];
    }

    delete[] this->array_;
    this->array_ = temp_arr;

    for (unsigned int i = 0, j = 0; i < this->size_; i++)
    {
        if (i == index - 1)
            file_type_temp[i] = 2;
        else
            file_type_temp[i] = this->file_type[j++];
    }

    delete[] this->file_type;
    this->file_type = file_type_temp;
}

void FileArray::RemoveFile(unsigned int index)
{
    if (index >= this->size_)
    {
        return;
    }

    delete this->array_[index];
    --this->size_;

    while (index < this->size_)
    {
        this->array_[index] = this->array_[index + 1];
        ++index;
    }

    this->array_[index] = nullptr;
}

void FileArray::PickBySize() const
{
    for (unsigned int i = 0; i < this->size_; i++)
    {
        if (this->array_[i]->GetSize() >= 50)
        {
            cout << *this->array_[i] << endl;
        }
    };
}

unsigned int FileArray::GetSize() const
{
    return this->size_;
}

void FileArray::readFromFile(string fileName)
{
    ifstream fin(fileName);

    fin.seekg(0, ios::cur);

    if (!fin.is_open()) // проверка открыт ли файл
        cout << "Файл не может быть открыт!\n";
    else
    {
        for (int i = 0; i < this->size_; i++)
        {
            int file_type_one;

            fin >> file_type_one; // читаем 1 значение в файле. если 1 - это первый наследник, если 2 - второй
            fin.seekg(1, ios::cur);

            string tmp_result;
            getline(fin, tmp_result);

            if (file_type_one == 2)
            {
                ((Videofile *)this->array_[i])->fromString(tmp_result);
                file_type[i] = file_type_one;
            }
            else if (file_type_one == 1)
            {
                ((Imagefile *)this->array_[i])->fromString(tmp_result);
                file_type[i] = file_type_one;
            }
            else
            {
                exit(1);
            }
        }
    }

    fin.close();
}

void FileArray::writeToFile(string fileName)
{
    ofstream fout(fileName);

    if (!fout.is_open()) // проверка открыт ли файл
        cout << "Файл не может быть открыт!\n";
    else
    {
        for (int i = 0; i < this->size_; i++)
        {
            if (this->file_type[i] == 2)
                fout << ((Videofile *)this->array_[i])->toString();

            else if (this->file_type[i] == 1)
                fout << ((Imagefile *)this->array_[i])->toString();

            if (i != this->size_ - 1)
                fout << endl;
        }
    }
}

File *FileArray::operator[](int index) const
{
    if (index >= this->size_)
    {
        return nullptr;
    }

    return this->array_[index];
}

// ostream &operator<<(ostream &out, const FileArray &array)
// {
//     for (unsigned int i = 0; i < array.size_; i++)
//     {
//         out << *array[i] << endl;
//     }

//     return out;
// }

// istream &operator>>(istream &in, FileArray &array)
// {
//     int type_id;
//     const regex reg("^((true)|(false)) [\\w\\d]+ [\\d\\.\\d]+ ((true)|(false)) ((true)|(false)) ((true)|(false)) [\\w\\d]+$");

//     for (unsigned int i = 0; i < array.size_; i++)
//     {

//         string tmp_isVisible;
//         string tmp_filename;
//         float tmp_size;
//         string tmp_read;
//         string tmp_write;
//         string tmp_execute;
//         string tmp_extension;

//         in >> tmp_isVisible >> tmp_filename >> tmp_size >> tmp_read >> tmp_write >> tmp_execute >> tmp_extension;
//         stringstream ss;
//         ss << tmp_isVisible
//            << " " << tmp_filename
//            << " " << tmp_size
//            << " " << tmp_read
//            << " " << tmp_write
//            << " " << tmp_execute
//            << " " << tmp_extension;

//         if (regex_match(ss.str(), reg) && tmp_filename != "")
//         {
//             array.AddFile(ss.str());
//         }
//     }
//     return in;
// }
