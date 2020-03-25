#include <stdio.h>

int main()
{
    int N;
    while (scanf("%d",&N) != EOF)
    {
        if (N==1)
            printf("January\n");
        else if (N==2)
            printf("February\n");
        else if (N==3)
            printf("March\n");
        else if (N==4)
            printf("April\n");
        else if (N==5)
            printf("May\n");
        else if (N==6)
            printf("June\n");
        else if (N==7)
            printf("July\n");
        else if (N==8)
            printf("August\n");
        else if (N==9)
            printf("September\n");
        else if (N==10)
            printf("October\n");
        else if (N==11)
            printf("November\n");
        else
            printf("December\n");
    }
    return 0;
}