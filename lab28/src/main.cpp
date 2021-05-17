#include "Array.h"

int main()
{
    Array a;
    int **arrays;
    int *res_arr;

    arrays = a.ReadFile("input.txt");
    res_arr = a.SumArray(arrays);
    a.WriteOut("output.txt", res_arr);

    a.FreeMemory(arrays);
    return 0;
}