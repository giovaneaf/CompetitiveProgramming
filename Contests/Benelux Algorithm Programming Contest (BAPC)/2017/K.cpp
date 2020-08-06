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
#define INF 0x3f3f3f3f
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL
 
#define ITER 1000000
#define DEBUG 0
 
int n, m;
int ans[MAXN];
int t;
bool valid;
 
void DFS(int cur, vi* adj, vb& seen)
{
	if(t == n-1)
	{
		valid = true;
		return ;
	}
	for(int& v : adj[cur])
	{
		if(!seen[v])
		{
			seen[v] = true;
			ans[t++] = v;
			DFS(v, adj, seen);
		}
	}
}
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	while(cin >> n)
	{
		string M;
		vi adj[n];
		FOR(i, 0, n)
		{
			cin >> M;
			FOR(j, 0, n)
			{
				if(M[j] == '1')
				{
					adj[i].emplace_back(j);
				}
			}
		}
		vb seen(n, false);
		t = 0;
		valid = false;
		seen[0] = true;
		DFS(0, adj, seen);
		if(!valid)
			printf("impossible\n");
		else
		{
			RFOR(i, n-2, 0)
			{
				printf("%d ", ans[i]);
			}
			printf("0\n");
		}
	}
	return 0;
}