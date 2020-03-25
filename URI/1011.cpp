#include <stdio.h>
#define PI 3.14159

int main()
{
    double R;
    while(scanf("%lf",&R) != EOF)
    {
        printf("VOLUME = %.3lf\n",4.0/3*PI*R*R*R);
    }
    return 0;
}
