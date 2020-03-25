#include <stdio.h>

int main()
{
    int A,B,C,aux;
    int card[3];
    while (scanf("%d %d %d",&A,&B,&C) != EOF)
    {
        if (A == 0 && B == 0 && C == 0)
            break;
        if (A == B && A == C)
        {
            if (A==13)
                card[0]='*';
            else
                card[0] = card[1] = card[2] = A+1;
        }
        else if (A == B || A == C || B == C)
        {
            if (A == C)
            {
                aux = C;
                C = B;
                B = aux;
            }
            else if (B == C)
            {
                aux = C;
                C = A;
                A = aux;
            }
            if (A == B)
            {
                if (A == 13 && C == 12)
                    card[0] = card[1] = card[2] = 1;
                else if (A == 13)
                {
                    card[0] = C+1;
                    card[1] = A;
                    card[2] = B;
                }
                else if (C == 13)
                {
                    card[0] = 1;
                    card[1] = A+1;
                    card[2] = B+1;
                }
                else if (C>A)
                {
                    card[0] = A;
                    card[1] = B;
                    card[2] = C+1;
                }
                else if (C+1 == A)
                {
                    card[0] = A;
                    card[1] = B;
                    card[2] = C+2;
                }
                else
                {
                    card[0] = C+1;
                    card[1] = A;
                    card[2] = B;
                }
            }
        }
        else
        {
            card[0] = 1;
            card[1] = 1;
            card[2] = 2;
        }
        if (card[0] == '*')
            printf("%c\n",card[0]);
        else
            printf("%d %d %d\n",card[0],card[1],card[2]);
    }
    return 0;
}