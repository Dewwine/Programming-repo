int main()
{
    // Задаём трёхзначное число
    int num = 123;
    // Получаем разряд чисел
    int f = (((num%100)%10)*100),
    // Получаем разряд десятков 
        s = (((num%100)/10)*10),
    // Получаем разряд сотен 
        t = (num/100),
    // Объявляем переменную для записи результата
        res;
    // Получаем число и записываем в переменную
    res = f+s+t;

	return 0;
}
