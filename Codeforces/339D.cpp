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
#define MAXM 100010
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL
 
#define ITER 10000000
 
#define DEBUG 0

int n, m;
int v[MAXN];
int st[4*MAXN];

void init(int cur, int l, int r, bool isOr)
{
	if(l > r) return ;
	if(l == r)
	{
		st[cur] = v[l];
		return ;
	}
	int mid = (l+r)/2;
	int lc = 2*cur + 1;
	int rc = lc + 1;
	init(lc, l, mid, !isOr); init(rc, mid+1, r, !isOr);
	if(isOr)
		st[cur] = st[lc] | st[rc];
	else
		st[cur] = st[lc] ^ st[rc];
}

int query(int cur, int l, int r, int x, bool isOr, int v)
{
	if(l > r) return 0;
	if(l == r)
	{
		return st[cur] = v;
	}
	int mid = (l+r)/2;
	int lc = 2*cur + 1;
	int rc = lc + 1;
	if(x <= mid)
	{
		query(lc, l, mid, x, !isOr, v);
	}
	else
	{
		query(rc, mid+1, r, x, !isOr, v);
	}
	if(isOr)
		st[cur] = st[lc] | st[rc];
	else
		st[cur] = st[lc] ^ st[rc];
	return st[cur];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m)
	{
		bool isOr = ((n%2) > 0);
		n = (1 << n);
		FOR(i, 0, n)
		{
			cin >> v[i];
		}
		init(0, 0, n-1, isOr);
		FOR(i, 0, m)
		{
			int a, b;
			cin >> a >> b;
			a--;
			// query
			int ans = query(0, 0, n-1, a, isOr, b);
			printf("%d\n", ans);
		}
	}
	return 0;
}