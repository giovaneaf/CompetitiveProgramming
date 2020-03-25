#include <cstdio>

int main()
{
    int C[3];
    for (int i = 0; i < 3; i++)
        C[i] = 0;
    int fuel = 1;
    while(fuel != 4)
    {
        scanf("%d",&fuel);
        while(fuel < 1 || fuel > 4)
            scanf("%d",&fuel);
        if (fuel != 4)
            C[fuel-1]++;
    }
    printf("MUITO OBRIGADO\nAlcool: %d\nGasolina: %d\nDiesel: %d\n",C[0],C[1],C[2]);
    return 0;
}
