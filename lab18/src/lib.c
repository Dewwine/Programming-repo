/**
 * @file lib.c
 * @brief Файл з реалізацією функцій оперування файлами
 *
 * @author Babenko A.
 * @date 20-feb-2020
 * @version 1.0
 */

#include "lib.h"

bool bool_input(char *str)
{
    return (strcmp(str, "true") == 0) ? true : false;
}

char *bool_output(bool b)
{
    return (b) ? ("true") : ("false");
}

void output(file *arr, int N)
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

int randomer()
{
    int num = rand() % 10 + 1;
    return num;
}

float random_float()
{
    float num = rand() % 10 + 1 + (double)((rand() % 1000)) / 1000;
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
        (arr + i)->isVisible = random_bool();
        sprintf((arr + i)->filename, "file №%d", i + 1);
        (arr + i)->size = random_float();
        (arr + i)->access.write = random_bool();
        (arr + i)->access.read = random_bool();
        (arr + i)->access.execute = random_bool();

        char ext_arr[10][5] = {"txt", "docx", "pdf", "mp3", "avi", "mp4", "mkv", "exe", "bat", "jar"};
        sprintf((arr + i)->extension, ext_arr[randomer() - 1]);
    }
}

char *insert(char *s1, char *s2, int pos)
{
    char *str = malloc(sizeof(char) * (strlen(s1) + strlen(s2) + 1));

    memcpy(str, s1, pos);
    memcpy(str + pos, s2, sizeof(char) * strlen(s2));
    memcpy(str + pos + strlen(s2), s1 + pos, strlen(s1 + pos));

    return str;
}

char *reduce(char *s1, int start, int end)
{
    char *str = malloc(sizeof(char) * (strlen(s1) + 1));

    memcpy(str, s1, start);
    memcpy(str + start, s1 + end + 1, strlen(s1) - end);

    return str;
}

file * add_struct(file *files, int N)
{
    files = (file *)realloc(files, sizeof(file) * (N + 1));

    printf("\nВведите номер структуры, которую нужно добавить(0-%d): \n", N);
    int to_add;
    scanf("%d", &to_add);
    for (int i = N; i > to_add; i--)
    {
        memcpy(files + i, files + i - 1, sizeof(file));
    }

    files[to_add].isVisible = random_bool();
    sprintf(files[to_add].filename, "add");
    files[to_add].size = random_float();
    files[to_add].access.write = random_bool();
    files[to_add].access.read = random_bool();
    files[to_add].access.execute = random_bool();
    char ext_arr[10][5] = {"txt", "docx", "pdf", "mp3", "avi", "mp4", "mkv", "exe", "bat", "jar"};
    sprintf(files[to_add].extension, ext_arr[randomer() - 1]);
    
    return files;
}

file * remove_struct(file *files, int N)
{
    printf("\nВведите номер структуры, которую нужно удалить(0-%d): \n", N - 1);
    int to_remove;
    scanf("%d", &to_remove);
    memset(files + to_remove, NULL, sizeof(file));
    for (int i = to_remove; i < N - 1; i++)
    {
        memcpy(files + i, files + i + 1, sizeof(file));
    }

    files = (file *)realloc(files, sizeof(file) * (N - 1));

    return files;
}