/**
 * @file Permission.hpp
 * @brief Файл з прототипами методів оперування класом
 *
 * @author Babenko A.
 * @date 15-apr-2020
 * @version 1.0
 */

#ifndef _Permission_
#define _Permission_

#include <lib.h>

/**
 * Структура <Доступи> 
*/
struct Permission
{
    Permission();
    Permission(bool read, bool write, bool execute);

    bool read_;
    bool write_;
    bool execute_;
};

#endif