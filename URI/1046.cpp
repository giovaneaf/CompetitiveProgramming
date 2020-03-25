#include <stdio.h>

int main()
{
    int a,b;
    while (scanf("%d %d",&a,&b) != EOF)
    {
        if (a == b)
            printf("O JOGO DUROU 24 HORA(S)\n");
        else if (b>a)
            printf("O JOGO DUROU %d HORA(S)\n",b-a);
        else
            printf("O JOGO DUROU %d HORA(S)\n",24-a+b);
    }
    return 0;
}
