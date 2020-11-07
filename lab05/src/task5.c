#include <stdio.h>
int main()
{
    // Объявляем переменные
    int num = 144;
    int i = 1;
    int res;

    // Перебор квадратов чисел от 1 до num тех пор пока не совпадёт с числом
    for (i = 1; i < num; i++)
    {
        res = i * i;
            if (res == num)
            {
                res = i;
                break;
            } else
            {
                res = 0;
            }
    }


/*
    while (i < num)
    {
        res = i * i;
            if (res == num)
            {
                res = i;
                break;
            } else
            {
                res = 0;
            }
    i++;
    }
*/

/*
    do
    {
        res = i * i;
            if (res == num)
            {
                res = i;
                break;
            } else
            {
                res = 0;
            }
    i++;
    } while (i < num);
*/

    return 0;
}
