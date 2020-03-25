#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    char str[100][51],buf[1];
    int i,j,k,N,L;
    cin >> N;
    for (k=0; k<N; k++)
    {
        unsigned long long int soma = 0;
        cin >> L;
        gets(buf);
        for (i=0;i<L;i++)
        {
            gets(str[i]);
        }
        for (i=0;i<L;i++)
        {
            j = 0;
            while (str[i][j] != '\0')
            {
                soma += str[i][j] - 'A' + j + i;
                j++;
            }
        }
        cout << soma << endl;
    }
    return 0;
}