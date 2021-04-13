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

void read_list_from_file(DblLinkedList *list, char *filename)
{
    regex_t regex;

    /*
        ^[A-ZА-ЯЁ] - перша літера латиниця або кирилиця у верхньому регістрі
        ()|()+ - розподіл на 2 группи символів, або ліва частина, або права, + будь яка кількість символів
        [A-ZА-Яa-zа-яё0-9] - 1 група всі кириличні та латинські символи будь-якого регістру, а також цифри 
        ([,?!\\. ][^\\.,?! ]) - 2 підгрупа символів 
        [,?!\\. ] - розділові знаки
        [^\\.,?! ] - перевірка на повторення розділових знаків
    */
    int return_value = regcomp(&regex, "^[A-ZА-ЯЁ]([A-ZА-Яa-zа-яё0-9]|([,?!\\. ][^\\.,?! ]))+", REG_EXTENDED);

    char isVisible[20];
    char filename1[20];
    char access_r[20];
    char access_w[20];
    char access_e[20];
    char extension[20];

    FILE *fp = fopen(filename, "r");

    for (int i = 0; i < list->size; i++)
    {
        Node *tmp = (Node *)malloc(sizeof(Node));

        fscanf(fp, "%s", &isVisible);
        fscanf(fp, "%s", &filename1);
        fscanf(fp, "%f", &tmp->myfile.size);
        fscanf(fp, "%s", &access_r);
        fscanf(fp, "%s", &access_w);
        fscanf(fp, "%s", &access_e);
        fscanf(fp, "%s", &tmp->myfile.extension);

        tmp->myfile.isVisible = bool_input(isVisible);
        tmp->myfile.access.read = bool_input(access_r);
        tmp->myfile.access.write = bool_input(access_w);
        tmp->myfile.access.execute = bool_input(access_e);

        if (regexec(&regex, filename1, 0, NULL, 0) == 0)
            strcpy(tmp->myfile.filename, filename1);
        else
            printf("\nArea filename of node №%d doesn't match regex\n", i);

        tmp->next = NULL;
        if (list->head == NULL)
        {
            tmp->prev = NULL;
        }
        else
        {
            tmp->prev = list->tail;
        }

        if (list->tail)
        {
            list->tail->next = tmp;
        }
        list->tail = tmp;

        if (list->head == NULL)
        {
            list->head = tmp;
        }
    }

    fclose(fp);

    DEBUG;

    regfree(&regex);
}

void write_list_to_file(DblLinkedList *list, char *filename)
{

    FILE *fp = fopen(filename, "w");

    Node *p = list->head;

    for (int i = 0; i < list->size; i++)
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

    DEBUG;
}

void output_list(DblLinkedList *list)
{

    Node *tmp = list->head;

    for (int i = 0; i < list->size; i++)
    {
        printf("\n\n\n\n");

        printf("Visibility: %s\n", bool_output(tmp->myfile.isVisible));
        printf("Filename: %s\n", tmp->myfile.filename);
        printf("File size: %.3f kb\n", tmp->myfile.size);
        printf("Readable: %s\n", bool_output(tmp->myfile.access.read));
        printf("Writeable: %s\n", bool_output(tmp->myfile.access.write));
        printf("Executable: %s\n", bool_output(tmp->myfile.access.execute));
        printf("File extension: %s\n", tmp->myfile.extension);

        tmp = tmp->next;
    }

    DEBUG;
}

void output_node(Node *node)
{

    printf("\n\n\n\n");

    printf("Visibility: %s\n", bool_output(node->myfile.isVisible));
    printf("Filename: %s\n", node->myfile.filename);
    printf("File size: %.3f kb\n", node->myfile.size);
    printf("Readable: %s\n", bool_output(node->myfile.access.read));
    printf("Writeable: %s\n", bool_output(node->myfile.access.write));
    printf("Executable: %s\n", bool_output(node->myfile.access.execute));
    printf("File extension: %s\n", node->myfile.extension);

    DEBUG;
}

void find_list(DblLinkedList *list)
{

    Node *p = list->head;

    printf("\nPick criterion for searching: \nVisibility[1]                \nFilename[2]\nFile size[3]                            \nReadability[4]\nWriteability[5]                        \nExecuteability[6]\nFile extension[7]                         \nEnter yout number: ");
    int criterion = 0;
    scanf("%d", &criterion);

    char str[20];
    switch (criterion)
    {
    case 1:
        printf("\nEnter visibility parameter for searching: ");
        scanf("%s", str);
        for (int i = 0; i < list->size; i++)
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
        for (int i = 0; i < list->size; i++)
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
        for (int i = 0; i < list->size; i++)
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
        for (int i = 0; i < list->size; i++)
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
        for (int i = 0; i < list->size; i++)
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
        for (int i = 0; i < list->size; i++)
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
        for (int i = 0; i < list->size; i++)
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

    DEBUG;
}

Node *getNth(DblLinkedList *list, size_t index)
{

    Node *tmp = NULL;
    size_t i;

    if (index < list->size / 2)
    {
        i = 0;
        tmp = list->head;
        while (tmp && i < index)
        {
            tmp = tmp->next;
            i++;
        }
    }
    else
    {
        i = list->size - 1;
        tmp = list->tail;
        while (tmp && i > index)
        {
            tmp = tmp->prev;
            i--;
        }
    }

    DEBUG;

    return tmp;
}

void add_to_list(DblLinkedList *list, int index)
{

    Node *elm = NULL;
    Node *ins = (Node *)malloc(sizeof(Node));
    elm = getNth(list, index);

    ins->myfile.isVisible = random_bool();
    sprintf(ins->myfile.filename, "added file 1243");
    ins->myfile.size = random_float();
    ins->myfile.access.write = random_bool();
    ins->myfile.access.read = random_bool();
    ins->myfile.access.execute = random_bool();
    char ext_arr[10][5] = {"txt", "docx", "pdf", "mp3", "avi", "mp4", "mkv", "exe", "bat", "jar"};
    sprintf(ins->myfile.extension, ext_arr[randomer() - 1]);

    if (elm->prev == NULL)
    {
        ins->next = list->head;
        ins->prev = NULL;
        if (list->head)
        {
            list->head->prev = ins;
        }
        list->head = ins;
        if (list->tail == NULL)
        {
            list->tail = ins;
        }
    }
    else if (elm->next == NULL)
    {
        ins->next = NULL;
        ins->prev = list->tail;
        if (list->tail)
        {
            list->tail->next = ins;
        }
        list->tail = ins;

        if (list->head == NULL)
        {
            list->head = ins;
        }
    }
    else
    {
        ins->prev = elm->prev;
        ins->next = elm;
        if (elm->next)
        {
            ins->next->prev = ins;
        }
        if (elm->prev)
        {
            ins->prev->next = ins;
        }
        elm = ins;
    }

    list->size++;

    DEBUG;
}

void remove_from_list(DblLinkedList *list, int index)
{

    Node *elm = NULL;
    elm = getNth(list, index);

    if (elm->prev)
    {
        elm->prev->next = elm->next;
    }
    if (elm->next)
    {
        elm->next->prev = elm->prev;
    }

    if (!elm->prev)
    {
        list->head = elm->next;
    }
    if (!elm->next)
    {
        list->tail = elm->prev;
    }

    free(elm);

    list->size--;

    DEBUG;
}

void sort_by_criterion(DblLinkedList *list)
{

    int criterion = 0;
    printf("\nPick criterion for sorting: \nVisibility[1]                \nFilename[2]\nFile size[3]                            \nReadability[4]\nWriteability[5]                        \nExecuteability[6]\nFile extension[7]                         \nEnter yout number: ");
    scanf("%d", &criterion);

    Node *node = list->head;
    Node *n1, *n2, *n3, *n4;

    bool flag;

    while (node->next != NULL)
    {
        switch (criterion)
        {
        case 1:
        {
            flag = (node->myfile.isVisible) < (node->next->myfile.isVisible);
            break;
        }
        case 2:
        {
            flag = strcmp(node->myfile.filename, node->next->myfile.filename) > 0;
            break;
        }
        case 3:
        {
            flag = (node->myfile.size) > (node->next->myfile.size);
            break;
        }
        case 4:
        {
            flag = (node->myfile.access.read) < (node->next->myfile.access.read);
            break;
        }
        case 5:
        {
            flag = (node->myfile.access.write) < (node->next->myfile.access.write);
            break;
        }
        case 6:
        {
            flag = (node->myfile.access.execute) < (node->next->myfile.access.execute);
            break;
        }
        case 7:
        {
            flag = strcmp(node->myfile.extension, node->next->myfile.extension) > 0;
            break;
        }
        default:
            break;
        }

        if (flag)
        {
            n1 = node->prev;
            n2 = node;
            n3 = node->next;
            n4 = node->next->next;

            if (n1 == NULL)
                list->head = n3;
            else
                n1->next = n3;

            n3->next = n2;
            n2->next = n4;

            n3->prev = n1;
            n2->prev = n3;

            if (n4 != NULL)
                n4->prev = n2;

            if (n1 != NULL)
                node = n1;
        }
        else
            node = node->next;
    }

    DEBUG;
}

void output_format(DblLinkedList *list)
{
    Node *p = list->head;

    regex_t regex;
    /*
        .+ будь-яка кількість будь-якого символу
        \\s будь-який символ пробілу між символами
        .+ будь-яка кількість будь-якого символу
    */

    // ^[^ ]+ [^ ]+$  
    int return_value = regcomp(&regex, "^\\w+\\s\\w+$", REG_EXTENDED);

    for (int i = 0; i < list->size; i++)
        {
            if (regexec(&regex, p->myfile.filename, 0, NULL, 0) == 0)
            {
                output_node(p);
            }

            p = p->next;
        }
    regfree(&regex);
}