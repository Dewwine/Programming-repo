#include <string.h>

void func(char *, char *, double *);
void print(char *, double *);

int main()
{
  char text[] = "aaabbbcc";
  char *str = calloc((strlen(text) + 1), sizeof(char));
  strcpy(str, text);

  char *str_res = calloc(strlen(str) + 1, sizeof(char));
  double *res = calloc(strlen(str) + 1, sizeof(double));

  func(str, str_res, res);
  print(str_res, res);

  free(str);
  free(str_res);
  free(res);
  return 0;
}

void func(char *str, char *str_res, double *res)
{
  int i, j;
  int count = 0;

  for (j = i = 0; *(str+i) != '\0'; i++)
  {
    if (!strchr(str_res, *(str+i)))
    {
      *(str_res+j) = *(str+i);
      j = j + 1;
    }
  }

  for (int i = 0; i < strlen(str_res); i++)
  {
    char *p_string = str;
    for (int j = 0; (p_string = strchr(p_string, *(str_res + i))) != NULL; j++)
    {
      count++;
      p_string++;
    }
    *(res + i) = (double)count / strlen(str);
    count = 0;
  }
}

void print(char *str_res, double *res)
{
  for (int i = 0; *(str_res + i) != '\0'; i++)
  {
    printf("%c  \t", *(str_res + i));
    printf("%f ", *(res + i));
    printf("\n");
  }
}