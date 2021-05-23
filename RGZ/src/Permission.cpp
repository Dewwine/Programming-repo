/**
 * @file Darray.cpp
 * @brief Файл з реалізацією методів оперування класом
 *
 * @author Babenko A.
 * @date 15-apr-2020
 * @version 1.0
 */

#include <Permission.h>

Permission::Permission()
{
    this->read_ = false;
    this->write_ = false;
    this->execute_ = false;
}

Permission::Permission(bool read, bool write, bool execute)
{
    this->read_ = read;
    this->write_ = write;
    this->execute_ = execute;
}

// Permission::Permission(struct Permission *permission)
// {
//     this->read_ = permission->read_;
//     this->write_ = permission->write_;
//     this->execute_ = permission->execute_;
// }