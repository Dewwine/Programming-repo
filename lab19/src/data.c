/**
 * @file data.c
 * @brief Файл з реалізацією функцій оперування файлами
 *
 * @author Babenko A.
 * @date 20-feb-2020
 * @version 1.0
 */

#include "list.h"
#include "data.h"

bool bool_input(char *str)
{
    return (strcmp(str, "true") == 0) ? true : false;
}

char *bool_output(bool b)
{
    return (b) ? ("true") : ("false");
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

int count_lines(char *filename)
{
    int lines_count = 0;
    FILE *fp;
    fp = fopen(filename, "r");
    while (!feof(fp))
    {
        if (fgetc(fp) == '\n')
        {
            lines_count++;
        }
    }
    lines_count++;
    fclose(fp);
    return lines_count;
}

void read_list_from_file(list *p_begin, char *filename, int N)
{
    char isVisible[20];
    char access_r[20];
    char access_w[20];
    char access_e[20];

    FILE *fp;
    fp = fopen(filename, "r");

    list *p = p_begin;

    for (int i = 0; i < N; i++)
    {
        fscanf(fp, "%s", &isVisible);
        fscanf(fp, "%s", &p->myfile.filename);
        fscanf(fp, "%f", &p->myfile.size);
        fscanf(fp, "%s", &access_r);
        fscanf(fp, "%s", &access_w);
        fscanf(fp, "%s", &access_e);
        fscanf(fp, "%s", &p->myfile.extension);

        p->myfile.isVisible = bool_input(isVisible);
        p->myfile.access.read = bool_input(access_r);
        p->myfile.access.write = bool_input(access_w);
        p->myfile.access.execute = bool_input(access_e);

        p = p->next;
    }

    fclose(fp);
}

void write_list_to_file(list *p_begin, char *filename, int N)
{
    FILE *fp = fopen(filename, "w");

    list *p = p_begin;

    for (int i = 0; i < N; i++)
    {
        fprintf(fp, "Visibility: %s\n", bool_output(p->myfile.isVisible));
        fprintf(fp, "filename: %s\n", p->myfile.filename);
        fprintf(fp, "File size: %f\n", p->myfile.size);
        fprintf(fp, "Readable: %s\n", bool_output(p->myfile.access.read));
        fprintf(fp, "Writeable: %s\n", bool_output(p->myfile.access.write));
        fprintf(fp, "Executable: %s\n", bool_output(p->myfile.access.execute));
        fprintf(fp, "File extension: %s\n", p->myfile.extension);
        fprintf(fp, "\n\n\n\n");

        p = p->next;
    }

    fclose(fp);

    printf("Successfully written\n");
}

void output_list(list *p_begin, int N)
{
    list *p = p_begin;

    for (int i = 0; i < N; i++)
    {
        printf("\n\n\n\n");

        printf("Visibility: %s\n", bool_output(p->myfile.isVisible));
        printf("Filename: %s\n", p->myfile.filename);
        printf("File size: %.3f kb\n", p->myfile.size);
        printf("Readable: %s\n", bool_output(p->myfile.access.read));
        printf("Writeable: %s\n", bool_output(p->myfile.access.write));
        printf("Executable: %s\n", bool_output(p->myfile.access.execute));
        printf("File extension: %s\n", p->myfile.extension);

        p = p->next;
    }
}

void output_node(list *p)
{
    printf("\n\n\n\n");

    printf("Visibility: %s\n", bool_output(p->myfile.isVisible));
    printf("Filename: %s\n", p->myfile.filename);
    printf("File size: %.3f kb\n", p->myfile.size);
    printf("Readable: %s\n", bool_output(p->myfile.access.read));
    printf("Writeable: %s\n", bool_output(p->myfile.access.write));
    printf("Executable: %s\n", bool_output(p->myfile.access.execute));
    printf("File extension: %s\n", p->myfile.extension);
}

void find_list(list *p_begin, int N)
{
    list *p = p_begin;

    printf("\nPick criterion for searching: \nVisibility[1]                \nFilename[2]\nFile size[3]                            \nReadability[4]\nWriteability[5]                        \nExecuteability[6]\nFile extension[7]                         \nEnter yout number: ");
    int criterion = 0;
    scanf("%d", &criterion);

    char str[20];
    switch (criterion)
    {
    case 1:
        printf("\nEnter visibility parameter for searching: ");
        scanf("%s", str);
        for (int i = 0; i < N; i++)
        {
            if (bool_input(str) == p->myfile.isVisible)
            {
                output_node(p);
            }

            p = p->next;
        }
        break;
    case 2:
        printf("\nEnter name of file for searching: ");
        scanf("%s", str);
        for (int i = 0; i < N; i++)
        {
            if (strcmp(str, p->myfile.filename) == 0)
            {
                output_node(p);
            }

            p = p->next;
        }
        break;
    case 3:
        printf("\nEnter size for searching: ");
        float number = 0.0f;
        scanf("%f", &number);
        for (int i = 0; i < N; i++)
        {
            if (number == p->myfile.size)
            {
                output_node(p);
            }

            p = p->next;
        }
        break;
    case 4:
        printf("\nEnter readability parameter for searching: ");
        scanf("%s", str);
        for (int i = 0; i < N; i++)
        {
            if (bool_input(str) == p->myfile.access.read)
            {
                output_node(p);
            }

            p = p->next;
        }
        break;
    case 5:
        printf("\nEnter writability parameter for searching: ");
        scanf("%s", str);
        for (int i = 0; i < N; i++)
        {
            if (bool_input(str) == p->myfile.access.write)
            {
                output_node(p);
            }

            p = p->next;
        }
        break;
    case 6:
        printf("\nEnter executability parameter for searching: ");
        scanf("%s", str);
        for (int i = 0; i < N; i++)
        {
            if (bool_input(str) == p->myfile.access.execute)
            {
                output_node(p);
            }

            p = p->next;
        }
        break;
    case 7:
        printf("\nEnter extension searching for searching: ");
        scanf("%s", str);
        for (int i = 0; i < N; i++)
        {
            if (strcmp(str, p->myfile.extension) == 0)
            {
                output_node(p);
            }

            p = p->next;
        }
        break;
    default:
        break;
    }
}

void push(list **p_begin)
{
    list *newNode = malloc(sizeof(list));

    newNode->myfile.isVisible = random_bool();
    sprintf(newNode->myfile.filename, "added file");
    newNode->myfile.size = random_float();
    newNode->myfile.access.write = random_bool();
    newNode->myfile.access.read = random_bool();
    newNode->myfile.access.execute = random_bool();
    char ext_arr[10][5] = {"txt", "docx", "pdf", "mp3", "avi", "mp4", "mkv", "exe", "bat", "jar"};
    sprintf(newNode->myfile.extension, ext_arr[randomer() - 1]);

    newNode->next = *p_begin;
    *p_begin = newNode;
}

void add_to_list(list **p_begin, int index)
{
    if (index == 0)
    {
        push(p_begin);
    }
    else
    {
        list *p = *p_begin;
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        push(&p->next);
    }
}

void remove_from_list(list **p_begin, int index)
{
    list *p = *p_begin;
    list *del_pos = NULL;

    if (index == 0)
    {
        del_pos = *p_begin;
        *p_begin = p->next;
        free(del_pos);
        return;
    }

    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
    }

    del_pos = p->next;
    p->next = p->next->next;
    free(del_pos);
}

void sort_by_criterion(list **p_begin, int N)
{
    int swapped, i;
    list *p;
    list *lp = NULL;

    /* Checking for empty list */
    if (p_begin == NULL)
        return;

    int criterion = 0;
    printf("\nPick criterion for sorting: \nVisibility[1]                \nFilename[2]\nFile size[3]                            \nReadability[4]\nWriteability[5]                        \nExecuteability[6]\nFile extension[7]                         \nEnter yout number: ");
    scanf("%d", &criterion);

    switch (criterion)
    {
    case 1:
        while (swapped)
        {
            swapped = 0;
            p = *p_begin;

            while (p->next != lp)
            {
                if (p->myfile.isVisible == false)
                {
                    if (p->next != NULL)
                    {
                        swap(p, p->next);
                        swapped = 1;
                    }
                }
                p = p->next;
            }
            lp = p;
        }
        break;
    case 2:
        while (swapped)
        {
            swapped = 0;
            p = *p_begin;

            while (p->next != lp)
            {
                if (strcmp(p->myfile.filename, p->next->myfile.filename) > 0)
                {
                    if (p->next != NULL)
                    {
                        swap(p, p->next);
                        swapped = 1;
                    }
                }
                p = p->next;
            }
            lp = p;
        }
        break;
    case 3:
        while (swapped)
        {
            swapped = 0;
            p = *p_begin;

            while (p->next != lp)
            {
                if (p->myfile.size > p->next->myfile.size)
                {
                    if (p->next != NULL)
                    {
                        swap(p, p->next);
                        swapped = 1;
                    }
                }
                p = p->next;
            }
            lp = p;
        }
        break;
    case 4:
        while (swapped)
        {
            swapped = 0;
            p = *p_begin;

            while (p->next != lp)
            {
                if (p->myfile.access.read == false)
                {
                    if (p->next != NULL)
                    {
                        swap(p, p->next);
                        swapped = 1;
                    }
                }
                p = p->next;
            }
            lp = p;
        }
        break;
    case 5:
        while (swapped)
        {
            swapped = 0;
            p = *p_begin;

            while (p->next != lp)
            {
                if (p->myfile.access.write == false)
                {
                    if (p->next != NULL)
                    {
                        swap(p, p->next);
                        swapped = 1;
                    }
                }
                p = p->next;
            }
            lp = p;
        }
        break;
    case 6:
        while (swapped)
        {
            swapped = 0;
            p = *p_begin;

            while (p->next != lp)
            {
                if (p->myfile.access.execute == false)
                {
                    if (p->next != NULL)
                    {
                        swap(p, p->next);
                        swapped = 1;
                    }
                }
                p = p->next;
            }
            lp = p;
        }
        break;
    case 7:
        while (swapped)
        {
            swapped = 0;
            p = *p_begin;

            while (p->next != lp)
            {
                if (strcmp(p->myfile.extension, p->next->myfile.extension) > 0)
                {
                    if (p->next != NULL)
                    {
                        swap(p, p->next);
                        swapped = 1;
                    }
                }
                p = p->next;
            }
            lp = p;
        }
        break;

    default:
        break;
    }
}

void swap(list *a, list *b)
{
    file temp = a->myfile;
    a->myfile = b->myfile;
    b->myfile = temp;
}
