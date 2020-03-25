#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int main()
{
    int i,j,D,N;
    char valor[102],novo[102];
    while (1)
    {
        cin >> D;
        scanf("%s",valor);
        if (D == 0 && valor[0] == '0' && valor[1] == '\0')
            break;
        i = 0;
        j = 0;
        while ((valor[i] == '0' || valor[i] == (D + '0')) && valor[i] != '\0')
            i++;
        if (valor[i] == '\0')
        {
            novo[0] = '0';
            novo[1] = '\0';
        }
        else
        {
            while (valor[i] != '\0')
            {
                if (valor[i] != (D+'0'))
                {
                    novo[j] = valor[i];
                    j++;
                }
                i++;
            }
            novo[j] = '\0';
        }
        cout << novo << endl;
    }
    return 0;
}