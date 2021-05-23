#include "File.h"

template <typename T>
class MyPtr
{
  T *ptr;
  int count;

public:
  MyPtr(T *ptr)
  {
    this->ptr = ptr;
    count = 1;
    cout << "\nВызвался конструктор" << endl;
  }

  MyPtr(const MyPtr &other)
  {
    this->ptr = other.ptr;
    this->count = other.count + 1;
    cout << "\nВызвался конструктор копирования" << endl;
  }

  ~MyPtr()
  {
    if (count == 1)
    {
      delete ptr;
      cout << "\nВызвался деструктор" << endl;
    }
    count--;
  }

  T &operator*()
  {
    return *ptr;
  }

  T &operator->()
  {
    return ptr;
  }
};