#include <cstdio>

int main()
{
    int N;
    scanf("%d",&N);
    int d1,d2;
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d",&d1,&d2);
        if (d2 == 0)
            printf("divisao impossivel\n");
        else
            printf("%.1f\n",(float)d1/d2);
    }
    return 0;
}