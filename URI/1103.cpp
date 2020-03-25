#include <stdio.h>

int cont_dias(h1,m1,h2,m2)
{
    int aux,i,count=0;
    aux = m1;
    if (m2>=m1 || h1!=h2)
    {
        if (h1 == h2)
            return (m2-m1);
        else
        {
            while(h1!=h2)
            {
                for (;aux<60;aux++,count++)
                    ;
                aux = 0;
                if (h1 != 23)
                    h1++;
                else
                    h1 = 0;
            }
            for (aux = 0;aux<m2;aux++,count++)
                ;
        }
    }
    else
    {
        for (i=0;i<24;i++)
        {
            for (;aux<60;aux++,count++)
                ;
            aux = 0;
            if (h1 != 23)
                h1++;
            else
                h1=0;
        }
        count += m2;
    }
    return count;
}

int main()
{
    int h1,m1,h2,m2;
    while (1)
    {
        scanf("%d %d %d %d",&h1,&m1,&h2,&m2);
        if (h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0)
            return 0;
        if (h1>=0 && h1 <= 23 && h2>=0 && h2 <= 23 && m1>=0 && m1 <= 59 && m1>=0 && m1 <= 59)
            if (h1 != h2 || m1 != m2)
                printf("%d\n",cont_dias(h1,m1,h2,m2));
    }
    return 0;
}