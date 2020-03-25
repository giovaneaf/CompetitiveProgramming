#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int main()
{
    map<string, string> mapa;
    int N;
    cin >> N;
    char v[1000],k[1000];
    map<string, string>::iterator it = mapa.begin();
    gets(v);
    for (int i = 0; i < N; i++)
    {
        gets(v);
        gets(k);
        string lan(v), mc(k);
        mapa.insert(it, pair<string, string>(lan,mc));
    }
    int M;
    cin >> M;
    gets(v);
    for (int i = 0; i < M; i++)
    {
        gets(v);
        gets(k);
        string lan(v), mc(k);
        cout << lan << endl;
        it = mapa.find(mc);
        cout << it->second << endl;
        cout << endl;
    }
    return 0;
}