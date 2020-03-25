#include <stdio.h>

main()
{
    int i,count;
    float n1,n2,n3,n4,n5,n6;
    scanf("%f %f %f %f %f %f",&n1,&n2,&n3,&n4,&n5,&n6);
    float list[] = {n1,n2,n3,n4,n5,n6};
    for (i=0,count=0;i<6;i++)
        if (list[i]>0)
            count++;
    printf("%d valores positivos\n",count);
}