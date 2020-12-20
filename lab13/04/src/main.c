#include <string.h>

void func(char *, char *);

int main()
{
  char text[] = "8 asdasfda fqw9r112e4 12 asdas5";

  char *str = calloc(strlen(text), sizeof(char));
  strcpy(str, text);

  char *str_res = calloc(strlen(str), sizeof(char));

  func(str, str_res);

  free(str);
  free(str_res);

  return 0;
}

void func(char * str, char * str_res)
{
  for (int i = 0; *(str + i) != '\0'; i++)
  {
    if (isdigit(*(str+i))) {
      char *temp_str = calloc(strlen(str), sizeof(char));
      *(temp_str + 0) = *(str + i);
      *(temp_str + 1) = '\0';
      strcat(str_res, temp_str);
      free(temp_str);
    } else if (isdigit(*(str+i-1))) {
      strcat(str_res, " ");
    }
  }  

  printf("%s\n", str_res);
}