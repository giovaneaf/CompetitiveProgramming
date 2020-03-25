#include <cstdio>

int main()
{
    int x,y;
    while(true)
    {
        scanf("%d %d",&x,&y);
        if (x == 0 || y == 0)
            break;
        if (x > 0 && y > 0)
            printf("primeiro\n");
        else if (x > 0 && y < 0)
            printf("quarto\n");
        else if (y > 0 && x < 0)
            printf("segundo\n");
        else
            printf("terceiro\n");
    }
    return 0;
}