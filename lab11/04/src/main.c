void fill(int **, int);
void func(int **, int *, int);
void print(int **, int *, int);

int main()
{
  srand(time(0));
  int N = 4;
  int *res = (int *)calloc(N, sizeof(int));
  int **arr = (int **)calloc(N, sizeof(int *));
  for (int i = 0; i < N; i++)
  {
    *(arr + i) = (int *)calloc(N, sizeof(int));
  }

  fill(arr, N);
  func(arr, res, N);
  print(arr, res, N);

  free(arr);

  return 0;
}

void fill(int **arr, int N)
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      *(*(arr + i) + j) = rand() % 10 + 1;
    }
  }
}

void func(int ** arr, int * res, int N)
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (i == j) {
        *(res + i) = *(*(arr + i) + j);
      }
    }
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N - 1; j++)
    {
      if(*(res + j) > *(res + j + 1)) {        
        int temp = *(res + j);
        *(res + j) = *(res + j + 1);
        *(res + j + 1) = temp; 
      }
    }
  }
}

void print(int ** arr, int * res, int N)
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      printf("%d\t", *(*(arr + i) + j));
    }
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < N; i++)
  {
    printf("%d\t", *(res + i));
  }
}