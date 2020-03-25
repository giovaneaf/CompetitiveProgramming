#include <stdio.h>

int main()
{
    int i,max,pos;
    int list[100];
    for (i=0;i<100;i++)
    {
        scanf("%d",&list[i]);
    }
    for (i=0,max=0;i<100;i++)
        if(list[i]>max)
        {
            max = list[i];
            pos = i+1;
        }
    printf("%d\n%d\n",max,pos);
	return 0;
}
