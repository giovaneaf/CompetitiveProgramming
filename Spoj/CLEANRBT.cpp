#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll; 
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 100010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9
 
int n, m, k;
string M[25];
int memo[21][21][1024];
bool seen[21][21][1024];
int nDirt;
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};
 
int solve(int r, int c, int mask, map<ii, int>& mm)
{
	memo[r][c][mask] = 0;
	seen[r][c][mask] = true;
	queue<pair<ii, int>> q;
	q.push(mp(mp(r, c), mask));
	while(q.size())
	{
		r = q.front().first.first;
		c = q.front().first.second;
		mask = q.front().second;
		q.pop();
		if(mask == (1 << nDirt) - 1) return memo[r][c][mask];
		FOR(i, 0, 4)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];
			if(nr < 0 || nr >= n || nc < 0 || nc >= m || M[nr][nc] == 'x' || seen[nr][nc][mask] == true) continue;
			if(M[nr][nc] == '*')
			{
				int nmask = mask | (1 << mm[mp(nr, nc)]);
				seen[nr][nc][nmask] = true;
				memo[nr][nc][nmask] = 1 + memo[r][c][mask];
				q.push(mp(mp(nr, nc), nmask));
			}
			else
			{
				seen[nr][nc][mask] = true;
				memo[nr][nc][mask] = 1 + memo[r][c][mask];
				q.push(mp(mp(nr, nc), mask));
			}
		}
	}
	return -1;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> m >> n)
	{
		if(n == 0 && m == 0) break;
		map<ii, int> mm;
		ii start;
		nDirt = 0;
		FOR(i, 0, n)
		{			
			cin >> M[i];
			FOR(j, 0, m)
			{
				if(M[i][j] == '*')
				{
					mm[mp(i, j)] = nDirt++;
				}
				else if(M[i][j] == 'o')
				{
					start = mp(i, j);
				}
				FOR(k, 0, 1024)
				{					
					memo[i][j][k] = -1;
					seen[i][j][k] = false;
				}
			}
		}
		int ans = solve(start.fst, start.snd, 0, mm);
		printf("%d\n", ans);
	}
    return 0;
}