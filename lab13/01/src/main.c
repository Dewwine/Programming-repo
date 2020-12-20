/**
 * @file main.c
 * @brief Файл з реалізацією і викликом функції.
 *
 * @author Babenko A.
 * @date 19-dec-2020
 * @version 1.0
 */

#include <string.h>

/**
 * Розрахунок кількості слів у тексті
 * 
 * Функція, що рахує кількість слів у тексті без ітерації по кожному символу
 *	@param str строка (заданий текст)
 *  @return Кількість слів у строці (count) 
 */
int wordsInStr(char *);

/**
 * Головна функція
 * 
 * Послідовність дій:
 * - задання тексту
 * - виділення тексту під масив символів (строку)
 * - копіювання тексту до строки
 * - виклик функції wordsInStr()
 * - очищення пам'яті виділеної під строку
 * @return успішний код виконання програми (0)
 */
int main()
{
  char text[] = " count  words in this    string";
  char *str = calloc((strlen(text) + 1), sizeof(char));
  strcpy(str, text);

  wordsInStr(str);

  free(str);

  return 0;
}

int wordsInStr(char *str)
{
  int count = 0;
  char **srt_str = (char **)calloc((strlen(str) + 1), sizeof(char *));
  for (int i = 0; i < strlen(str) + 1; i++)
  {
    *(srt_str + i) = (char *)calloc((strlen(str) + 1), sizeof(char));
  }

  char *str1 = strtok(str, " ");

  for (int i = 0; str1 != NULL; i++)
  {
    count++;
    strcat(*(srt_str + i), str1);

    str1 = strtok(NULL, " ");
  }

  free(str1);

  printf("%d", count);
  printf("\n");

  char *str_tmp = calloc((strlen(str) + 1), sizeof(char));

  for (int i = 1; i < strlen(str); i++)
  {
    for (int j = 0; j < strlen(str) - i; j++)
    {
      if (strcmp(*(srt_str + j), *(srt_str + j + 1)) > 0)
      {
        strcpy(str_tmp, *(srt_str + j));
        strcpy(*(srt_str + j), *(srt_str + j + 1));
        strcpy(*(srt_str + j + 1), str_tmp);
      }
    }
  }

  for (int i = 1; i < strlen(str) - 0; i++)
  {
    printf("%s\n", *(srt_str + i));
  }

  free(str_tmp);
  free(srt_str);

  return count;
}