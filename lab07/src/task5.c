#include <stdio.h>
int sqrt(int);

int main()
{
    printf("%d\n", sqrt(144));
    return 0;
}

int sqrt(int num) {
    // Объявляем переменные
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
    return res;
};