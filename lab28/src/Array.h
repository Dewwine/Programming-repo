#include "stdio.h"
#include <string>
#include "stdlib.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>

using namespace std;

class Array
{
    int size;
    int *CreateArray(int n);

public:
    int **ReadFile(string filename);

    int *SumArray(int **arrays);
    // int *AverageArray(int **arrays);
    void WriteOut(string filename, int *res_arr);
    void FreeMemory(int **arr);
};