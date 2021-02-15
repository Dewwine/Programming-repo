#include <stdio.h>

/**
 * @file main.c
 * @brief Файл з реалізацією і викликом функції.
 *
 * @author Babenko A.
 * @date 12-feb-2020
 * @version 1.0
 */

/**
 * Заповнення масиву числами
 * 
 * Функція, що заповнює масив числами введенними користувачем
 *	@param arr масив чисел
 *	@param N кількість елементів масиву
 */
void fill(float *, int);

/**
 * Заповнення масиву числами що повторюються
 * 
 * Функція, що шукає числа які повторюються і кількість повторень
 *	@param arr заповнений масив чисел
 *	@param N кількість елементів масиву
 */
void repeat(float *, int);

/**
 * Виведення масиву на екран
 * 
 * Функція, що виводить масив
 *	@param arr заповнений масив чисел
 *	@param N кількість елементів масиву
 */
void print(float *, int);

/**
 * Головна функціяcd
 * 
 * Послідовність дій:
 * - Взаємодія з користувачем шляхом механізму введення/виведення
 * - задання кількості елементів масиву
 * - ініціалізація масиву
 * - виклик функції fill
 * - виклик функції repeat
 * @return успішний код виконання програми (0)
 */
int main()
{
  char surname[50] = "";
  puts("\nЛабораторна робота №12");
  write(1, "Взаємодія з користувачем шляхом механізму введення/виведення\n", 115);
  printf("\nEnter author's surname\n");
  gets(surname);
  printf("\nEnter first letter of author's name\n");

  char name = getc(stdin);
  printf("\nAuthor: %s %c\n", surname, name);
  
  printf("\nEnter 0 (start) or 1 (exit)\n");
  char isEnterCh;
  read(0, &isEnterCh, 1);
  int isEnter = isEnterCh - '0';

  if (isEnter != 0) {
    printf("You entered ");
    putc(isEnter + '0', stdout);
    printf(", program closed\n");
    exit(0);  
  }

  int N = 0;
  printf("\nEnter count of numbers\n");
  scanf("%d", &N);

  float * arr = (float*)calloc(N, sizeof(float));

  fill(arr, N);

  printf("\nInitial array: \t");
  print(arr, N);
  printf("\n");
  repeat(arr, N);

  free(arr);

  return 0;
}

void fill(float * arr, int N) {
  printf("Enter array of numbers\n");
  for (int i = 0; i < N; i++)
  {
    scanf("%f", &*(arr+i));
   }
}

void repeat(float * arr, int N) {
  int count = 1;
  int x = 0;
  float * res = (float*)calloc(N * 2, sizeof(float));

  for (int i = 0; i < N; i++) {
    for (int j = i+1; j < N; j++) {
      if (*(arr+ i) != ' ') {
        if (*(arr + i) == *(arr + j)) {
          *(res + x) = *(arr + j);
          count++;
          *(arr + j) = 0;
        }
      }
    }
    if (*(res + x) != 0) {
      *(res + x + 1) = count;
      x += 2;
    }
    count = 1;
  }
  
  printf("Resulting array: ");
  for (int i = 0; *(res + i) != 0; i++)
  {
    printf("%f\t", *(res + i));
  }
  free(res);
}

void print(float * arr, int N) {
  for (int i = 0; i < N; i++)
  {
    printf("%f\t", *(arr + i));
  }
} 