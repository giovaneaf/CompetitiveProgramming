#include <iostream>
#include <cstdio>
#include <ctype.h>
using namespace std;

int main()
{
    int i,j,N;
    char input[51], fl[51];
    int cont;
    cin >> N;
    gets(fl);
    for (i=0;i<N;i++)
    {
        int flag = 1;
        gets(input);
        j = 0;
        cont = 0;
        while (input[cont] != '\0')
        {
            if (flag && input[cont] != ' ')
            {
                fl[j] = input[cont];
                flag = 0;
                j++;
            }
            else if (input[cont] == ' ')
                flag = 1;
            cont++;
        }
        fl[j] = '\0';
        cout << fl << endl;
    }
    return 0;
}
