/**
 * @file main.c
 * @brief Файл з реалізацією і викликом функції.
 *
 * @author Babenko A.
 * @date 19-dec-2020
 * @version 1.0
 */

#include <string.h>
#include <stdio.h>
#define N 100


void read_from_file(char* filename, char* result, int buf_size);

void write_to_file(char* filename, char* data);

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
  char text[N] = "";
  char input_file[N] = "";
  printf("Enter name of input file: ");
  scanf("%s", input_file);
  
  
  read_from_file(input_file, text, N);


  char *str = calloc((strlen(text) + 1), sizeof(char));
  strcpy(str, text);

  wordsInStr(str);


  free(str);

  return 0;
}

int wordsInStr(char *str)
{
  char output_file[N] = "";
  int count = 0;
  char **srt_str = (char **)calloc((strlen(str) + 1), sizeof(char *));
  for (int i = 0; i < strlen(str) + 1; i++)
  {
    *(srt_str + i) = (char *)calloc((strlen(str) + 1), sizeof(char));
  }

  char *str_tmp = calloc((strlen(str) + 1), sizeof(char));


  char *str1 = strtok(str, " ");

  for (int i = 0; str1 != NULL; i++)
  {
    count++;
    strcat(*(srt_str + i), str1);
    strcat(*(srt_str + i), " ");

    str1 = strtok(NULL, " ");
  }

  printf("Count of words: %d\n", count);

  free(str1);

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

  free(str_tmp);  

  *(str_tmp + 0) = count + '0';
  strcat(str_tmp, " ");
  printf("Words in alphabet order: ");
  for (int i = 1; i < strlen(str) - 0; i++)
  {
    strcat(str_tmp, *(srt_str + i));
    printf("%s", *(srt_str + i));
  }

  printf("\nEnter name of output file: ");
  scanf("%s", output_file); 
  write_to_file(output_file, str_tmp);
  
  free(srt_str);

  return count;
}

void read_from_file(char* filename, char* result, int buf_size) {
  FILE *file = fopen(filename, "r");
  fgets(result, buf_size, file);
  fclose(file);
}

void write_to_file(char* filename, char* data) {
  FILE *file = fopen(filename, "w");
  fputs(data, file);
  fclose(file);
}
