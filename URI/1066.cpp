#include <stdio.h>

int main()
{
    int i,a,npos,nn,npar,ni;
    npos=nn=npar=ni=0;
    for (i=0;i<5;i++)
    {
        scanf("%d",&a);
        if (a%2)
            ni++;
        else
            npar++;
        if (a>0)
            npos++;
        else if (a<0)
            nn++;
    }
    printf("%d valor(es) par(es)\n",npar);
    printf("%d valor(es) impar(es)\n",ni);
    printf("%d valor(es) positivo(s)\n",npos);
    printf("%d valor(es) negativo(s)\n",nn);
    return 0;
}