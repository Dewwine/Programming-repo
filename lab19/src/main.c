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
 * - виклик функції createDblLinkedList()
 * - виклик функції read_list_from_file()
 * - виклик функції output_list()
 * - виклик функції обраної користувачем
 * @return успішний код виконання програми (0)
 */
int main()
{
  srand(time(0));
  int N = count_lines("input.txt");
  printf("Elements in linked link: %d\n", N);

  DblLinkedList *list = NULL;
  list = createDblLinkedList();
  list->size = N;
  read_list_from_file(list, "input.txt");
  output_list(list);

  int pick;
  int index;

  printf("Enter what you want to do?\nAdd struct[1]\tRemove struct[2]\tWrite list to file[3]\tFind by criterion[4]\tSort by criterion[5]\n");
  scanf("%d", &pick);

  switch (pick)
  {
  case 1:
    printf("\nEnter index for adding [0-%d]\n", N);
    scanf("%d", &index);
    add_to_list(list, index);
    output_list(list);
    break;
  case 2:
    printf("\nEnter index for removing [0-%d]\n", N - 1);
    scanf("%d", &index);
    remove_from_list(list, index);
    output_list(list);
    break;
  case 3:
    write_list_to_file(list, "output.txt");
    break;
  case 4:
    find_list(list);
    break;
  case 5:
    sort_by_criterion(list);
    output_list(list);
    break;
  default:
    printf("You entered incorrect number.\n");
    break;
  }

  return 0;
}