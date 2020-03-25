#include <bits/stdc++.h>

using namespace std;

typedef long long ll; 

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 40
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 2000000000
#define EPS 1e-9

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s;
    cin >> s;
    vector<int> v[260];
    for(int i = 0; i < s.size(); ++i)
        v[(int) s[i]].emplace_back(i);
    int q;
    cin >> q;
    string ss;
    for(int i = 0; i < q; ++i)
    {
        cin >> ss;
        bool can = true;
        int a, pos;
        a = -1; pos = 0;
        for(char c : ss)
        {
            auto it = lower_bound(v[c].begin(), v[c].end(), pos);
            if(it == v[c].end())
            {
                can = false;
                break;
            }
            if(a == -1) a = *it;
            pos = (*it) + 1;
        }
        if(can)
            printf("Matched %d %d\n", a, pos-1);
        else
            printf("Not matched\n");
    }
	return 0;
}