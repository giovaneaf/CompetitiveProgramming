#include <stdio.h>

int main()
{
    int a,b,c,d;
    while (scanf("%d %d %d %d",&a,&b,&c,&d) != EOF)
    {
        if (c>a && d>=b)
            printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n",c-a,d-b);
        else if (c>a && d<b)
            printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n",c-a-1,60-b+d);
        else if (c<a && d>=b)
            printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n",24-a+c,d-b);
        else if (c<a && d<b)
            printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n",24-a+c-1,60-b+d);
        else if (d>=b)
            printf("O JOGO DUROU 24 HORA(S) E %d MINUTO(S)\n",d-b);
        else
            printf("O JOGO DUROU 23 HORA(S) E %d MINUTO(S)\n",60-b+d);
    }
    return 0;
}