#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, bool> ib;

#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define all(v) v.begin(), v.end()

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 200010
#define LOGMAXN 20
#define MAXM 1000010
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL

int T;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> T)
	{
		while(T--)
		{
			int n;
			cin >> n;
			int v[MAXN];
			vi pos(n+2, -1);
			FOR(i, 0, n)
			{
				cin >> v[i];
			}
			int ans = INF;
			FOR(i, 0, n)
			{
				if(pos[v[i]] > -1)
				{
					ans = min(i - pos[v[i]] + 1, ans);
				}
				pos[v[i]] = i;
			}
			printf("%d\n", ans == INF ? -1 : ans);
		}
	}
	return 0;
}