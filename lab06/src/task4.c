int main()
{
    char str[] = "Hello world, asfqwf I    fqwfqwfqfw     fqwfqwf";
    
    int i, 
        count = 0, 
        isWord = 0;
    
    for (i = 0; str[i] != '\0'; i++) 
    {
        if (str[i] != ' ' && isWord == 0) 
        {
            count += 1;
            isWord = 1;
        } else if (str[i] == ' ') 
        {
            isWord = 0;
        }
    }

    printf("%d", count);
}