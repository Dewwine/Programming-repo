int main()
{
    // Задаем 3х-значное число 
    int x = 123;
    // Находим первую цифру
    float af = x / 100,
    // Находим последнюю цифру
          al = x % 10,
    // Находим во сколько раз первая цифра больше последней 
          y = af / al;
    // Обрезаем ко второму знаку после запятой
    y *= 100;      
    int y1 = y;
    float res = y1/100.0f;
	
    return 0;
}