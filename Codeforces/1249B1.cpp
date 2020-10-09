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
#define MAXN 200010
#define LOGMAXN 20
#define MAXM 1000010
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL

#define DEBUG 0

int p[MAXN];
int dad[MAXN];
int ans[MAXN];
bool seen[MAXN];

void DFS(int cur, int sz)
{
	seen[cur] = true;
	if(!seen[p[cur]])
	{
		dad[p[cur]] = cur;
		DFS(p[cur], sz+1);
	}
	else
	{
		int node = cur;
		while(node != -1)
		{
			ans[node] = sz;
			node = dad[node];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		FOR(i, 0, n) 
		{
			cin >> p[i];
			p[i]--;
		}
		fill(ans, ans+n, -1);
		fill(dad, dad+n, -1);
		fill(seen, seen+n, false);
		FOR(i, 0, n)
		{
			if(!seen[i])
			{
				DFS(i, 1);
			}
		}
		FOR(i, 0, n)
		{
			if(i > 0) putchar(' ');
			printf("%d", ans[i]);
		}
		putchar('\n');
	}
	return 0;
}

