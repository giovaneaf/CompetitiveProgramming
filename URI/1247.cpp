#include <stdio.h>
#include <math.h>

int main()
{
    int D,VF,VG;
    while (scanf("%d %d %d",&D,&VF,&VG) != EOF)
        if (VG>=(VF/12.0*sqrt(pow(D,2)+144)))
            printf("S\n");
        else
            printf("N\n");
    return 0;
}
