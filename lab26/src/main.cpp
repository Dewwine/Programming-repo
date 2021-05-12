/**
 * @file main.cpp
 * @brief Файл з викликом методів.
 *
 * @author Babenko A.
 * @date 15-apr-2021
 * @version 1.0
 */

#include <Darray.h>
#include <VideoArray.h>
#include <ImageArray.h>

int main()
{
    File file(true, "vid1", 555.55, Permission(true, false, true), "mp4");
    cout << file << endl;
    Videofile vid(file, 360, 24);
    cout << vid << endl;
    Imagefile img(file, 1280, 1024, 100);
    cout << img << endl;

    VideoArray vidArr(10);

    string filePath = "files/VideoInput.txt";
    ifstream fin(filePath);
    fin >> vidArr;
    fin.close();
    cout << vidArr;

    ImageArray imgArr(10);

    string filePath2 = "files/ImageInput.txt";
    ifstream fin2(filePath2);
    fin2 >> imgArr;
    fin2.close();
    cout << imgArr;

    return 0;
}