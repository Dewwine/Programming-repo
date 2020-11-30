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
 * Множення матриць
 * 
 * Функція множить матрицю саму на себе згідно з правилами їх множення
 *	@param N Кількість рядків і стовпців 
 *  @param arr[][N] масив для заповнювання
 */
void matrixMul(int N, int arr[][N]);

/**
 * Головна функція
 * 
 * Послідовність дій:
 * - ініціалізація масиву для заповнення
 * - виклик функції fill
 * - виклик функції matrixMul
 * @return успішний код виконання програми (0)
 */
int main()
{
    int arr[N][N];

    fill(N, arr);
    matrixMul(N, arr);
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

void matrixMul(int N, int arr[][N])
{
    int temp = 0;
    int res[N][N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < N; k++)
            {
                res[i][j] += arr[i][k] * arr[k][j];
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d\t", res[i][j]);
        }
        printf("\n");
    }
}