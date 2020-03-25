#include <stdio.h>

int main()
{
    int n,val;
    while (scanf("%d",&n) != EOF)
    {
        val = n/365.0;
        printf("%d ano(s)\n",val);
        if (val>0)
            n %= 365;
        val = n/30.0;
        printf("%d mes(es)\n",val);
        if (val>0)
            n %= 30;
        printf("%d dia(s)\n",n);
    }
    return 0;
}