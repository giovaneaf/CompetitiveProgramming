#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    while(cin >> T && T > 0)
    {
        map<string, int> dom;
        map<string, int> img;
        bool notFunc = false;
        bool notInv = false;
        while(T--)
        {
            string a, b, c;
            cin >> a >> b >> c;
            if(dom.find(a) != dom.end())
            {
                notFunc = true;
            }
            else
            {
                dom[a] = 1;
            }
            if(img.find(c) != img.end())
            {
                notInv = true;
            }
            else
            {
                img[c] = 1;
            }
        }
        if(notFunc)
            cout << "Not a function.";
        else if(notInv)
            cout << "Not invertible.";
        else
            cout << "Invertible.";
        cout << endl;
    }
    return 0;
}
