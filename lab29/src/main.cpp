#include "Array.h"
#include "Class.h"
#include "Class1.h"

int main()
{
    srand(time(0));
    /*   cout<<"----------------------------------------Работа с простыми числами типа  int----------------------------------------"<<endl;
    Array<int> in;
    for(int i=0;i<10;i++)
        in.AddEl(rand()%10);
    cout<<"Массив заполнен"<<endl;
    in.PrintArray();

    cout<<"\nУдаление 1 элемента"<<endl;
    in.DeleteEl(1);
    in.PrintArray();

    cout<<"\nМинимальный элемент в массиве: "<<in.FindMin()<<endl;

    cout<<"\nПоиск элемента `3`"<<endl;
    in.Finder(3);

    cout<<"\nСортировка массива"<<endl;
    in.SortArray();
    in.PrintArray();
   cout<<"----------------------------------------Работа с простыми числами типа  double----------------------------------------"<<endl;
    Array<double> db;
    for(int i=0;i<10;i++)
        db.AddEl(rand()%10+0.1);
    cout<<"Массив заполнен"<<endl;
    db.PrintArray();

    cout<<"\nУдаление 5 элемента"<<endl;
    db.DeleteEl(5);
    db.PrintArray();

    cout<<"\nМинимальный элемент в массиве: "<<db.FindMin()<<endl;

    cout<<"\nПоиск элемента `3.1`"<<endl;
    db.Finder(3.1);

    cout<<"\nСортировка массива"<<endl;
    db.SortArray();
    db.PrintArray();
 */
    cout << "----------------------------------------Работа с Классами----------------------------------------" << endl;
    Array<Class *> a;

    Class c(5.15);
    a.AddEl(&c);
    Class c1(3.15);
    a.AddEl(&c1);
    Class c2(2.1);
    a.AddEl(&c2);
    Class c3(9.99);
    a.AddEl(&c3);
    cout << "Массив заполнен" << endl;
    a.PrintArray();
    cout << "Добавление класса-наследника" << endl;
    Class1 cc(3.1, 2);
    a.AddEl(&cc);
    a.PrintArray();

    cout << "\nУдаление 2 элемента" << endl;
    a.DeleteEl(2);
    a.PrintArray();

    cout << "\nМинимальный элемент в массиве: " << a.FindMin() << endl;

    cout << "\nПоиск элемента `2.1`" << endl;
    a.Finder(2.1);

    cout << "\nСортировка массива" << endl;
    a.SortArray();
    a.PrintArray();

    return 0;
}