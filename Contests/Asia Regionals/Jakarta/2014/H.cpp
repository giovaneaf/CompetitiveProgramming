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
#define MAXN 2010
#define LOGMAXN 20
#define MAXM 250010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

ll mod = 1000000007LL;

int T, n, m, k;
int memo[MAXN][MAXN];
ii table[MAXN];
string s;

int solve(int pos, int m, bool loop)
{
	if(m <= 0) return s[pos-1] == 'A' ? 1 : 0;
	if(memo[pos][m] == -1)
	{
		int ans, tmp, x;
		if(loop)
		{
			ans = solve(pos+1, m-1, true);
			x = 1;
			if(ans == 1) table[pos].fst++;
			else table[pos].snd++;
			if(s[pos] == 'A')
			{
				for(int i = 2; i <= k; ++i)
				{
					tmp = solve(pos+1, m-i, false);
					if(tmp == 1) table[pos].fst++;
					else table[pos].snd++;
					if(ans < tmp) x = i;
					ans = max(ans, tmp);
				}
			}
			else
			{
				for(int i = 2; i <= k; ++i)
				{
					tmp = solve(pos+1, m-i, false);
					if(tmp == 1) table[pos].fst++;
					else table[pos].snd++;
					if(ans > tmp) x = i;
					ans = min(ans, tmp);
				}
			}
		}
		else
		{
			tmp = solve(pos+1, m - min(m, k), false);
			x = -1;
			ans = tmp;
			if(pos+1 < 2*n)
			{
				if(memo[pos+1][m] == 1) table[pos].fst--;
				else table[pos].snd--;
			}
			if(s[pos] == 'A')
			{
				if(table[pos].fst > 0) ans = 1;
			}
			else
			{
				if(table[pos].snd > 0) ans = 0;
			}
			if(tmp == 1) table[pos].fst++;
			else table[pos].snd++;
		}
		memo[pos][m] = ans;
	}
	return memo[pos][m];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	FOR(t, 0, T)
	{
		int ans = 0;
		memset(memo, -1, sizeof(memo));
		cin >> n >> m >> k;
		FOR(i, 0, m+1) table[i] = mp(0, 0);
		cin >> s;
		printf("Case #%d: %c\n", t+1, solve(0, m, true) == 1 ? 'A' : 'B');
	}
	return 0;
}
