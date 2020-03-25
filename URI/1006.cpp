#include <stdio.h>

main()
{
    double A,B,C,media;
    scanf("%lf %lf %lf",&A,&B,&C);
    media = (A*2+B*3+C*5)/10;
    printf("MEDIA = %.1lf\n",media);
}