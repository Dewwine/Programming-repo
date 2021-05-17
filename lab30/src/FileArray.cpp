/**
 * @file FileArray.cpp
 * @brief Файл з реалізацією методів оперування класом
 *
 * @author Babenko A.
 * @date 15-apr-2020
 * @version 1.0
 */

#include <FileArray.h>

FileArray::FileArray(unsigned int N) {}

FileArray::~FileArray() {}

void FileArray::AddFile(File *file)
{
    files.push_back(file);
}

void FileArray::RemoveFile(unsigned int index)
{
    auto iter = files.cbegin();
    files.erase(iter + index);
}

void FileArray::PickBySize() const
{
    for (unsigned int i = 0; i < files.size(); i++)
    {
        if (files[i]->GetSize() >= 50)
        {
            cout << *files[i] << endl;
        }
    };
}

void FileArray::writeToFile(string fileName)
{
    ofstream fout(fileName);
    if (!fout.is_open())
    {
        return;
    }

    fout << *this;

    fout.close();
}

void FileArray::ShowAll()
{
    for (int i = 0; i < files.size(); i++)
        cout << files[i]->toString() << endl;
}

ostream &operator<<(ostream &out, FileArray &array)
{
    for (int i = 0; i < array.files.size(); i++)
        out << array.files[i]->toString() << endl;
    return out;
}

struct sort_files
{
    bool operator()(File *i, File *j)
    {
        return (i->GetSize() < j->GetSize());
    }
} SortSize;

void FileArray::SortBySize()
{
    sort(files.begin(), files.end(), SortSize);
}

void FileArray::ConcVec(vector<File *> v2)
{
    files.insert(files.end(), v2.begin(), v2.end());
}