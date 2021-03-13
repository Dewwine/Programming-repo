/**
 * @file main.c
 * @brief Файл з реалізацією і викликом функції.
 *
 * @author Babenko A.
 * @date 20-feb-2020
 * @version 1.0
 */

#include "list.h"
#include "data.h"

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
  srand(time(0));
  int N = count_lines("input.txt");
  printf("Elements in linked link: %d\n", N);
  
  list *p_begin = NULL;
  p_begin = create_list(N - 1);
  read_list_from_file(p_begin, "input.txt", N);

  int pick;
  int index;

  printf("Enter what you want to do?\nAdd struct[1]\tRemove struct[2]\tWrite list to file[3]\tFind by criterion[4]\tSort by criterion[5]\n");
  scanf("%d", &pick);

  switch (pick)
  {
  case 1:
    printf("\nEnter index for adding [1-%d]\n", N);
    scanf("%d", &index);
    add_to_list(&p_begin, index);
    output_list(p_begin, N + 1);
    break;
  case 2:
    printf("\nEnter index for removing [0-%d]\n", N - 1);
    scanf("%d", &index);
    remove_from_list(&p_begin, index);
    output_list(p_begin, N - 1);
    break;
  case 3:
    write_list_to_file(p_begin, "output.txt", N);
    break;
  case 4:
    find_list(p_begin, N);
    break;
  case 5:
    sort_by_criterion(&p_begin, N);
    output_list(p_begin, N);
    break;
  default:
    printf("You entered incorrect number.\n");
    break;
  }
  
}