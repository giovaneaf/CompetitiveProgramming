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
#define MAXN 10010
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

int n;
int t[MAXN];
int memo[MAXN];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		FOR(i, 1, n+1)
		{
			cin >> t[i];
		}
		memset(memo, INF, sizeof(memo));
		memo[0] = 0;
		FOR(p, 1, n+1)
		{
			FOR(k, 1, p+1)
			{
				memo[p] = min(memo[p], memo[p-k] + 120 + max(t[p]-t[p-k+1]-1800+20, 20*k));
			}
		}
		printf("%d\n", memo[n]);
	}
	return 0;
}
