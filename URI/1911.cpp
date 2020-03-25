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
    while(cin >> n && n)
    {
		map<string, string> mm;
		string s, ss;
		FOR(i, 0, n)
		{
			cin >> s >> ss;
			mm[s] = ss;
		}
		cin >> m;
		int ans = 0;
		FOR(i, 0, m)
		{
			cin >> s >> ss;
			string sig = mm[s];
			int diff = 0;
			FOR(i, 0, (int) sig.size())
			{
				if(sig[i] != ss[i]) diff++;
			}
			if(diff > 1) ans++;
		}
		printf("%d\n", ans);
    }
	return 0;
}