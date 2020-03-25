#include <stdio.h>

void simplify(int num,int den)
{
    int max,i;
    if (num >= den)
        max = num;
    else
        max = den;
        for (i=2; i<max; i++)
            if (num%i == 0 && den%i == 0)
            {
                num /= i;
                den /= i;
                i=1;
            }
        printf("%d/%d\n",num,den);
}

int main ()
{
    int i,N,n1,n2,n3,n4,num,den;
    char ch1,ch2,ch3;
    scanf("%d",&N);
    for (i=0;i<N;i++)
    {
        scanf("%d %c %d %c %d %c %d",&n1,&ch1,&n2,&ch2,&n3,&ch3,&n4);
        if (ch1 == '/' && ch3 == '/')
        {
            switch (ch2)
            {
                case '+':
                            num = (n1*n4+n3*n2);
                            den = (n2*n4);
                            break;
                case '-':
                            num = (n1*n4-n3*n2);
                            den = (n2*n4);
                            break;
                case '/':
                            num = (n1*n4);
                            den = (n2*n3);
                            break;
                case '*':
                            num = (n1*n3);
                            den = (n2*n4);
            }
            if (n2 != 0 && n4 !=0)
            {
                printf("%d/%d = ",num,den);
                simplify(num,den);
            }
        }
    }
}
