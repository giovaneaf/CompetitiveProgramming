#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define MAXN 35
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9

int n, m;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n >> m)
    {
		map<string, int> mm;
		string s;
		int v;
		FOR(i, 0, n)
		{
			cin >> s >> v;
			mm[s] = v;
		}
		FOR(i, 0, m)
		{
			ll ans = 0LL;
			while(cin >> s)
			{
				if(s.size() == 1 && s[0] == '.') break;
				if(mm.find(s) != mm.end()) ans += mm[s];
			}
			printf("%lld\n", ans);
		}
    }
	return 0;
}