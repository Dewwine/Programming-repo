/**
 * @file VideoArray.cpp
 * @brief Файл з реалізацією методів оперування класом
 *
 * @author Babenko A.
 * @date 15-apr-2020
 * @version 1.0
 */

#include <VideoArray.h>

VideoArray::VideoArray(unsigned int max_size)
{
    cout << "\nВикликано конструктор масива\n";

    this->array_ = new Videofile *[max_size];
    this->size_ = 0;
    this->max_size_ = max_size;
}

VideoArray::~VideoArray()
{
    cout << "\nВикликано деструктор\n";

    while (this->size_ > 0)
    {
        RemoveFile(this->size_ - 1);
    }

    delete[] this->array_;
}

Videofile *VideoArray::GetFile(unsigned int index) const
{
    if (index >= this->size_)
    {
        return nullptr;
    }

    return this->array_[index];
}

void VideoArray::ShowAll() const
{
    Videofile *item;
    for (unsigned int i = 0; i < size_; ++i)
    {
        item = this->array_[i];
        cout << *item << endl;
    }
}

void VideoArray::AddFile(string str)
{
    Videofile **temp_arr = new Videofile *[this->size_ + 1];

    Videofile *file = new Videofile;
    stringstream ss(str);
    ss >> *file;

    for (unsigned int i = 0; i < this->size_; i++)
    {
        temp_arr[i] = this->array_[i];
    }

    temp_arr[this->size_] = file;

    delete[] this->array_;

    this->array_ = temp_arr;
    ++this->size_;
}

void VideoArray::RemoveFile(unsigned int index)
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

void VideoArray::PickBySize() const
{
    for (unsigned int i = 0; i < this->size_; i++)
    {
        if (this->array_[i]->GetSize() >= 50)
        {
            cout << *this->array_[i] << endl;
        }
    };
}

unsigned int VideoArray::GetSize() const
{
    return this->size_;
}

void VideoArray::readFromFile(string fileName)
{
    ifstream fin(fileName);

    fin.seekg(0, ios::cur); //переместил курсор на начало файла

    if (!fin.is_open()) // проверка открыт ли файл
        cout << "Файл не может быть открыт!\n";
    else
    {
        if (this->size_ != 0)
        {
            for (unsigned int i = 0; i < this->size_; i++)
            {
                delete array_[i];
            }
            this->size_ = 0;
        }

        for (unsigned int i = 0; i < this->max_size_; i++)
        {
            if (!(fin.eof()))
            {
                Videofile *file = new Videofile;
                fin >> *file;

                if (file->GetSize() == 0)
                {
                    delete file;
                    --this->size_;
                }

                this->array_[i] = file;
                ++this->size_;
            }
        }
    }

    fin.close();

    this->ShowAll();
}

void VideoArray::writeToFile(string fileName)
{
    ofstream fout(fileName);

    if (!fout.is_open()) // проверка открыт ли файл
        cout << "Файл не может быть открыт!\n";
    else
    {
        for (unsigned int i = 0; i < this->size_; i++)
        {
            fout << *this->array_[i];

            if (i != this->size_ - 1)
                fout << endl;
        }
    }
}

Videofile *VideoArray::operator[](int index) const
{
    if (index >= this->size_)
    {
        return nullptr;
    }

    return this->array_[index];
}

ostream &operator<<(ostream &out, const VideoArray &array)
{
    for (unsigned int i = 0; i < array.size_; i++)
    {
        out << *array[i] << endl;
    }

    return out;
}

istream &operator>>(istream &in, VideoArray &array)
{
    const regex reg("^((true)|(false)) [\\w\\d]+ [\\d\\.\\d]+ ((true)|(false)) ((true)|(false)) ((true)|(false)) [\\w\\d]+ [\\d]+ [\\d]+$");

    for (unsigned int i = 0; i < array.max_size_; i++)
    {

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

        if (regex_match(ss.str(), reg) && tmp_filename != "")
        {
            array.AddFile(ss.str());
        }
    }
    return in;
}
