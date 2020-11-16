int main()
{
    #define N 3
    int temp = 0;
    int arr[N][N] = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9},
    };
    int res[N][N];
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            res[i][j] = 0;
            for(int k = 0; k < N; k++) {
                res[i][j] += arr[i][k] * arr[k][j];
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d\t", res[i][j]);
        }
        printf("\n");
    }

    return 0;
}