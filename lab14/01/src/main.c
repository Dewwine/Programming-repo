/**
 * @file main.c
 * @brief Файл з реалізацією і викликом функції.
 *
 * @author Babenko A.
 * @date 12-feb-2020
 * @version 1.0
 */

#include <string.h>
#include <stdio.h>
#include <dirent.h>
#define N 1000

/**
 * Заповнення масиву числами
 * 
 * Функція, що виводить структуру файлів і каталогів
 *	@param path шлях до директорії
 *	@param root вкладеність директорії
 */
void tree(char *path, int root);

/**
 * Головна функція
 * 
 * Послідовність дій:
 * - ініціалізація строки для запису шляху до директорії
 * - зчитування шляху від користувача
 * - виклик функції tree()
 * @return успішний код виконання програми (0)
 */
int main()
{
  char path[N] = "";
  scanf("%s", path);

  tree(path, 0);

  return 0;
}

void tree(char *path, int root)
{
  char newPath[N];
  DIR *dir;
  struct dirent *dp;
  if ((dir = opendir(path)) != NULL)
  {
    while ((dp = readdir(dir)) != NULL)
    {
      if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
      {
        /* Вывод символов для отступа */
        for (int i = 0; i < root; i++)
        {
          if (i % 2 == 0 || i == 0)
            printf("│");
          else
            printf(" ");
        }

        printf("│──%s\n", dp->d_name);

        /* Создание нового пути из исходного */
        strcpy(newPath, path);
        strcat(newPath, "/");
        strcat(newPath, dp->d_name);

        tree(newPath, root + 2);
      }
    }

    closedir(dir);
  }
}