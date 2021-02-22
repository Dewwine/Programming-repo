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
  /*-------------------------Задовільно-------------------------*/
  // int N = count_lines("input.txt");
  // file myFiles[N];
  // read_from_file(myFiles, N, "input.txt");
  // write_to_file("output.txt", myFiles, N);
  // output(myFiles, N);


  /*-------------------------Добре-------------------------*/
  // srand(time(0));
  // const int numberOfKilobytes = 50;

  // int N = random();
  // file myFiles[N];
  // generation(myFiles, N);
  // output(myFiles, N);
  // pick_by_size(myFiles, N, numberOfKilobytes);

  /*-------------------------Добре-------------------------*/
  // const int numberOfKilobytes = 50;

  // int N = count_lines("input.txt");
  // file myFiles[N];
  // read_from_file(myFiles, N, "input.txt");
  // output(myFiles, N);
  // pick_by_size(myFiles, N, numberOfKilobytes);

  /*-------------------------Добре-------------------------*/
  // srand(time(0));

  // int N = random();
  // file myFiles[N];
  // generation(myFiles, N);
  // printf("\nPick criterion for sorting: \nVisibility[1]                \nFilename[2]\nFile size[3]                            \nReadability[4]\nWriteability[5]                        \nExecuteability[6]\nFile extension[7]                         \nEnter yout number: ");
  // int criterion = 0;
  // scanf("%d", &criterion);
  // sort_by_criterion(myFiles, N, criterion);
  // output(myFiles, N);


  /*-------------------------Відмінно-------------------------*/
  int N = count_lines("input.txt");
  file myFiles[N];
  read_from_file(myFiles, N, "input.txt");
  write_to_file_bin("output.dat", myFiles, N);
  read_from_file_bin("output.dat", myFiles, N);
  output(myFiles, N);
  int find_structure = 0;
  printf("\nEnter number of searched struct: ");
  scanf("%d", &find_structure);
  find_struct("output.dat", myFiles, N, find_structure);

}