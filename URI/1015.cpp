#include <stdio.h>
#include <math.h>

main()
{
    float x1,y1,x2,y2,distancia;
    scanf("%f %f %f %f",&x1,&y1,&x2,&y2);
    distancia = sqrt (pow(x2-x1,2)+pow(y2-y1,2));
    printf("%.4f\n",distancia);
}
