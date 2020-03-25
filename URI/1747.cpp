#include <bits/stdc++.h>
 
#define mp(a, b) make_pair(a, b)
 
#define MAXN 10010
#define LOGMAXN 20
#define MOD 1000000007
#define INF 1e9
#define EPS 1e-9
 
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef pair<int, bool> ib;
typedef vector<ii> vii;

int n, m;
set<ii> seen;
unordered_set<int> s;
int C[MAXN];
vi adj[MAXN];

void solve(int cur, int gcd, vi* adj, int* C)
{
	if(seen.find({cur, gcd}) == seen.end())
	{
		s.insert(gcd);
		seen.insert({cur, gcd});
		for(int i = 0; i < adj[cur].size(); ++i)
		{
			solve(adj[cur][i], __gcd(gcd, C[adj[cur][i]]), adj, C);
		}
	}
}
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; ++i)
	{
		cin >> C[i];
	}
	for(int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 0; i < n; ++i)
	{
		solve(i, C[i], adj, C);
	}
	cout << s.size() << '\n';		
}