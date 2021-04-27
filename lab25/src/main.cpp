/**
 * @file main.cpp
 * @brief Файл з викликом методів.
 *
 * @author Babenko A.
 * @date 15-apr-2021
 * @version 1.0
 */

#include <Darray.hpp>

int main()
{
    srand(time(0));
    int N;
    cout << "\nEnter count of elements to read from file" << endl;
    cin >> N;

    Darray arr(N);

    string filePath = "files/input.txt";
    // arr.readFromFile("files/input.txt");
    ifstream fin(filePath);
    fin >> arr;
    fin.close();
    cout << arr;
    
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

        cout << "\nEnter what you want to do?";
        cout << "\nAdd element[1]";
        cout << "\tRemove element[2]";
        cout << "\tFind file > 50 kb[3]";
        cout << "\tShow all elements[4]";
        cout << "\tGet element by index[5]";
        cout << "\nWrite to file[6]";
        cout << "\nRead from file[7]";
        cout << "\nExit[8]";
        cout << "\nПродемонстрировать перегрузку оператора присвоения[9]";
        cout << "\nПродемонстрировать перегрузку оператора сравнения[10]";
        cin >> pick;


        File test(false, "test1", 11, Permission(false, false, true), "txt");
        File test2(true, "test2", 22, Permission(false, true, true), "exe");

        switch (pick)
        {
        case 1:
            filename_str << "file" << arr_size;

            addedfile << boolalpha
                      << (((rand() % 2) == 0) ? false : true) << " "
                      << filename_str.str() << " "
                      << size << " "
                      << (((rand() % 2) == 0) ? false : true) << " "
                      << (((rand() % 2) == 0) ? false : true) << " "
                      << (((rand() % 2) == 0) ? false : true) << " "
                      << ext_arr[rand() % 10];

            arr.AddFile(addedfile.str());
            cout << endl << arr;
            break;
        case 2:
            cout << "Enter index for removing" << endl;
            cin >> index;
            arr.RemoveFile(index);
            cout << endl << arr;
            break;
        case 3:
            cout << endl;
            arr.PickBySize();
            break;
        case 4:
            cout << endl << arr;
            break;
        case 5:
            cout << "Enter index for getting" << endl;
            cin >> index;
            cout << endl;
            if (arr[index] != nullptr)
            {
                cout << *arr[index] << endl;
            }
            break;
        case 6:
            arr.writeToFile("files/output.txt");
            break;
        case 7:
            cout << "\nEnter path to file" << endl;
            cin >> filePath;
            arr.readFromFile(filePath);
            break;
        case 8:
            isExit = 0;
            break;
        case 9:
            cout << endl << test << endl;
            test = File(true, "fileYYY", 55.55, Permission(false, true, false), "exe");
            cout << test << endl;
            break;
        case 10:
            cout << endl << boolalpha << (test == test2) << endl;
            break;
        default:
            cout << endl << "You entered incorrect number." << endl;
            break;
        }
    }

    return 0;
}