#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
#define MAXN 110
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL
 
#define ITER 1000000
#define DEBUG 0
 
int n, m;
int M[MAXN][MAXN];
int accMe[MAXN][MAXN];
int accHer[MAXN][MAXN];
ii memo[MAXN][MAXN][2];
 
inline int diff(ii& p, bool negative)
{
	return (negative ? -1 : 1)*(p.fst-p.snd);
}
 
ii solve(int r, int c, bool me)
{
	if(r < 0 || c >= m) return mp(0, 0);
	if(memo[r][c][me] == mp(INF, INF))
	{
		ii ans;
		if(me)
		{
			if(c == m-1)
			{
				ans = mp(accMe[r][c] - accMe[r][c-1], 0);
			}
			ans = mp(INF, INF);
			ii tmp;
			for(int i = c; i < m; ++i)
			{
				tmp = solve(r, i+1, !me);
				tmp.fst += accMe[r][i] - (c > 0 ? accMe[r][c-1] : 0);
				if(ans == mp(INF, INF) || (diff(ans, false) < diff(tmp, false)))
				{
					ans = tmp;
				}
			}
			memo[r][c][me] = ans;
		}
		else
		{
			if(r == 0)
			{
				ans = mp(0, accHer[r][c] - accHer[r+1][c]);
			}
			else
			{
				ans = mp(INF, INF);
				ii tmp;
				for(int i = r; i >= 0; --i)
				{
					tmp = solve(i-1, c, !me);
					tmp.snd += accHer[i][c] - (r < n-1 ? accHer[r+1][c] : 0);
					if(ans == mp(INF, INF) || (diff(ans, true) < diff(tmp, true)))
					{
						ans = tmp;
					}
				}
			}
			memo[r][c][me] = ans;
		}
	}
	return memo[r][c][me];
}
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	while(cin >> n >> m)
	{
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < m; ++j)
			{
				M[i][j] = ((i+j)&1 ? -1 : 1);
				FOR(k, 0, 2)
					memo[i][j][k] = {INF, INF};
			}
		}
		accMe[0][0] = M[0][0];
		for(int i = 1; i < n; ++i)
			accMe[i][0] = M[i][0] + accMe[i-1][0];
		for(int j = 1; j < m; ++j)		
			accMe[0][j] = M[0][j] + accMe[0][j-1];
		for(int i = 1; i < n; ++i)
		{
			for(int j = 1; j < m; ++j)
			{
				accMe[i][j] = M[i][j] + accMe[i-1][j] + accMe[i][j-1] - accMe[i-1][j-1];
			}
		}
		accHer[n-1][m-1] = M[n-1][m-1];
		for(int i = n-2; i >= 0; --i)
			accHer[i][m-1] = M[i][m-1] + accHer[i+1][m-1];
		for(int j = m-2; j >= 0; --j)		
			accHer[n-1][j] = M[n-1][j] + accHer[n-1][j+1];
		for(int i = n-2; i >= 0; --i)
		{
			for(int j = m-2; j >= 0; --j)
			{
				accHer[i][j] = M[i][j] + accHer[i+1][j] + accHer[i][j+1] - accHer[i+1][j+1];
			}
		}
		ii ans = solve(n-1, 0, true);
		printf("%d\n", abs(diff(ans, false)));
	}
	return 0;
}