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
#define MAXN 200010
#define LOGMAXN 20
#define MAXM 100010
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL
 
#define ITER 1000000
#define DEBUG 0
 
int n;
string M[11];
vector<vb> seen(11, vb (11, false));
vvi shore(11, vi (11, -1));
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};
map<ll, int> memo;
map<ii, int> mm;
int sz;
ii v[110];
 
void fillShore(int r, int c, int shoreV)
{
	seen[r][c] = true;
	int nr, nc;
	FOR(k, 0, 4)
	{
		nr = r + dr[k]; nc = c + dc[k];
		if(nr < 0 || nr >= n || nc < 0 || nc >= n || M[nr][nc] == 'x' || seen[nr][nc]) continue;
		if(M[nr][nc] == '*')
		{
			fillShore(nr, nc, shoreV);
		}
		else if(M[nr][nc] == '.')
		{
			shore[nr][nc] = shoreV;
		}
	}
}
 
void DFS(int r, int c)
{
	seen[r][c] = true;
	mm[{r, c}] = sz;
	v[sz++] = {r, c};
	int nr, nc;
	FOR(k, 0, 4)
	{
		nr = r + dr[k]; nc = c + dc[k];
		if(nr < 0 || nr >= n || nc < 0 || nc >= n || M[nr][nc] == 'x' || seen[nr][nc]) continue;
		if(M[nr][nc] == '.' && shore[nr][nc] == shore[r][c])
		{
			DFS(nr, nc);
		}
	}
}
 
void print(ll st)
{
	printf("state = ");
	FOR(i, 0, sz)
	{
		printf("%d", st%2);
		st /= 2;
	}
	putchar('\n');
}
 
int grundy(ll st)
{
	if(memo.count(st)) return memo[st];
	set<int> s;
	int r, c, nr, nc;
	FOR(i, 0, sz)
	{
		if((st & (1LL << i)))
		{
			r = v[i].fst, c = v[i].snd;
			list<int> toAdd;
			st = st & (~(1LL << i));
			FOR(k, 0, 4)
			{
				nr = r + dr[k]; nc = c + dc[k];
				if(nr < 0 || nr >= n || nc < 0 || nc >= n || M[nr][nc] == 'x' || shore[nr][nc] != shore[r][c]) continue;
				if(M[nr][nc] == '.')
				{
					auto it = mm.find({nr, nc});
					if(it != mm.end() && (st & (1LL << it->snd)))
					{
						st = st & (~(1LL << it->snd));
						toAdd.push_back(it->snd);
					}
				}
			}
			s.insert(grundy(st));
			// fix st
			st = st | (1LL << i);
			for(auto it = toAdd.begin(); it != toAdd.end(); ++it)
			{
				st = st | (1LL << (*it));
			}
		}
	}
	int mex = 0;
	auto it = s.begin();
	while(it != s.end() && (*it) == mex)
	{
		mex++; it++;
	}
	return memo[st] = mex;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		FOR(i, 0, n)
			cin >> M[i];
		fill(shore.begin(), shore.end(), vi (11, -1));
		fill(seen.begin(), seen.end(), vb (11, false));
		int xr = 0LL;
		ll st; // state
		int nr, nc;
		int shoreV = 0;
		FOR(i, 0, n)
		{
			FOR(j, 0, n)
			{
				if(M[i][j] == '*' && !seen[i][j])
				{
					fillShore(i, j, shoreV);
					shoreV++;
				}
			}
		}
		FOR(i, 0, n)
		{
			FOR(j, 0, n)
			{
				if(M[i][j] == '.' && !seen[i][j] && shore[i][j] > -1)
				{
					sz = 0;
					DFS(i, j);
					assert(sz <= 64);
					st = 0;
					FOR(k, 0, sz)
					{
						st = st | (1LL << k);
					}
					xr = xr ^ grundy(st);
				}
				mm.clear();
				memo.clear();
			}
		}
		printf("%s\n", xr ? "First player will win" : "Second player will win");
	}
	return 0;
}