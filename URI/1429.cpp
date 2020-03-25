#include <stdio.h>
#include <string.h>

int factorial(x)
{
    int i,soma;
    for (i=2,soma=1;i<=x;i++)
        soma *= i;
    return soma;
}

int main()
{
    char number[6];
    int decimal,i,j;
    while (scanf("%s",number) != EOF)
    {
        if (number[0] == '0' && strlen(number) == 1)
            break;
        for (i=1,j=strlen(number),decimal=0;i<=strlen(number);i++,j--)
            decimal += (number[j-1]-48)*factorial(i);
        printf("%d\n",decimal);
    }
    return 0;
}