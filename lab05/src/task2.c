int main()
{
    // Объявляем число и переменную для результата
    int n = 5;
    int res = 0;

    // Проходим по циклу от 2 до n
    for (int i = 2; i <= n; i++)
    {
        // Если у числа есть делитель res + 1
        if (n % i == 0)
        {
            res += 1;
        }
    }


/*
    int i = 2;
    while (i <= n)
    {
        if (n % i == 0)
        {
            res += 1;
        }
        i++;
    }
*/

/*
    int i = 2;
    do {
        if (n % i == 0)
        {
            res += 1;
        }
        i++;
    } while (i <= n);
*/


    // Если кол-во делителей больше одного, res = 0 (не простое), иначе простое
    if (res > 1) 
    {
        res = 0;
    }

	return 0;
}
