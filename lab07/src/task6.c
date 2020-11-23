char center(char str[]);

int main()
{
  char str[] = "Ivanov        ";
  
  center(str);
  return 0;
}

char center(char str[]) {
  // Задаем заполнитель
  char zap = '_';
  // Задаем переменные для записи количества пробелов, и пробелов перед словом
  int count_spaces = 0;
  int spaces_before = 0;
  int size = 0;

  // Вычисляем размер заданного массива
  for (int i = 0; str[i] != '\0'; i++) {
    size += 1;
  }

  // Меняем пробелы на заполнитель и считаем кол-во пробелов
  for (int i = 0; i < size; i++)
  {
    if (str[i] == ' ')
    {
      str[i] = zap;
      count_spaces++;
    }
  }

  // Считаем кол-во пробелов перед символами
  for (int i = 0; i < size; i++)
  {
    if (str[i] == zap)
    {
      spaces_before++;
    }
    else
    {
      break;
    }
  }

  // Сдвигаем слово влево, есои пробелы перед словом
  for (int i = 0; i < spaces_before; i++)
  {
    for (int j = 0; j < size - 1; j++)
    {
      str[j] = str[j + 1];
    }
    str[size - 1 - i] = zap;
  }

  // Сдвигаем слово на количество пробелов делённое на 2
  for (int i = 0; i < count_spaces / 2; i++)
  {
    for (int j = size - 2; j >= 0; j--)
    {
      str[j + 1] = str[j];
    }
  }

  // Заменяем на заполнитель первые символы кол-во которых равно количеству пробелов пополам 
  for (int i = 0; i < count_spaces / 2; i++)
  {
    str[i] = zap;
  }

  // Вывод для удобстава
  for (int i = 0; i < size; i++)
  {
    printf("%c\t", str[i]);
  }
  printf("\n");
  return 0;
}