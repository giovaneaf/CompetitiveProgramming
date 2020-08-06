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
#define MAXN 10010
#define LOGMAXN 20
#define MAXM 250010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

ll mod = 1000000007LL;

int n, R, C, l;

string M[MAXN];
ii wall[4][15][15];
vii st;

int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

bool collide(int r, int c)
{
	if(r < 0 || r >= R || c < 0 || c >= C || M[r][c] == 'W') return true;
	return false;
}

ii checkRobots(ii npos, ii pos, int ri, int dir, vii& st)
{
	FOR(i, 0, n)
	{
		if(i == ri) continue;
		if(dir <= 1)
		{
			if(st[i].snd == pos.snd && min(pos.fst, npos.fst) <= st[i].fst && st[i].fst <= max(pos.fst, npos.fst))
			{
				npos = st[i];
				npos.fst -= dr[dir]; npos.snd -= dc[dir];
			}
		}
		else
		{
			if(st[i].fst == pos.fst && min(pos.snd, npos.snd) <= st[i].snd && st[i].snd <= max(pos.snd, npos.snd))
			{
				npos = st[i];
				npos.fst -= dr[dir]; npos.snd -= dc[dir];
			}
		}
	}
	return npos;
}

int solve(vii& st, int depth)
{
	vii nst(n);
	ii npos;
	sort(st.begin()+1, st.end());
	queue<pair<vii, int>> q;
	set<vii> seen;
	q.push(mp(st, 0));
	seen.insert(st);
	while(q.size())
	{
		st = q.front().fst;
		depth = q.front().snd;
		q.pop();
		if(M[st[0].fst][st[0].snd] == 'X') return depth;
		if(depth == l) continue;
		FOR(i, 0, n)
		{
			FOR(k, 0, 4)
			{
				npos = wall[k][st[i].fst][st[i].snd];
				npos = checkRobots(npos, mp(st[i].fst, st[i].snd), i, k, st);
				nst = st;
				nst[i] = npos;
				sort(nst.begin()+1, nst.end());
				if(seen.find(nst) == seen.end())
				{
					seen.insert(nst);
					q.push(mp(nst, depth+1));
				}
			}
		}
	}
	return INF;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> C >> R >> l)
	{
		st.resize(n);
		int id;
		FOR(i, 0, R)
		{
			cin >> M[i];
			FOR(j, 0, C)
			{
				if(M[i][j] >= '1' && M[i][j] <= '4')
				{
					id = M[i][j] - '1';
					M[i][j] = '.';
					st[id] = mp(i, j);
				}
			}
		}
		int nr, nc;
		FOR(i, 0, R)
		{
			FOR(j, 0, C)
			{
				if(M[i][j] == 'W') continue;
				FOR(k, 0, 4)
				{
					nr = i; nc = j;
					do
					{
						nr += dr[k]; nc += dc[k];
					} while(!collide(nr, nc));
					nr -= dr[k]; nc -= dc[k];
					wall[k][i][j] = mp(nr, nc);
				}
			}
		}
		int ans = solve(st, 0);
		if(ans == INF) printf("NO SOLUTION");
		else printf("%d", ans);
		puts("");
	}
	return 0;
}
