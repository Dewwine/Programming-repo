int wordsInStr(char[]);

int main()
{
    char str[] = "Hello world, asfqwf f   fqwfqwfqfw     fqwfqwf";
    printf("%d\n", wordsInStr(str));

    return 0;
}

int wordsInStr(char str[]) {
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

  return count;
}