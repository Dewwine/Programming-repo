int main()
{
    // Объявляем переменные
    float k = 3,
          m = 2,
          n = 1,
          temp;

// Сравнение k и m 
    if (k > m) 
    {
        temp = k;
        k = m;
        m = temp;
    }
// Сравнение m и n
    if (m > n)
    {
        temp = m;
        m = n;
        n = temp;
    }
/* Повторное сравнение k и m, 
если m и n были поменялись местами */
    if (k > m)
    {
        temp = k;
        k = m;
        m = temp;
    }
    
    
    

	return 0;
}
