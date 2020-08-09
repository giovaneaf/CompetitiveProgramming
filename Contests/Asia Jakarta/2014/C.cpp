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
#define MAXN 100010
#define LOGMAXN 20
#define MAXM 250010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

ll mod = 1000000007LL;

int T, n, k, e;
int memo[1001][11][51][4][2];
int ap[4] = {0, 4, 8, 11};
int sl[1001];

int solve(int pos, int k, int e, int al, bool shutdown)
{
	if(pos == n) return 0;
	if(memo[pos][k][e][al][shutdown] == -1)
	{
		int nal = al;
		bool nsd = shutdown;
		if(al > e)
		{
			nal = 0;
			nsd = true;
		}
		int ans = max(0, sl[pos] - ap[nal]) + solve(pos+1, k, e-nal, nal, nsd);
		if(k > 0 && !shutdown)
		{
			FOR(i, 0, 4)
			{
				if(i > e) break;
				if(i == al) continue;
				ans = min(ans, max(0, sl[pos] - ap[i]) + solve(pos+1, k-1, e-i, i, shutdown));
			}
		}
		memo[pos][k][e][al][shutdown] = ans;
	}
	return memo[pos][k][e][al][shutdown];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	FOR(t, 0, T)
	{
		int ans = 0;
		memset(memo, -1, sizeof(memo));
		cin >> n >> k >> e;
		FOR(i, 0, n) cin >> sl[i];
		printf("Case #%d: %d\n", t+1, solve(0, k, e, 0, false));
	}
	return 0;
}
