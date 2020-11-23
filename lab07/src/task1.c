int nod(int, int);
int get_rand();

int main()
{
  srand(time(0));

  printf("%d\n", nod(6, get_rand()));
  return 0;
}

int nod(int a, int b)
{
  // Объявляем переменные для записи результата
  int res;
  int i = 1;

  // Запись младшего числа в переменную b
  if (a < b)
  {
    int x = a;
    a = b;
    b = x;
  }

  // Цикл прохождения от 1 до младшего числа
  for (i = 1; i <= b; i++)
  {
    // Если остаток от деления двух чисел == 0, записываем его в переменную
    if ((a % i) == 0 && (b % i) == 0)
    {
      res = i;
    }
  }

  /*
  while (i <= b)
  {
    if ((a % i) == 0 && (b % i) == 0) 
    {
      res = i;
    }
    i++;
  }
*/

  /*
  do {
    if ((a % i) == 0 && (b % i) == 0) 
    {
      res = i;
    }
    i++;
  } while (i <= b);
*/

  return res;
}

int get_rand() {
  return rand() % 10 + 1;
}