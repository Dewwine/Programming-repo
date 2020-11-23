int func(int N, int arr[][N]) {
    int temp = 0;
    for (int i = 0; i < N; i++) {
        temp = arr[i][0];
        for (int j = 0; j < N; j++) {
            arr[i][j] = arr[i][j+1];
        }
        arr[i][N-1] = temp;
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int main()
{
    #define N 4
    int arr[N][N] = {
        {1, 2, 3, 6},
        {4, 5, 6, 6},
        {7, 8, 9, 6},
        {1, 2, 3, 4}
    };

    func(N, arr);
    return 0;
}