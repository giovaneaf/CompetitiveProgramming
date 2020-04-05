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
#define MAXN 100010
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007

int T;
int n;

struct st
{
	int s, f;
	bool operator< (const st& v) { return s < v.s; };
};

st v[MAXN];
bool can;

void DFS(int cur, int c, vi& color, vi* adj)
{
	color[cur] = c;
	for(int& v : adj[cur])
	{
		if(color[v] == -1)
		{
			DFS(v, c^1, color, adj);
		}
		else if(color[v] == c)
		{			
			can = false;
			break;
		}
	}
}

bool overlap(int i, int j)
{
	if(v[i].s > v[j].s) swap(i, j);
	return v[i].f > v[j].s;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	FOR(t, 1, T+1)
	{
		cin >> n;
		FOR(i, 0, n)
		{
			cin >> v[i].s >> v[i].f;
		}
		vi adj[n];
		FOR(i, 0, n)
		{
			FOR(j, i+1, n)
			{
				if(overlap(i, j))
				{
					adj[i].emplace_back(j);
					adj[j].emplace_back(i);
				}
			}
		}
		can = true;
		vi color(n, -1);
		FOR(i, 0, n)
			if(color[i] == -1)
				DFS(i, 0, color, adj);
		printf("Case #%d: ", t);
		if(!can) printf("IMPOSSIBLE\n");
		else
		{		
			FOR(i, 0, n) 
			{ 
				printf("%c", color[i] ? 'C' : 'J');
			}
			putchar('\n');
		}
	}
	return 0;
}

