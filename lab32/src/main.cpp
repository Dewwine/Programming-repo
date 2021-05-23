/**
 * @file main.cpp
 * @brief Файл з викликом методів.
 *
 * @author Babenko A.
 * @date 15-apr-2021
 * @version 1.0
 */

#include <FileArray.h>
#include <memory>
#include "MyPtr.h"

using std::auto_ptr;
using std::shared_ptr;
using std::unique_ptr;
using std::weak_ptr;

int main()
{

    Videofile vid1(true, "vid1", 555.55, Permission(true, false, true), "mp4", 360, 24);
    Imagefile img1(false, "img1", 10.55, Permission(false, false, true), "exe", 1280, 1024, 100);
    Videofile vid2(true, "vid1", 20.55, Permission(true, false, true), "mp4", 360, 24);
    Imagefile img2(false, "img1", 40.55, Permission(false, false, true), "exe", 1280, 1024, 100);

    // ---------------------auto_ptr----------------------------

    // auto_ptr<FileArray> ap1(new FileArray);

    // auto_ptr<FileArray> ap2(new FileArray);

    // ap1->AddFile(&vid1);
    // ap1->AddFile(&vid2);
    // ap2->AddFile(&img1);
    // ap2->AddFile(&img2);
    // cout << endl
    //      << "ap1: " << endl;
    // ap1->ShowAll();
    // cout << endl
    //      << "До присвоения ap2: " << endl;
    // ap2->ShowAll();
    // cout << endl;

    // ap2 = ap1; // Присвоение указателя ap1 в ap2
    //            // При этом указатель ap1 затирается
    //            // и можно работать только с ap2
    //            // Если попытаться обратится к ap1
    //            // произойдет ошибка сегментирования

    // cout << endl
    //      << "После присвоения ap2 = ap1: " << endl;
    // ap2->ShowAll();
    // cout << endl;

    // ---------------------------------------------------------

    // ---------------------unique_ptr--------------------------

    // unique_ptr<FileArray> ap1(new FileArray);

    // unique_ptr<FileArray> ap2(new FileArray);

    // ap1->AddFile(&vid1);
    // ap1->AddFile(&vid2);
    // ap2->AddFile(&img1);
    // ap2->AddFile(&img2);
    // cout << endl
    //      << "ap1: " << endl;
    // ap1->ShowAll();
    // cout << endl
    //      << "До присвоения ap2: " << endl;
    // ap2->ShowAll();
    // cout << endl;

    // ap2 = move(ap1); // Нельзя напрямую присвоить указатель ap1 в ap2
    //                  // поэтому используется функция move
    //                  // При этом указатель ap1 затирается
    //                  // и можно работать только с ap2
    //                  // Если попытаться обратится к ap1
    //                  // произойдет ошибка сегментирования

    // cout << endl
    //      << "После присвоения ap2 = move(ap1): " << endl;
    // ap2->ShowAll();
    // cout << endl;

    // ---------------------------------------------------------

    // ---------------------shared_ptr--------------------------

    // shared_ptr<FileArray> ap1(new FileArray);

    // shared_ptr<FileArray> ap2(new FileArray);

    // ap1->AddFile(&vid1);
    // ap1->AddFile(&vid2);
    // ap2->AddFile(&img1);
    // ap2->AddFile(&img2);
    // cout << endl
    //      << "ap1: " << endl;
    // ap1->ShowAll();
    // cout << endl
    //      << "До присвоения ap2: " << endl;
    // ap2->ShowAll();
    // cout << endl;

    // ap2 = ap1; // Shared pointer решает проблему
    //            // доступа к одним данным из разных указателей
    //            // после присвоения доступны ap1 и ap2
    //            // Данные будут уничтожены при выходе из
    //            // последнего shared pointer'a
    //            // Shared pointer'ы считают количество ссылок
    //            // и если их количество = 1 данные зачищаются

    // cout << endl
    //      << "После присвоения" << endl
    //      << "ap1: " << endl;
    // ap1->ShowAll();
    // cout << endl
    //      << "ap2: " << endl;
    // ap2->ShowAll();
    // cout << endl;

    // ---------------------------------------------------------

    // ---------------------weak_ptr----------------------------

    // Weak pointer используется вместе с shared
    // Он не позволяет работать с методами напрямую
    // Для работы с данными используется метод .lock()
    // При этом если данные будут доступны из обоих
    // указателей

    // shared_ptr<FileArray> ap1(new FileArray);

    // weak_ptr<FileArray> ap2(ap1);

    // ap1->AddFile(&vid1);
    // ap1->AddFile(&vid2);
    // ap2.lock()->AddFile(&img1);
    // ap2.lock()->AddFile(&img2);
    // cout << endl
    //      << "ap1: " << endl;
    // ap1->ShowAll();
    // cout << endl
    //      << "ap2: " << endl;
    // ap2.lock()->ShowAll();
    // cout << endl;

    // ---------------------------------------------------------

    // ---------------------My_ptr------------------------------

    MyPtr<int> ptr1 = new int(5);
    MyPtr<int> ptr2(ptr1);

    cout << *ptr2 << endl;

    // ---------------------------------------------------------

    return 0;
}