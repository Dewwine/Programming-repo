int main()
{
    // Объявляем переменные
    int p = 8, // система счисления 
        num = 5014, // 4-разрядное число
        
    // Находим степени числа, которе является системой счисления
        p2 = (p * p), 
        p3 = (p2 * p),

    // Находим все цифры числа num
        a1 = num % 10,
        a2 = num % 100 / 10,
        a3 = num % 1000 / 100,
        a4 = num % 10000 / 1000,
        res;
    
    // Считаем эквивалент числа num в десятичной системе и записываем в переменную 
    res = a4*p3 + a3*p2 + a2*p + a1;

	return 0;
}
