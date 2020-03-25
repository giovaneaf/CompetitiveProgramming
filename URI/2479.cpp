#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{
    char buf[10];
    int N;
    cin >> N;
    int p, n;
    p = n = 0;
    char l;
    gets(buf);
    vector<string> names;
    string name;
    for (int i = 0; i < N; i++)
    {
        cin >> l;
        if (l == '+')
            p++;
        else
            n++;
        cin >> name;
        names.push_back(name);
    }
    sort(names.begin(),names.end());
    vector<string>::iterator it;
    for (it = names.begin(); it != names.end(); it++)
    {
        cout << *it << endl;
    }
    cout << "Se comportaram: " << p << " | Nao se comportaram: " << n << endl;
    return 0;
}