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
 
ll dist[(1 << 4)][100][100];
string M[100];
int dr[] = {0, 0, -1, 1};
int dc[] = {1, -1, 0, 0};
map<char, int> mm; 
 
inline int Key(char ch)
{
	if(ch == 'g' || ch == 'r' || ch == 'b' || ch == 'y') return mm[ch];
	return -1;
}
 
inline int Door(char ch)
{
	if(ch == 'G' || ch == 'R' || ch == 'B' || ch == 'Y') return mm[ch];
	return -1;
}
 
int solve(int mask, int r, int c, int er, int ec)
{
	FOR(i, 0, (1 << 4))
	{
		FOR(j, 0, n)
		{
			FOR(k, 0, m)
			{
				dist[i][j][k] = -1LL;
			}
		}
	}
	queue<pair<int, ii>> q;
	q.push(mp(mask, mp(r, c)));
	dist[mask][r][c] = 0;
	while(q.size())
	{
		r = q.front().snd.fst;
		c = q.front().snd.snd;
		mask = q.front().fst;
		q.pop();
		if(M[r][c] == 'X')
			return dist[mask][r][c];
		FOR(i, 0, 4)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];
			if(nr < 0 || nr >= n || nc < 0 || nc >= m || M[nr][nc] == '#') continue;
			int nd = Door(M[nr][nc]);
			if(nd > -1 && (mask & (1 << nd)) == 0) continue;
			int nm = Key(M[nr][nc]);
			nm = (nm == -1 ? mask : (mask | (1 << nm)));
			if(dist[nm][nr][nc] == -1LL)
			{
				dist[nm][nr][nc] = dist[mask][r][c] + 1;
				q.push(mp(nm, mp(nr, nc)));
			}
		}
	}
	return -1LL;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	mm['g'] = 0; mm['G'] = 0; mm['r'] = 1; mm['R'] = 1; mm['b'] = 2; mm['B'] = 2; mm['y'] = 3; mm['Y'] = 3;
	while(cin >> n >> m)
	{
		if(n == 0 && m == 0) break;
		int r, c;
		int er, ec;
		FOR(i, 0, n)
		{
			cin >> M[i];
			FOR(j, 0, m)
			{
				if(M[i][j] == '*')
				{
					r = i; c = j;
				}
				else if(M[i][j] == 'X')
				{
					er = i; ec = j;
				}
			}
		}
		int ans = solve(0, r, c, er, ec);
		if(ans == -1LL) printf("The poor student is trapped!\n");
		else printf("Escape possible in %d steps.\n", ans);
	}
} 