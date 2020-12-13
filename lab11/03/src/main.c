#include <stdarg.h>


void fill(float *, int, ...);
void func(float *, float *, int);
void print(float *, int);

int main()
{
  int N = 7;
  float *arr = (float *)calloc(N, sizeof(float));
  float *res = (float *)calloc(N, sizeof(float));

  fill(arr, N, 1.1f, 1.2f, 1.3f, 1.1f, 1.5f, 1.6f, 1.7f);

  func(arr, res, N);

  print(arr, N);
  printf("\n");
  printf("\n");
  print(res, N);

  free(arr);

  return 0;
}

void fill(float *arr, int N, ...)
{
  va_list args;
  va_start(args, N);
  for (int i = 0; i < N; i++)
  {
    *(arr + i) = va_arg(args, double);
    // printf("%f\t", *(arr+i));
  }
  va_end(args);
}

void func(float *arr, float *res, int N)
{
  int x = 0;
  int count = 0;
  int maxCount = 0;
  int j = 0;
  int k = 0;
  int temp = 0;
  
  for (int i = 0; i < N; i++) 
  {    
    for (temp; *(arr + temp + 1) > *(arr + temp); temp++)
    {
      count++;
    }
    if (*(arr + i + 1) > *(arr + i)) 
    {
      if ((count >= maxCount))
      {
        if ((count >= maxCount) && (k < temp))
        {
          for (int r = 0; r < N; r++)
          {
            *(res + r) = 0;
          }
        }
        
        for (k; k <= temp; k++)
        {
          *(res + x) = *(arr + k);
          x++;
        }
      }

    } else {
      if (temp == k)
      {
        temp++;
        k++;
      }
    
      if (count > maxCount) 
      {
        maxCount = count;
        temp = temp + 1;
        count = 0;
        x = 0;
      }
    }
  }
}

void print(float *array, int N)
{
  for (int i = 0; i < N; i++)
  {
    printf("%f\t", *(array + i));
  }
} 