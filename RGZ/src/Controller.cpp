/**
 * @file Controller.cpp
 * @brief Файл з реалізацією методів оперування класом
 *
 * @author Babenko A.
 * @date 15-apr-2020
 * @version 1.0
 */

#include <Controller.h>

void Controller::readFromFile(string path)
{
  ifstream fin(path);
  fin.seekg(0, ios::cur);
  string tmp_result;

  if (!fin.is_open())
    cout << "Файл не может быть открыт!\n";
  else
  {
    unsigned int i = 0;
    while (getline(fin, tmp_result))
    {
      int fileType;
      const regex videoReg("^((true)|(false)) [\\w\\d]+ [\\d\\.\\d]+ ((true)|(false)) ((true)|(false)) ((true)|(false)) [\\w\\d]+ [\\d]+ [\\d]+$");
      const regex imageReg("^((true)|(false)) [\\w\\d]+ [\\d\\.\\d]+ ((true)|(false)) ((true)|(false)) ((true)|(false)) [\\w\\d]+ [\\d]+ [\\d]+ [\\d]+$");

      stringstream ss;
      ss << tmp_result;

      if (regex_match(ss.str(), videoReg))
      {
        Videofile *vid = new Videofile;
        vid->fromString(tmp_result);
        filesVector.push_back(vid);
      }
      else if (regex_match(ss.str(), imageReg))
      {
        Imagefile *img = new Imagefile;
        img->fromString(tmp_result);
        filesVector.push_back(img);
      }
    }
  }

  fin.close();
}
void Controller::writeToFile(string path)
{
  ofstream fout;
  fout.open(path);
  for (int i = 0; i < filesVector.size(); i++)
  {
    fout << filesVector[i]->toString() << endl;
  }
  fout.close();
}

ostream &operator<<(ostream &out, Controller &array)
{
  for (int i = 0; i < array.filesVector.size(); i++)
    out << array.filesVector[i]->toString() << endl;
  return out;
}

struct SortSize
{
  bool operator()(File *i, File *j)
  {
    return (i->GetSize() < j->GetSize());
  }
} SortSize;

struct SortFileName
{
  bool operator()(File *i, File *j)
  {
    return (i->GetFilename() < j->GetFilename());
  }
} SortFileName;

struct SortExtension
{
  bool operator()(File *i, File *j)
  {
    return (i->GetExtension() < j->GetExtension());
  }
} SortExtension;

void Controller::SortBySize()
{
  sort(filesVector.begin(), filesVector.end(), SortSize);
}

void Controller::SortByFileName()
{
  sort(filesVector.begin(), filesVector.end(), SortFileName);
}

void Controller::SortByExtension()
{
  sort(filesVector.begin(), filesVector.end(), SortExtension);
}

void Controller::PickBySize() const
{
  for (unsigned int i = 0; i < filesVector.size(); i++)
  {
    if (filesVector[i]->GetSize() >= 50)
    {
      filesVector[i]->PrintParams();
    }
  };
}

void Controller::PickAllPermission()
{
  sort(filesVector.begin(), filesVector.end(), SortFileName);
  bool isSecond = false;
  for (unsigned int i = 0; i < filesVector.size(); i++)
  {
    if (filesVector[i]->GetReadPermission() == 1 &&
        filesVector[i]->GetWritePermission() == 1 &&
        filesVector[i]->GetExecutePermission() == 1)
    {
      if (isSecond)
      {
        filesVector[i]->PrintParams();
      }
      isSecond = true;
    }
  };
}

void Controller::PickLessPixels()
{
  const regex imageReg("^((true)|(false)) [\\w\\d]+ [\\d\\.\\d]+ ((true)|(false)) ((true)|(false)) ((true)|(false)) [\\w\\d]+ [\\d]+ [\\d]+ [\\d]+$");

  string tmp;
  int sizeWidth;
  int sizeHeight;
  bool hasImage = false;
  int lessPixels = 0;
  int index = 0;

  for (int i = 0; i < filesVector.size(); i++)
  {
    string str = filesVector[i]->toString();
    stringstream ss;
    ss << str;

    if (regex_match(ss.str(), imageReg))
    {
      ss >> tmp >> tmp >> tmp >> tmp >> tmp >> tmp >> tmp >>
          sizeWidth >> sizeHeight;

      lessPixels = sizeWidth * sizeHeight;
      hasImage = true;
      break;
    }
  }

  for (unsigned int i = 0; i < filesVector.size(); i++)
  {
    string str = filesVector[i]->toString();
    stringstream ss;
    ss << str;

    if (regex_match(ss.str(), imageReg))
    {
      ss >> tmp >> tmp >> tmp >> tmp >> tmp >> tmp >> tmp >>
          sizeWidth >> sizeHeight;

      if (sizeWidth * sizeHeight < lessPixels)
      {
        lessPixels = sizeWidth * sizeHeight;
        index = i;
      }
    }
  }
  filesVector[index]->PrintParams();
};
