/**
 * @file main.c
 * @brief Файл з реалізацією і викликом функції.
 *
 * @author Babenko A.
 * @date 29-nov-2020
 * @version 1.0
 */

/**
 * Кількість рядків і стовпців у матриці
 */
const int N = 3;

/**
 * Заповнення масиву
 * 
 * Функція заповнює масив числами від 1 до N*N 
 *	@param N Кількість рядків і стовпців 
 *  @param arr[][N] масив для заповнювання
 */
void fill(int N, int arr[][N]);

/**
 * Зсув стовпця матриці
 * 
 * Функція виконує циклічне зрушення елементів рядків масиву в напрямку справа наліво
 *	@param N Кількість рядків і стовпців 
 *  @param arr[][N] масив для заповнювання
 */
void shift(int N, int arr[][N]);

/**
 * Головна функція
 * 
 * Послідовність дій:
 * - ініціалізація масиву для заповнення
 * - виклик функції fill
 * - виклик функції shift
 * @return успішний код виконання програми (0)
 */
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