#include <stdio.h>
#include <string.h>

int main()
{
    int i,j,count,carry;
    char v1[15]={};
    char v2[15]={};
    while (scanf("%s %s",v1,v2) != EOF)
    {
        if (v1[0] == '0' && v2[0] == '0' && strlen(v1)==1 && strlen(v2)==1)
            break;
        for (i=strlen(v1),j=strlen(v2),count=0,carry=0;i>-1 && j>-1;j--,i--)
        {
            if (v1[i]+v2[j]-96+carry>9)
            {
                count++;
                carry=1;
            }
            else
                carry=0;
        }
        if (i>j)
            for (;i>-1;i--)
            {
                if (v1[i]-48+carry>9)
                    count++;
                else
                    break;
            }
        else
            for (;j>-1;j--)
            {
                if (v2[j]-48+carry>9)
                    count++;
                else
                    break;
            }
        if (count == 0)
            printf("No carry operation.\n");
        else if (count == 1)
            printf("1 carry operation.\n");
        else
            printf("%d carry operations.\n",count);
    }
    return 0;
}