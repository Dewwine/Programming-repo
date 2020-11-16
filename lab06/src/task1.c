int main()
{
// Задаем размер массива символов
#define size 15
  // Задаем заполнитель
  char zap = '_';
  // Задаем массив символов
  char str[size] = "Ivanov        ";
  // Задаем переменные для записи количества пробелов, и символов
  int count_spaces = 0;
  int count_spaces_before_chars = 0;
  int count_chars = 0;

  // Меняем пробелы на заполнитель и считаем кол-во пробелов и символов
  for (int i = 0; i < size - 1; i++)
  {
    if (str[i] == ' ')
    {
      str[i] = zap;
      count_spaces++;
    }
    else
    {
      count_chars++;
    }
  }

  // Считаем кол-во пробелов перед символами
  for (int i = 0; i < size - 1; i++)
  {
    if (str[i] == zap)
    {
      count_spaces_before_chars++;
    }
    else
    {
      break;
    }
  }

  // Сдвигаем слово влево, есои пробелы перед словом
  for (int i = 0; i < count_spaces_before_chars; i++)
  {
    for (int j = 0; j < size - 2; j++)
    {
      str[j] = str[j + 1];
    }
    str[size - 2 - i] = zap;
  }

  // Сдвигаем слово на количество пробелов делённое на 2
  for (int i = 0; i < count_spaces / 2; i++)
  {
    for (int j = size - 3; j >= 0; j--)
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

  return 0;
}