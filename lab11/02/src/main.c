#include <stdarg.h>

void fill(int *, int, ...);
void maxSum(int *, int *, int);
void print(int *, int *, int);

int main()
{
  srand(time(0));
  int N = 13;
  int *arr = (int *)calloc(N, sizeof(int));
  int *res = (int *)calloc(N, sizeof(int));

  fill(arr, N, 3, 3, 3, 3, -1, 5, 5, 5, -2, 7, 7, 7, -3);
  maxSum(arr, res, N);
  print(arr, res, N);

  free(arr);

  return 0;
}

void fill(int *arr, int N, ...)
{
  va_list args;
  va_start(args, N);
  for (int i = 0; i < N; i++)
  {
    *(arr + i) = va_arg(args, int);
  }
  va_end(args);
}

void maxSum(int *arr, int *res, int N)
{
  int sum = 0;
  int maxSum = 0;
  int x = 0;
  int j = 0;

  for (int i = 0; i < N; i++)
  {
    if (*(arr + i) >= 0)
    {
      for (j; *(arr + j) >= 0; j++)
      {
        sum += *(arr + j);
        if (j >= N - 1)
        {
          // sum = 0;
          break;
        }
      }
      if (sum > maxSum && x == 0)
      {
        for (int k = 0; k < N; k++)
        {
          *(res + k) = 0;
        }
      }
      if (sum >= maxSum)
      {
        *(res + x) = *(arr + i);
      }
      x++;
    }
    else
    {
      x = 0;
      if (sum > maxSum)
      {
        maxSum = sum;
      }
      sum = 0;
      j++;
    }
  }  
}

void print(int *arr, int *res, int N)
{
  for (int i = 0; i < N; i++)
  {
    printf("%d\t", *(arr + i));
  }
    printf("\n");
  for (int i = 0; i < N; i++)
  {
    printf("%d\t", *(res + i));
  }
} 