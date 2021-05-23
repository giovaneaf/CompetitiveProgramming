#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, int> ip;
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
#define MAXN 5010
#define LOGMAXN 23
#define MAXM 1110
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-6
#define MAXWORDS 1010
 
ll mod = 1000000007LL;

int T;
int n, m;

int memo[MAXN][MAXN];
int s[21];

int solve(int pushup, int points)
{
	if(pushup >= n)
	{
		return (pushup == n ? points : -INF);
	}
	if(memo[pushup][points] == -1)
	{
		int ans = -INF;
		int tmp;
		FOR(i, 0, m)
		{
			tmp = solve(pushup + points + s[i], points + s[i]);
			if(tmp != -INF && tmp > ans)
			{
				ans = tmp;
			}
		}
		memo[pushup][points] = ans;
	}
	return memo[pushup][points];
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> T)
	{
		while(T--)
		{
			memset(memo, -1, sizeof(memo));
			cin >> n >> m;
			FOR(i, 0, m) cin >> s[i];
			int ans = solve(0, 0);
			printf("%d\n", ans == -INF ? -1 : ans);
		}
	}
	return 0;
}