/**
 * @file main.cpp
 * @brief Файл з викликом методів.
 *
 * @author Babenko A.
 * @date 15-apr-2021
 * @version 1.0
 */

#include <Darray.hpp>
#include <iostream>

int main()
{
    srand(time(0));
    int N;
    cout << "\nEnter count of elements in array" << endl;
    cin >> N;

    Darray arr(N);

    string filePath;
    cout << "\nEnter path to file" << endl;
    cin >> filePath;
    arr.readFromFile(filePath);

    int isExit = 1;
    int pick;
    int index;

    string ext_arr[10] = {"txt", "docx", "pdf", "mp3", "avi", "mp4", "mkv", "exe", "bat", "jar"};

    while (isExit)
    {
        stringstream addedfile;
        stringstream filename_str;
        float size = rand() % 100 + 1 + (float)((rand() % 1000)) / 1000;
        unsigned int arr_size = arr.GetSize() + 1;

        cout << "\nEnter what you want to do?\nAdd element[1]\tRemove element[2]\tFind file > 50 kb[3]\tShow all elements[4]\tGet element by index[5]\tWrite to file[6]\tExit[7]" << endl;
        cin >> pick;

        switch (pick)
        {
        case 1:
            filename_str << "file" << arr_size;

            addedfile << boolalpha
                      << (((rand() % 2) == 0) ? false : true) << " "
                      << size << " "
                      << filename_str.str() << " "
                      << (((rand() % 2) == 0) ? false : true) << " "
                      << (((rand() % 2) == 0) ? false : true) << " "
                      << (((rand() % 2) == 0) ? false : true) << " "
                      << ext_arr[rand() % 10];

            arr.AddFile(addedfile.str());
            arr.ShowAll();
            break;
        case 2:
            cout << "Enter index for removing" << endl;
            cin >> index;
            arr.RemoveFile(index);
            arr.ShowAll();
            cout << arr.GetSize();
            break;
        case 3:
            arr.PickBySize();
            break;
        case 4:
            arr.ShowAll();
            break;
        case 5:
            cout << "Enter index for getting" << endl;
            cin >> index;
            if (arr.GetFile(index) != nullptr)
            {
                cout << arr.GetFile(index)->toString();
            }
            break;
        case 6:
            arr.writeToFile("files/output.txt");
            break;
        case 7:
            isExit = 0;
            break;
        default:
            cout << "You entered incorrect number." << endl;
            break;
        }
    }

    return 0;
}