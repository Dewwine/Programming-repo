/**
 * @file main.c
 * @brief Файл з реалізацією і викликом функції.
 *
 * @author Babenko A.
 * @date 29-nov-2020
 * @version 1.0
 */

/**
 * Кількість елементів масива
 */
const int N = 5;

/**
 * Заповнення масиву простими числами
 * 
 * Функція заповнює масив простими числами
 *	@param N Кількість елементів в масиві
 */
void fillSimple(int);

/**
 * Головна функція
 * 
 * Послідовність дій:
 * - виклик функції fillSimple
 * @return успішний код виконання програми (0)
 */
int main()
{
  fillSimple(N);
  return 0;
}

void fillSimple(int size)
{
  int arr[size];
  int stop = 0;
  int i = 0;
  int num = 2;

  while (stop < 1)
  {
    for (int j = 2; j <= num; j++)
    {
      if (num % j == 0)
      {
        if (num == j)
        {
          arr[i] = num;
          i++;
        }
        else
        {
          break;
        }
      }
    }
    num++;
    if (i == size)
    {
      stop++;
    }
  }

  for (int i = 0; i < size; i++)
  {
    printf("%d\t", arr[i]);
  }
}