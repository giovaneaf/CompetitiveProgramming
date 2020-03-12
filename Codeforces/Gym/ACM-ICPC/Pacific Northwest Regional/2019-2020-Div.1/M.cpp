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
#define MAXN 1010
#define LOGMAXN 20
#define MAXM 100010
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL
 
#define ITER 1000000
#define DEBUG 0
 
int n, m;
string M[MAXN];
int dr[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dc[] = {0, 0, 1, -1, 1, -1, 1, -1};
 
bool wall(int r, int c, int id)
{
	if(id == 0)
	{
		return M[r+1][c] == '/' && M[r][c+1] == '/';
	}
	if(id == 1)
	{
		return M[r+1][c] == '\\' && M[r][c-1] == '\\';
	}
	if (id == 2)
	{
		return M[r-1][c] == '\\' && M[r][c+1] == '\\';
	}
	return M[r-1][c] == '/' && M[r][c-1] == '/';
}
 
bool stucked(int r, int c, vector<vb>& seen)
{
	seen[r][c] = true;
	bool st = !(r == 0 || r == n-1 || c == 0 || c == m-1);
	int nr, nc;
	FOR(k, 0, 4)
	{
		nr = r + dr[k]; nc = c + dc[k];
		if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
		if(seen[nr][nc] || M[nr][nc] != '.') continue;
		st = stucked(nr, nc, seen) && st;
	}
	FOR(k, 4, 8)
	{
		nr = r + dr[k]; nc = c + dc[k];
		if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
		if(seen[nr][nc] || M[nr][nc] != '.' || wall(r, c, k-4)) continue;
		st = stucked(nr, nc, seen) && st;
	}
	return st;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m)
	{
		FOR(i, 0, n)
		{
			cin >> M[i];
		}
		vector<vb> seen(n, vb(m, false));
		int ans = 0;
		int square = 0;
		FOR(i, 0, n)
		{
			FOR(j, 0, m)
			{
				if(M[i][j] == '.' && !seen[i][j])
				{
					ans += stucked(i, j, seen);
				}
				else if(M[i][j] == '/' && i < n-1 && j < m-1 && M[i][j+1] == '\\' && M[i+1][j] == '\\' && M[i+1][j+1] == '/')
				{
					square++;
				}
			}
		}
		printf("%d\n", ans+square);
	}
	return 0;
}
close