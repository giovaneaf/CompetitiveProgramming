#include <stdio.h>

diagonal(X1,Y1,X2,Y2)
{
    int x1, y1;
    for(x1 = X1 + 1, y1 = Y1 + 1; x1 <= 8 && y1 <= 8; x1++, y1++)
        if (x1==X2 && y1 == Y2)
            return 1;
    for (x1 = X1 + 1, y1 = Y1 - 1; x1 <= 8 && y1 <= 8; x1++, y1--)
        if (x1==X2 && y1 == Y2)
            return 1;
    for(x1 = X1 - 1, y1 = Y1 - 1; x1 >= 1 && y1 >= 1; x1--, y1--)
        if (x1==X2 && y1 == Y2)
            return 1;
    for(x1 = X1 - 1, y1 = Y1 + 1; x1 >= 1 && y1 >= 1; x1--, y1++)
        if (x1==X2 && y1 == Y2)
            return 1;
    return 0;
}

nro_min(X1,Y1,X2,Y2)
{
    if(X1 == X2 && Y1 == Y2)
        return 0;
    if (X1 == X2 || Y1 == Y2 || diagonal(X1,Y1,X2,Y2))
        return 1;
    return 2;
}

int main()
{
    int X1,Y1,X2,Y2;
    while (X1!=0 || Y1!=0 || X2!=0 || Y2!=0)
    {
        scanf("%d %d %d %d",&X1,&Y1,&X2,&Y2);
        if (X1>=1 && X1<=8 && X2>=1 && X2<=8 && Y1>=1 && Y1<=8 && Y2>=1 && Y2<=8)
            printf("%d\n", nro_min(X1,Y1,X2,Y2));
    }
    return 0;
}
