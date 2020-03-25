#include <stdio.h>
#include <string.h>

int main()
{
    char str[50][51],buffer[2];
    int i,j,N,bigger,achou=0;
    while (1)
    {
        scanf("%d",&N);
        if (N == 0)
            break;
        gets(buffer);
        gets(str[0]);
        bigger = strlen(str[0]);
        for (i=1;i<N;i++)
        {
            gets(str[i]);
            if (strlen(str[i]) > bigger)
                bigger = strlen(str[i]);
        }
        if (achou)
            printf("\n");
        achou = 1;
        for (i=0;i<N;i++)
        {
            for (j=strlen(str[i]);j<bigger;j++)
                printf(" ");
            printf("%s\n",str[i]);
        }
    }
    return 0;
}