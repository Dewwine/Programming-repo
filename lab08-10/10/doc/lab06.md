**2 Виконання роботи**

2.1 Створення файлу з вихідним кодом, написання коду і коментарів до нього

```C
const int N = 3;

void fill(int N, int arr[][N]);

void shift(int N, int arr[][N]);

int main()
{
    int arr[N][N];

    fill(N, arr);
    shift(N, arr);
    return 0;
}

void fill(int N, int arr[][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            arr[i][j] = i * N + j + 1;
        }
    }
}

void shift(int N, int arr[][N])
{
    int temp = 0;
    for (int i = 0; i < N; i++)
    {
        temp = arr[i][0];
        for (int j = 0; j < N; j++)
        {
            arr[i][j] = arr[i][j + 1];
        }
        arr[i][N - 1] = temp;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}
```

2.2 Компіляція проекту за допомогою команди “make clean prep compile”. Зображено на рис.1.

![](./assets/image1.png)

Рисунок 1 - компіляція проекту

2.3 Відкрито у відлагоднику nemiver виконуючий файл main.bin. Ставимо точку зупину, проходимо по файлу і бачимо зміну значення в масиві в момент проходження по циклу. Зображено на рис.2.

![](./assets/image2.png)

Рисунок 2 - файл у відлагоднику

2.4 Створення блок-схеми програми. Зображення блок-схеми на рис.3.

![](../../doc/assets/6_5.png)

Рисунок 3 - блок-схема

**Висковки**

Створено програму, що виконує циклічне зрушення елементів рядків масиву в напрямку справа наліво.