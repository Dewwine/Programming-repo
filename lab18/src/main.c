/**
 * @file main.c
 * @brief Файл з реалізацією і викликом функції.
 *
 * @author Babenko A.
 * @date 20-feb-2020
 * @version 1.0
 */

#include "lib.h"

/**
 * Головна функція
 * 
 * Послідовність дій:
 * - зчитування кількості строк у файлі
 * - ініціалізація масиву структур
 * - виклик функції read_from_file()
 * - виклик функції write_to_file_bin()
 * - виклик функції read_from_file_bin()
 * - виклик функції output()
 * - ініціалізація номеру структури для пошуку
 * - виклик функції find_struct()
 * @return успішний код виконання програми (0)
 */
int main()
{
  // char str1[] = "abrakadabra";
  // char *s1 = (char *)malloc(sizeof(char));
  // s1 = &str1;

  // char str2[] = "TEXT2";
  // char *s2 = (char *)malloc(sizeof(char));
  // s2 = &str2;
  
  // printf("%s\n", insert(s1, s2, 4));
  // printf("%s\n", reduce(s1, 4, 8));
  

  srand(time(0));
  int N = randomer();
  
  file *myFiles = calloc(N, sizeof(file));
  
  generation(myFiles, N);

  myFiles = add_struct(myFiles, N);

  output(myFiles, N + 1);
  printf("\nКоличество структур в массиве: %d\nПосле добавления стало: %d\n", N, N + 1);
  
  // myFiles = remove_struct(myFiles, N);

  // output(myFiles, N - 1);
  // printf("\nКоличество структур в массиве: %d\nПосле удаления стало: %d\n", N, N - 1);


  free(myFiles);
}