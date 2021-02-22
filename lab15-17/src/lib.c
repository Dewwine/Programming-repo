/**
 * @file lib.c
 * @brief Файл з реалізацією функцій оперування файлами
 *
 * @author Babenko A.
 * @date 20-feb-2020
 * @version 1.0
 */

#include "lib.h"

int count_lines(char *filename)
{
    int lines_count = 0;
    FILE *file;
    file = fopen(filename, "r");
    while (!feof(file))
    {
        if (fgetc(file) == '\n')
        {
            lines_count++;
        }
    }
    lines_count++;
    fclose(file);
    return lines_count;
}

bool bool_input(char *str)
{
    return (strcmp(str, "true") == 0) ? true : false;
}

char * bool_output(bool b)
{
    return (b) ? ("true") : ("false");
}

void read_from_file(file *arr, int N, char *filename)
{

    char isVisible[20];
    char access_r[20];
    char access_w[20];
    char access_e[20];

    FILE *fp;
    fp = fopen(filename, "r");
    for (int i = 0; i < N; i++)
    {
        fscanf(fp, "%s", &isVisible);
        fscanf(fp, "%s", &arr[i].filename);
        fscanf(fp, "%f", &arr[i].size);
        fscanf(fp, "%s", &access_r);
        fscanf(fp, "%s", &access_w);
        fscanf(fp, "%s", &access_e);
        fscanf(fp, "%s", &arr[i].extension);

        arr[i].isVisible = bool_input(isVisible);
        arr[i].access.read = bool_input(access_r);
        arr[i].access.write = bool_input(access_w);
        arr[i].access.execute = bool_input(access_e);
    }
    fclose(fp);
}

void write_to_file(char *buff, file *arr, int N)
{
    FILE *fp = fopen(buff, "w");

    for (int i = 0; i < N; i++)
    {
        fprintf(fp, "Visibility: %s\n", bool_output(arr[i].isVisible));
        fprintf(fp, "filename: %s\n", arr[i].filename);
        fprintf(fp, "File size: %f\n", arr[i].size);
        fprintf(fp, "Readable: %s\n", bool_output(arr[i].access.read));
        fprintf(fp, "Writeable: %s\n", bool_output(arr[i].access.write));
        fprintf(fp, "Executable: %s\n", bool_output(arr[i].access.execute));
        fprintf(fp, "File extension: %s\n", arr[i].extension);
        fprintf(fp, "\n\n\n\n");
    }

    fclose(fp);
}

void output( file *arr, int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("\n\n\n\n");

        printf("Visibility: %s\n", bool_output(arr[i].isVisible));
        printf("Filename: %s\n", arr[i].filename);
        printf("File size: %.3f kb\n", arr[i].size);
        printf("Readable: %s\n", bool_output(arr[i].access.read));
        printf("Writeable: %s\n", bool_output(arr[i].access.write));
        printf("Executable: %s\n", bool_output(arr[i].access.execute));
        printf("File extension: %s\n", arr[i].extension);
    }
}

void sort_by_criterion(file *arr, int N, int criterion) 
{
    switch (criterion)
    {
    case 1:
        for(int i = 0 ; i < N - 1; i++) { 
            for(int j = 0 ; j < N - i - 1 ; j++) {  
                if (arr[j].isVisible == false){
                    sorting(arr, N, j);
                }
            }
        }
        break;
    case 2:
        for(int i = 0 ; i < N - 1; i++) { 
            for(int j = 0 ; j < N - i - 1 ; j++) {  
                if (strcmp(arr[j].filename, arr[j+1].filename) > 0) {
                    sorting(arr, N, j);
                }
            }
        }
        break;
    case 3:
        for(int i = 0 ; i < N - 1; i++) { 
            for(int j = 0 ; j < N - i - 1 ; j++) {  
                if (arr[j].size < arr[j+1].size) {
                    sorting(arr, N, j);
                }
            }
        }
        break;
    case 4:
        for(int i = 0 ; i < N - 1; i++) { 
            for(int j = 0 ; j < N - i - 1 ; j++) {      
                if (arr[j].access.read == false){
                    sorting(arr, N, j);
                }
            }
        }
        break;
    case 5:
        for(int i = 0 ; i < N - 1; i++) { 
            for(int j = 0 ; j < N - i - 1 ; j++) {  
                if (arr[j].access.write == false){
                    sorting(arr, N, j);
                }
            }
        }
        break;
    case 6:
        for(int i = 0 ; i < N - 1; i++) { 
            for(int j = 0 ; j < N - i - 1 ; j++) {
                if (arr[j].access.execute == false){
                    sorting(arr, N, j);
                }
            }
        }
        break;
    case 7:
        for(int i = 0 ; i < N - 1; i++) { 
            for(int j = 0 ; j < N - i - 1 ; j++) {  
                if (strcmp(arr[j].extension, arr[j+1].extension) > 0) {
                    sorting(arr, N, j);
                }
            }
        }
        break;
    
    default:
        break;
    }
}

void sorting(file *arr, int N, int j) 
{
    file temp;

    temp.isVisible = arr[j].isVisible;
    arr[j].isVisible = arr[j+1].isVisible;
    arr[j+1].isVisible = temp.isVisible; 
    
    sprintf(temp.filename, arr[j].filename);
    sprintf(arr[j].filename, arr[j+1].filename);
    sprintf(arr[j+1].filename, temp.filename); 

    temp.size = arr[j].size;
    arr[j].size = arr[j+1].size;
    arr[j+1].size = temp.size; 

    temp.access.read = arr[j].access.read;
    arr[j].access.read = arr[j+1].access.read;
    arr[j+1].access.read = temp.access.read; 

    temp.access.write = arr[j].access.write;
    arr[j].access.write = arr[j+1].access.write;
    arr[j+1].access.write = temp.access.write; 

    temp.access.execute = arr[j].access.execute;
    arr[j].access.execute = arr[j+1].access.execute;
    arr[j+1].access.execute = temp.access.execute; 

    sprintf(temp.extension, arr[j].extension);
    sprintf(arr[j].extension, arr[j+1].extension);
    sprintf(arr[j+1].extension, temp.extension); 
}

int pick_by_size(file *arr, int N, int numberOfKilobytes)
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i].size >= numberOfKilobytes)
        {
            printf("\nName of file > %d kb: %s\n", numberOfKilobytes, arr[i].filename);
            count++;
        }
    }
    return count;
}

int random()
{
    int num = rand() % 10 + 1;
    return num;
}

float random_float()
{
    float num = rand() % 10 + 1 + (double)((rand() % 1000))/1000;
    return num;
}

bool random_bool()
{
    int num = rand() % 2;
    return (num == 1) ? true : false;
}

void generation(file *arr, int N)
{
    for (int i = 0; i < N; i++)
    {

        arr[i].isVisible = random_bool();
        sprintf(arr[i].filename, "file №%d", i + 1);
        arr[i].size = random_float();
        arr[i].access.write = random_bool();
        arr[i].access.read = random_bool();
        arr[i].access.execute = random_bool();
        
        char ext_arr[10][5] = {"txt", "docx", "pdf", "mp3", "avi", "mp4", "mkv", "exe", "bat", "jar"};
        sprintf(arr[i].extension, ext_arr[random() - 1]);
    }
}

void write_to_file_bin(char *buff, file *arr, int N) {
    FILE *fp = fopen(buff, "wb");
    fwrite(arr, sizeof(file), N, fp);
    fclose(fp);
}

void read_from_file_bin(char *buff, file *arr, int N) {
    FILE *fp = fopen(buff, "rb");
    for (int i = 0; i < N; i++)
    {
        fread(arr + i, sizeof(file), 1, fp);
    }
    fclose(fp);
}

void find_struct(char *buff, file *arr, int N, int number) {
    FILE *fp = fopen(buff, "rb");
    file founded_struct;    
    fseek(fp, number*sizeof(file), SEEK_SET);
    fread(&founded_struct, sizeof(file), 1, fp);
    fclose(fp);
    printf("\n\n\n\n");

    printf("Visibility: %s\n", bool_output(founded_struct.isVisible));
    printf("Filename: %s\n", founded_struct.filename);
    printf("File size: %.3f kb\n", founded_struct.size);
    printf("Readable: %s\n", bool_output(founded_struct.access.read));
    printf("Writeable: %s\n", bool_output(founded_struct.access.write));
    printf("Executable: %s\n", bool_output(founded_struct.access.execute));
    printf("File extension: %s\n", founded_struct.extension);
};
