#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
#define MAXN 100010
#define LOGMAXN 21
#define MAXM 250010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
 
ll mod = 1000000007LL;
int n, m;
ll M[510][510];
bool seen[510][510];
int dr[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dc[] = {0, 0, 1, -1, 1, -1, 1, -1};

ll solve(int r, int c)
{
	ll ans = 0LL;
	priority_queue<pair<ll, ii>> pq;
	pq.push(mp(-M[r][c], mp(r, c)));
	int nr, nc;
	seen[r][c] = true;
	while(pq.size())
	{
		r = pq.top().snd.fst; c = pq.top().snd.snd;
		pq.pop();
		ans -= M[r][c];
		FOR(i, 0, 8)
		{
			nr = r + dr[i]; nc = c + dc[i];
			if(nr < 0 || nr >= n || nc < 0 || nc >= m || seen[nr][nc] || M[nr][nc] >= 0) 
				continue;
			seen[nr][nc] = true;
			M[nr][nc] = max(M[nr][nc], M[r][c]);
			pq.push(mp(-M[nr][nc], mp(nr, nc)));
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m)
	{
		FOR(i, 0, n) 
		{
			FOR(j, 0, m)
			{				
				cin >> M[i][j];
				if(M[i][j] > 0) M[i][j] = 0;
				seen[i][j] = false;
			}
		}
		int r, c;
		cin >> r >> c;
		r--, c--;
		printf("%lld\n", solve(r, c));
	}
	return 0;
}
