#include <iostream>
#include <cstdio>
#include <ctype.h>
using namespace std;

int main()
{
    int k,i,N;
    char buf[1],frase[201];
    cin >> N;
    gets(buf);
    for (k=0;k<N;k++)
    {
        int alpha[26] = {};
        int maximo = 0;
        gets(frase);
        i = 0;
        while (frase[i] != '\0')
        {
            if (isalpha(frase[i]))
            {
                frase[i] = tolower(frase[i]);
                alpha[frase[i] - 'a']++;
                if (alpha[frase[i] - 'a'] > maximo)
                    maximo = alpha[frase[i] - 'a'];
            }
            i++;
        }
        for (i=0;i<26;i++)
            if (alpha[i] == maximo)
                cout << (char) (i+'a');
        cout << endl;
    }
    return 0;
}