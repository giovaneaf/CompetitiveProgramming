#include <stdio.h>

int main()
{
    double A,B;
    double med;
    while(scanf("%lf %lf",&A,&B) != EOF)
    {
        med = A*0.3181817 + B*0.6818183;
        printf("MEDIA = %.5lf\n",med);
    }
    return 0;
}
