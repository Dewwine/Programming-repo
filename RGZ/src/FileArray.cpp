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
    cout << "Викликано конструктор з параметрами" << endl;
}

FileArray::~FileArray()
{
    cout << "Викликано деструктор колекції" << endl;
}

void FileArray::AddFile(File *file)
{
    filesVector.push_back(file);
}

void FileArray::RemoveFile(unsigned int index)
{
    auto iter = filesVector.cbegin();
    filesVector.erase(iter + index);
}

void FileArray::ShowAll()
{
    for (int i = 0; i < filesVector.size(); i++)
        filesVector[i]->PrintParams();
}

void FileArray::Clear()
{
    filesVector.clear();
}