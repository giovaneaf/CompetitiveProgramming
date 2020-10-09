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
#define MAXN 1010
#define LOGMAXN 20
#define MAXM 1000010
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL

#define ITER 10000000

#define DEBUG 0

int n, m, x, y;
int memo[MAXN][MAXN][2];
int black[MAXN];
int white[MAXN];

int solve(int pos, int len, bool isBlack)
{
	if(pos == m) 
	{
		return ((len >= x && len <= y) ? 0 : INF);
	}
	if(memo[pos][len][isBlack] == -1)
	{
		int changes;
		if(isBlack)
			changes = white[pos];
		else
			changes = black[pos];
		int ans = changes;
		if(pos+1 == m)
		{
			ans += solve(pos+1, len, isBlack);
		}
		else if(len < x)
		{
			ans += solve(pos+1, len+1, isBlack);
		}
		else if (len == y)
		{
			ans += solve(pos+1, 1, !isBlack);
		}
		else
		{
			ans += min(solve(pos+1, len+1, isBlack), solve(pos+1, 1, !isBlack));
		}
		memo[pos][len][isBlack] = ans;
#if DEBUG
		printf("%d %d %d = %d\n", pos, len, isBlack, memo[pos][len][isBlack]);
#endif
	}
	return memo[pos][len][isBlack];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m >> x >> y)
	{
		memset(black, 0, sizeof(black));
		memset(white, 0, sizeof(white));
		memset(memo, -1, sizeof(memo));
		FOR(i, 0, n)
		{
			string s;
			cin >> s;
			FOR(j, 0, (int) s.size())
			{
				if(s[j] == '.')
					white[j]++;
				else
					black[j]++;
			}
		}
		printf("%d\n", min(solve(0, 1, true), solve(0, 1, false)));
	}
	return 0;
}
