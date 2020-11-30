/**
 * @file main.c
 * @brief Файл з реалізацією і викликом функції.
 *
 * @author Babenko A.
 * @date 29-nov-2020
 * @version 1.0
 */

/**
 * Перевірка на досконалість
 * 
 * Функція визначає чи є задане число досконалим (якщо воно дорівнює сумі своїх дільників)
 *	@param n число, яке буде перевірятись на досконалість
 *  @return Результат роботи функції (res) 
 */
int isPerfect(int);

/**
 * Головна функція
 * 
 * Послідовність дій:
 * - виклик функції isPerfect
 * @return успішний код виконання програми (0)
 */
int main()
{
    printf("%d\n", isPerfect(28));
	return 0;
}

int isPerfect(int n) {
    /* Объявляем переменные */
    int count = 0;
    int res = 0;
    int i = 1;

    /* Проверка, является ли число совершенным */
    for (i = 1; i <= n/2; i++)
    {
        if (n % i == 0)
        {
            count += i;
        }
    }


/*
    while (i < n)
    {
        if (n % i == 0)
        {
            count += i;
        }
        i++;
    }
*/

/*
    do
    {
        if (n % i == 0)
        {
            count += i;
        }
        i++;
    } while (i < n);
*/

    if (n == count)
    {
        res = 1;
    } else
    {
        res = 0;
    }

    return res;
}