#include <cstdio>

int main()
{
    int N;
    scanf("%d",&N);
    double n1,n2,n3,media;
    for (int i = 0; i < N; i++)
    {
        scanf("%lf %lf %lf",&n1,&n2,&n3);
        media = (2*n1+3*n2+5*n3)/10.0;
        printf("%.1lf\n",media);
    }
    return 0;
}