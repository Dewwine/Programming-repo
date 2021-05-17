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
    Videofile vid(true, "vid1", 555.55, Permission(true, false, true), "mp4", 360, 24);
    Imagefile img(false, "vid2", 125.55, Permission(false, false, true), "exe", 1280, 1024, 100);

    int N = 5;
    FileArray arr(N);

    arr.AddFile(&vid, 1);
    arr.AddFile(&img, 2);

    arr[0]->PrintParams();
    arr[1]->PrintParams();

    return 0;
}