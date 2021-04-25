#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, int> ip;
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
#define LOGMAXN 23
#define MAXM 1000010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
 
const ll mod = 1000000007LL;
int n, q;

int x[MAXN];
int st[4*MAXN];

void update(int cur, int l, int r, int x, int v)
{
	if(l == r)
	{
		st[cur] = v;
		return ;
	}
	int m = (l+r)/2;
	int lc, rc;
	lc = 2*cur+1; rc = lc+1;
	if(x <= m)
		update(lc, l, m, x, v);
	else
		update(rc, m+1, r, x, v);
	st[cur] = st[lc]*st[rc];
}

int query(int cur, int l, int r, int ql, int qr)
{
	if(ql > r || qr < l)
		return 1;
	if(ql <= l && r <= qr)
	{
		return st[cur];
	}
	int m = (l+r)/2;
	int lc, rc;
	lc = 2*cur+1; rc = lc+1;
	int a = query(lc, l, m, ql, qr);
	int b = query(rc, m+1, r, ql, qr);
	return a*b;
}


int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> q)
	{
		memset(st, 0, sizeof(st));
		FOR(i, 0, n)
		{
			cin >> x[i];
			if(x[i] > 0) x[i] = 1;
			else if(x[i] < 0) x[i] = -1;
			update(0, 0, n-1, i, x[i]);
		}
		char c;
		int a, b;
		FOR(i, 0, q)
		{
			cin >> c >> a >> b;
			a--;
			if(c == 'P')
			{
				b--;
				int ans = query(0, 0, n-1, a, b);
				printf("%c", (ans == 0 ? '0' : (ans > 0 ? '+' : '-')));
			}
			else
			{
				if(b > 0) b = 1;
				else if(b < 0) b = -1;
				update(0, 0, n-1, a, b);
			}	
		}
		putchar('\n');
	}
	return 0;
}