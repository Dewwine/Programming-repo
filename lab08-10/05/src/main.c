/**
 * @file main.c
 * @brief Файл з реалізацією і викликом функції.
 *
 * @author Babenko A.
 * @date 29-nov-2020
 * @version 1.0
 */

/**
 * Коріінь заданого числа
 * 
 * Функція без допомоги зовнішніх бібліотек, отримує коріінь заданого числа
 *	@param num число з якого буде добуватись корінь
 *  @return Результат роботи функції (res) 
 */
int sqrt(int);

/**
 * Головна функція
 * 
 * Послідовність дій:
 * - виклик функції sqrt
 * @return успішний код виконання програми (0)
 */
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