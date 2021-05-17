/**
 * @file main.cpp
 * @brief Файл з викликом методів.
 *
 * @author Babenko A.
 * @date 15-apr-2021
 * @version 1.0
 */

#include <FileArray.h>

int main()
{

    Videofile vid1(true, "vid1", 555.55, Permission(true, false, true), "mp4", 360, 24);
    Imagefile img1(false, "img1", 10.55, Permission(false, false, true), "exe", 1280, 1024, 100);
    Videofile vid2(true, "vid1", 20.55, Permission(true, false, true), "mp4", 360, 24);
    Imagefile img2(false, "img1", 40.55, Permission(false, false, true), "exe", 1280, 1024, 100);

    FileArray vec;
    FileArray vec2;

    vec.AddFile(&vid1);
    vec.AddFile(&img1);

    vec2.AddFile(&vid2);
    vec2.AddFile(&img2);

    vec.ShowAll();
    cout << "---------------------------------" << endl;
    vec.SortBySize();
    cout << "---------------------------------" << endl;
    vec.ShowAll();

    // vec.ShowAll();
    // cout << "---------------------------------" << endl;
    // vec2.ShowAll();
    // vec.ConcVec(vec2.files);
    // cout << "---------------------------------" << endl;
    // cout << "---------------------------------" << endl;
    // vec.ShowAll();

    return 0;
}