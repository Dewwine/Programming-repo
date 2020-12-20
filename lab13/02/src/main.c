#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int func(char *);

int main()
{

  char text[] = "Petrov, Ivanov, Sidorov, Sidorov, Ivanov, Ivanov";
  char *str = calloc((strlen(text) + 1), sizeof(char));

  strcpy(str, text);

  func(str);

  free(str);

  return 0;
}

int func(char *str)
{
  char **srt_str = (char **)calloc((strlen(str) + 1), sizeof(char *));
  for (int i = 0; i < strlen(str) + 1; i++)
  {
    *(srt_str + i) = (char *)calloc((strlen(str) + 1), sizeof(char));
  }

  char *temp_str = strtok(str, ", ");

  for (int i = 0; temp_str != NULL; i++)
  {
    strcat(*(srt_str + i), temp_str);
    temp_str = strtok(NULL, ", ");
  }
  free(temp_str);

  char *temp_res = calloc((strlen(str) + 1), sizeof(char));

  for (int i = 0; i < strlen(*srt_str) + 1; i++)
  {
    int isEqual = 0;
    for (int j = i; j < strlen(*srt_str) + 1; j++)
    {
      if (strcmp(*(srt_str + i), *(srt_str + j)) == 0 && i != j)
      {
        isEqual = 1;
      }
    }

    if (isEqual == 0)
    {
      strcat(temp_res, *(srt_str + i));
      if (i != strlen(*srt_str))
      {
        strcat(temp_res, ", ");
      }
    }
  }

  free(srt_str);

  char *res = calloc((strlen(str) + 1), sizeof(char));
  strncpy(res, temp_res, strlen(temp_res) - 2);

  printf("%s\n", res);

  free(temp_res);
  free(res);
}