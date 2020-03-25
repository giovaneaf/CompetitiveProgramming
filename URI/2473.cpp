#include <iostream>

using namespace std;

int main()
{
    int i;
    int v[6];
    for (i = 0; i < 6; i++)
        cin >> v[i];
    int n;
    int acertos = 0;
    for (i = 0; i < 6; i++)
    {
        cin >> n;
        for (int j = 0; j < 6; j++)
            if (v[j] == n)
            {
                acertos++;
                break;
            }
    }
    if (acertos == 6)
        cout << "sena\n";
    else if (acertos == 5)
        cout << "quina\n";
    else if (acertos == 4)
        cout << "quadra\n";
    else if (acertos == 3)
        cout << "terno\n";
    else
        cout << "azar\n";
    return 0;
}