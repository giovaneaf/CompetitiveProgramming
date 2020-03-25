#include <iostream>

using namespace std;

int main()
{
    string s;
    int i,spaces;
    while(cin >> s)
    {
        spaces = 0;
        int tam = s.size();
        while(tam > 0)
        {
            for (int j = 0; j < spaces; j++)
            {
                cout << " ";
            }
            cout << s[0];
            for (i = 1; i < tam; i++)
            {
                cout << " " << s[i];
            }
            cout << "\n";
            tam--;
            spaces++;
        }
        cout << "\n";
    }
    return 0;
}