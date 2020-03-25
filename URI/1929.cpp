#include <stdio.h>

int is_triangle(int a,int b, int c)
{
    if (a<b+c && b<a+c && c<a+b)
        return 1;
    return 0;
}

int main()
{
    int a,b,c,d;
    while (scanf("%d %d %d %d",&a,&b,&c,&d) != EOF)
    {
        if (is_triangle(a,b,c)||is_triangle(a,b,d)||is_triangle(a,c,d)||is_triangle(b,c,d))
            printf("S\n");
        else
            printf("N\n");
    }
    return 0;
}