int isLucky(int);

int main()
{    
    printf("%d\n", isLucky(102300));
	return 0;
}

int isLucky(int n) {
    // Объявляем переменные
    int x1 = 0, x2 = 0, i = 0;
    int res;

    // Вычисляем сумму последних 3х цифр
    for(i=0; i<3; i++)
    {
        x2 += n % 10; 
        n /= 10;
    }
    // Вычисляем сумму первых 3х цифр
    for(i=0; i<3; i++)
    {
        x1 += n % 10;
        n /= 10;
    }

/*
    while (i<3)
    {
        x2 += n % 10; 
        n /= 10;
        i++;
    }
    i = 0;
    while (i<3)
    {
        x1 += n % 10; 
        n /= 10;
        i++;
    }
*/
  
/*
    do
    {
        x2 += n % 10; 
        n /= 10;
        i++;
    } while (i<3);
    i = 0;
    do
    {
        x1 += n % 10; 
        n /= 10;
        i++;
    } while (i<3);
*/

    if (x1 == x2)
    {
        res = 1;
    } else
    {
        res = 0;
    }
    return res;
}