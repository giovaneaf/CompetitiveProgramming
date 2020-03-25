#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define MAXN 200010

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    while(cin >> n)
    {
        map<string, int> mp;
        vector<string> v[n];
        for(int i = 0; i < n; ++i)
        {
            string name;
            cin >> name;
            mp[name] = i;
            for(int j = 0; j < 3; ++j)
            {
                string item;
                cin >> item;
                v[i].push_back(item);
            }
        }
        string str;
        getline(cin, str);
        getline(cin, str);
        while(str != "")
        {
            string a, b;
            stringstream ss(str);
            ss >> a;
            ss >> b;
            int idx = mp[a];
            bool found = false;
            for(int i = 0; i < 3; ++i)
            {
                if(v[idx][i] == b)
                {
                    found = true;
                    break;
                }
            }
            getline(cin, str);
            if(found) printf("Uhul! Seu amigo secreto vai adorar o/\n");
            else printf("Tente Novamente!\n");
        }
    }
	return 0;
}
