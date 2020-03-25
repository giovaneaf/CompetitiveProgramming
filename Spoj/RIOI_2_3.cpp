#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 1000010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9
 
int n, m, k;
 
int dist[(1 << 10)][50][50];
int M[50][50];
int dr[] = {0, 0, -1, 1};
int dc[] = {1, -1, 0, 0}; 
 
 
int solve(int mask, int r, int c, int er, int ec)
{
	FOR(i, 0, (1 << 10))
	{
		FOR(j, 0, n)
		{
			FOR(k, 0, n)
			{
				dist[i][j][k] = -1;
			}
		}
	}
	dist[mask][r][c] = 1;
	priority_queue<pair<ii, ii>, vector<pair<ii, ii>>, greater<pair<ii, ii>>> q;
	q.push(mp(mp(1, mask), mp(r, c)));
	while(q.size())
	{
		r = q.top().snd.fst;
		c = q.top().snd.snd;
		mask = q.top().fst.snd;
		q.pop();
		if(r == er && c == ec)
			return dist[mask][r][c];
		FOR(i, 0, 4)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];
			if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
			int toSum = ((mask & (1 << M[nr][nc])) == 0) ? 1 : 0;
			int nm = (mask | (1 << M[nr][nc]));
			if(dist[nm][nr][nc] == -1 || dist[nm][nr][nc] > toSum + dist[mask][r][c])
			{
				dist[nm][nr][nc] = toSum + dist[mask][r][c];
				q.push(mp(mp(dist[nm][nr][nc], nm), mp(nr, nc)));
			}
		}
	}
	return -1;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		while(cin >> n)
		{
			FOR(i, 0, n)
			{
				FOR(j, 0, n)
				{
					cin >> M[i][j];
				}
			}
			int r, c;
			int er, ec;
			cin >> r >> c;
			cin >> er >> ec;
			int ans = solve((1 << M[r][c]), r, c, er, ec);
			printf("%d\n", ans);
		}
	}
} 