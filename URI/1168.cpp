#include <stdio.h>
#include <string.h>

leds(char v[],int len)
{
    int i,led;
    for (i=0,led=0;i<len;i++)
    {
        if (v[i] == '2' || v[i] == '3' || v[i] == '5')
            led += 5;
        else if (v[i] == '6' || v[i] == '9' || v[i] == '0')
            led += 6;
        else if (v[i] == '1')
            led += 2;
        else if (v[i] == '4')
            led += 4;
        else if (v[i] == '7')
            led += 3;
        else
            led += 7;
    }
    return led;
}

int main()
{
    int i,N;
    char v[101];
    scanf("%d",&N);
    for (i=0;i<N;i++)
    {
        scanf("%s",v);
        printf("%d leds\n",leds(v,strlen(v)));
    }
    return 0;
}