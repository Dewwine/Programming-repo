int fillSimple(int);

int main()
{
  #define toNum 3

  fillSimple(toNum);
  return 0;
}

int fillSimple(int size) {
  int arr[size];
  int count = 0;

  for (int i = 2; i <= size; i++)
  {
    for (int j = 2; j < i; j++)
    {
      if (i % j == 0)
      {
        count = 1;
        break;
      }
    }
    if (count == 0)
    {
      arr[i] = i;
      printf("%d\n", arr[i]);
    }
    count = 0;
  }
  return 0;
}