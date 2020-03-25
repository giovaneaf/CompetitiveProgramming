#include <stdio.h>

int main()
{
    char v[15];
    while (scanf("%s",v) != EOF)
    {
        if (v[0] == 'v')
        {
            scanf("%s",v);
            if (v[0] == 'a')
            {
                scanf("%s",v);
                if (v[0] == 'c')
                    printf("aguia\n");
                else
                    printf("pomba\n");
            }
            else
            {
                scanf("%s",v);
                if (v[0] == 'o')
                    printf("homem\n");
                else
                    printf("vaca\n");
            }
        }
        else
        {
            scanf("%s",v);
            if (v[0] == 'i')
            {
                scanf("%s",v);
                if (v[2] == 'm')
                    printf("pulga\n");
                else
                    printf("lagarta\n");
            }
            else
            {
                scanf("%s",v);
                if (v[0] == 'h')
                    printf("sanguessuga\n");
                else
                    printf("minhoca\n");
            }
        }

    }
    return 0;
}