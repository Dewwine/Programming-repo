/**
 * @file Menu.cpp
 * @brief Файл з реалізацією методів оперування класом
 *
 * @author Babenko A.
 * @date 15-apr-2020
 * @version 1.0
 */

#include <Menu.h>

Menu::~Menu()
{
  files.Clear();
}

void Menu::start()
{
  cout << endl
       << "Pick what you want to do" << endl
       << endl;

  cout << "-Read from file [1]" << endl;
  cout << "-Write to file  [2]" << endl;
  cout << "-Print          [3]" << endl;
  cout << "-Add videofile  [4]" << endl;
  cout << "-Add imagefile  [5]" << endl;
  cout << "-Remove file    [6]" << endl;
  cout << "-Clear array    [7]" << endl;
  cout << "-Sort array     [8]" << endl;
  cout << "-Methods        [9]" << endl;
  cout << "-Exit          [10]" << endl;

  short int N;
  cin >> N;

  switch (N)
  {
  case 1:
  {
    string path;
    cout << "Insert path to file for reading:" << endl;
    cin >> path;
    files.readFromFile(path);
    break;
  }
  case 2:
  {
    string path;
    cout << "Insert path to file for writing:" << endl;
    cin >> path;
    files.writeToFile(path);
    break;
  }
  case 3:
  {
    files.ShowAll();
    break;
  }
  case 4:
  {
    Videofile *vid = new Videofile;
    vid->fromString("true added_vidfile 11.11 true false true mp4 1080 60");
    files.AddFile(vid);
    break;
  }
  case 5:
  {
    Imagefile *img = new Imagefile;
    img->fromString("true added_imagefile 22.22 false true false jpg 1920 1080 200");
    files.AddFile(img);
    break;
  }
  case 6:
  {
    cout << "Write index for deleting" << endl;
    short int index = N;
    cin >> index;
    files.RemoveFile(index);
    break;
  }
  case 7:
  {
    files.Clear();
    break;
  }
  case 8:
  {
    short int sortVariant;
    cout << "Pick variant of sorting: " << endl
         << endl;

    cout << "-By filename   [1]" << endl;
    cout << "-By size       [2]" << endl;
    cout << "-By extension  [3]" << endl;
    cin >> sortVariant;
    switch (sortVariant)
    {
    case 1:
      files.SortByFileName();
      break;
    case 2:
      files.SortBySize();
      break;
    case 3:
      files.SortBySortExtension();
      break;

    default:
      break;
    }
    break;
  }
  case 9:
  {
    short int pickVariant;
    cout << "Pick method: " << endl
         << endl;

    cout << "-Pick files more than 50 kb                [1]" << endl;
    cout << "-Pick second file that have rxw permission [2]" << endl;
    cout << "-Find image with lowest count of pixels    [3]" << endl;
    cin >> pickVariant;
    switch (pickVariant)
    {
    case 1:
      files.PickBySize();
      break;
    case 2:
      files.PickAllPermission();
      break;
    case 3:
      files.PickLessPixels();
      break;

    default:
      break;
    }
    break;
  }
  case 10:
    exit(0);

  default:
    break;
  }
  start();
}