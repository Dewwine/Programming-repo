void fill(int *, int);
void repeat(int *, int);
void print(int *, int);

int main()
{
  srand(time(0));
  int N = 5;
  int * arr = (int*)calloc(N, sizeof(int));

  fill(arr, N);
  print(arr, N);
  printf("\n");
  repeat(arr, N);
  
  free(arr);

  return 0;
}

void fill(int * arr, int N) {
  for (int i = 0; i < N; i++)
  {
    *(arr + i) = rand() % 10 + 1;
  }
}

void repeat(int * arr, int N) {
  int count = 1;
  int x = 0;
  int * res = (int*)calloc(N * 2, sizeof(int));

  for (int i = 0; i < N; i++) {
    for (int j = i+1; j < N; j++) {
      if (*(arr + i) == *(arr + j)) {
        *(res + x) = *(arr + j);
        count++;
        *(arr + j) = 0;
      }
      
    }
    if (*(res + x) != 0) {
      *(res + x + 1) = count;
      x += 2;
    }
    count = 1;
  }
  
  for (int i = 0; *(res + i) != 0; i++)
  {
    printf("%d\t", *(res + i));
  }
}

void print(int * arr, int N) {
  for (int i = 0; i < N; i++)
  {
    printf("%d\t", *(arr + i));
  }
}