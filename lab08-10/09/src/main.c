/**
 * @file main.c
 * @brief Файл з реалізацією і викликом функції.
 *
 * @author Babenko A.
 * @date 29-nov-2020
 * @version 1.0
 */

/**
 * Розрахунок кількісті слів у рядку
 * 
 * Функція рахує і повертає кількість слів в рядку str
 *	@param str[] масив символів (рядок)
 * @return повернення результату роботи функції (count)
 */
int wordsInStr(char[]);

/**
 * Головна функція
 * 
 * Послідовність дій:
 * - ініціалізація та присвоєння масиву символів (рядка) 
 * - виклик функції wordsInStr
 * @return успішний код виконання програми (0)
 */
int main()
{
    char str[] = "Hello world, asfqwf f   fqwfqwfqfw     fqwfqwf";
    printf("%d\n", wordsInStr(str));

    return 0;
}

int wordsInStr(char str[])
{
    int i,
        count = 0,
        isWord = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ' && isWord == 0)
        {
            count += 1;
            isWord = 1;
        }
        else if (str[i] == ' ')
        {
            isWord = 0;
        }
    }

    return count;
}