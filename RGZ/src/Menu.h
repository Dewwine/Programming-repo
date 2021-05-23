/**
 * @file Menu.h
 * @brief Файл з прототипами методів оперування класом
 *
 * @author Babenko A.
 * @date 15-apr-2020
 * @version 1.0
 */

#ifndef _Menu_
#define _Menu_

#include <Controller.h>

/**
 * Класс меню
*/
class Menu
{
private:
  Controller files;

public:
  ~Menu();

  void start();
};

#endif