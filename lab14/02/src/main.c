/**
 * @file main.c
 * @brief Файл з реалізацією і викликом функції.
 *
 * @author Babenko A.
 * @date 19-dec-2020
 * @version 1.0
 */

#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#define N 1000

void tree(char *path, int root, double *mb_size, int counter);

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
  double mb = 0.0;
  double *mb_size = &mb;
  int counter = 0;

  char path[N] = "";
  scanf("%s", path);

  tree(path, 0, mb_size, counter);
  
  int temp = 0;
  if ((mb / 1000.0f) >= 1000)
  {
    mb /= 1000000.0f;
    printf("Size of the catalog is: %.2f mb\n", mb);
  } else {
    mb /= 1000.0f;
    printf("Size of the catalog is: %.2f kb\n", mb);
  }
  

  return 0;
}

void tree(char *path, int root, double *mb_size, int counter)
{
  char newPath[N];
  DIR *dir;
  FILE *fp;
  struct stat buff;
  struct dirent *dp;
  if (counter == 0)
  {
    fp = fopen(path, "r");
    fstat(fileno(fp), &buff);
    *mb_size += buff.st_size;
    fclose(fp);
    counter++;
  }
  
  if (((dir = opendir(path)) != NULL))
  {
    while (((dp = readdir(dir)) != NULL))
    {
      if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
      {
        // Construct new path from our base path
        strcpy(newPath, path);
        strcat(newPath, "/");
        strcat(newPath, dp->d_name);


        fp = fopen(newPath, "r");
        fstat(fileno(fp), &buff);
        *mb_size += buff.st_size;
        fclose(fp);

        tree(newPath, root + 2, mb_size, counter);
      } 
    }

  closedir(dir);
  }
}

