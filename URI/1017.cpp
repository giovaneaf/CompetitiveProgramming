#include <stdio.h>

int main()
{
    int A,B;
    while (scanf("%d %d",&A,&B) != EOF)
        printf("%.3lf\n",(double)B/12.0*A);
    return 0;
}
