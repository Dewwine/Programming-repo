int main()
{
    // Объявляем переменные
    int n = 28;
    int count = 0;
    int res = 0;
    int i = 1;

    // Проверка, является ли число совершенным
    for (i = 1; i <= n/2; i++)
    {
        if (n % i == 0)
        {
            count += i;
        }
    }


/*
    while (i < n)
    {
        if (n % i == 0)
        {
            count += i;
        }
        i++;
    }
*/

/*
    do
    {
        if (n % i == 0)
        {
            count += i;
        }
        i++;
    } while (i < n);
*/


    if (n == count)
    {
        res = 1;
    } else
    {
        res = 0;
    }

	return 0;
}
