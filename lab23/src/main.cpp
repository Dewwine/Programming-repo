/**
 * @file main.cpp
 * @brief Файл з викликом методів.
 *
 * @author Babenko A.
 * @date 15-apr-2021
 * @version 1.0
 */

#include <Darray.hpp>

int main()
{
    srand(time(0));
    int N;
    printf("\nEnter count of elements in array\n");
    scanf("%d", &N);

    Darray arr(N);

    int isExit = 1;
    int pick;
    int index;
    int count;

    while (isExit)
    {
        printf("Enter what you want to do?\nAdd element[1]\tRemove element[2]\tFind file > 50 kb[3]\tShow all elements[4]\tGet element by index[5]\tExit[6]\n");
        scanf("%d", &pick);

        switch (pick)
        {
        case 1:
            arr.AddFile(new File(true, rand() % 100 + 1, "file", new Permission(true, true, false), "txt"));
            count++;
            arr.ShowAll();
            break;
        case 2:
            printf("\nEnter index for removing\n");
            scanf("%d", &index);
            arr.RemoveFile(index);
            arr.ShowAll();
            break;
        case 3:
            arr.PickBySize();
            break;
        case 4:
            arr.ShowAll();
            break;
        case 5:
            printf("\nEnter index for getting\n");
            scanf("%d", &index);
            arr.GetFile(index);
            break;
        case 6:
            isExit = 0;
            break;
        default:
            printf("You entered incorrect number.\n");
            break;
        }
    }

    return 0;
}