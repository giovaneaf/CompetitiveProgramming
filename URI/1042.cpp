#include <stdio.h>

int main()
{
    int a,b,c;
    while (scanf("%d %d %d",&a,&b,&c) != EOF)
    {
        if (a>b && a>c)
        {
            if (b>c)
                printf("%d\n%d\n%d\n",c,b,a);
            else
                printf("%d\n%d\n%d\n",b,c,a);
        }
        else if (b>c && b>a)
        {
            if (a>c)
                printf("%d\n%d\n%d\n",c,a,b);
            else
                printf("%d\n%d\n%d\n",a,c,b);
        }
        else
        {
            if (b>a)
                printf("%d\n%d\n%d\n",a,b,c);
            else
                printf("%d\n%d\n%d\n",b,a,c);
        }
        printf("\n");
        printf("%d\n%d\n%d\n",a,b,c);
    }
    return 0;
}