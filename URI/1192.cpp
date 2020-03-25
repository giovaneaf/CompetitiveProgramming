#include <stdio.h>

int operacao (int n1,int ch,int n2)
{
    if (n1 == n2)
        return n1*n2;
    if (ch >= 'A' && ch <= 'Z')
        return n2-n1;
    if (ch >= 'a' && ch <= 'z')
        return n1+n2;
}

int main()
{
    int N,i,n1,n2;
    char ch;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        scanf("%d %c %d",&n1,&ch,&n2);
        if (n1 >= 0 && n1 <= 9 && n2 >= 0 && n2 <= 9 && ((ch>='a' && ch<='z')||(ch>='A' && ch<='Z')))
            printf("%d\n", operacao (n1,ch,n2));
    }
}