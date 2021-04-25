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

int n, m;
int age[MAXN];
int dad[MAXN];
int party[MAXN];
int P[MAXN][LOGMAXN];
list<int> lst[MAXN];
int st[4*MAXN];

int query(int cur, int l, int r, int ql, int qr)
{
    int left = 2*cur+1;
    int right = 2*cur+2;
    if(ql > r || qr < l) return 0LL;
    if(l >= ql && r <= qr)
    {
        return st[cur];
    }
    int mid = (l + r) >> 1;
    int a = query(left, l, mid, ql, qr);
    int b = query(right, mid+1, r, ql, qr);
    st[cur] = st[right] + st[left];
    return a + b;
}

void update(int cur, int l, int r, int x, int val)
{
    int left = 2*cur+1;
    int right = 2*cur+2;
    if(l == r)
    {
        st[cur] += val;
        return;
    }
    int mid = (l + r) >> 1;
	if(x > mid)
		update(right, mid+1, r, x, val);
	else
		update(left, l, mid, x, val);
    st[cur] = st[left] + st[right];
}

void DFS(int cur, vi* adj)
{
	party[cur] = query(0, 0, MAXN-1, 0, age[cur]) + (int) lst[cur].size();
	for(int& x : lst[cur])
	{
		update(0, 0, MAXN-1, x, 1);
	}
	for(int& x : adj[cur])
	{
		DFS(x, adj);
	}
	for(int& x : lst[cur])
	{
		update(0, 0, MAXN-1, x, -1);
	}
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m)
	{
		memset(st, 0, sizeof(st));
		memset(P, -1, sizeof(P));
		vi adj[n];
		int a, b;
		cin >> a >> b;
		age[0] = a; dad[0] = -1;
		FOR(i, 1, n) 
		{
			cin >> a >> b;
			b--;
			age[i] = a; dad[i] = b;
			adj[b].push_back(i);
		}
		int o, l, r;
		FOR(i, 0, n) 
			P[i][0] = dad[i];
		FOR(j, 1, LOGMAXN)
			FOR(i, 0, n)
				if(P[i][j-1] > -1)
					P[i][j] = P[P[i][j-1]][j-1];
		FOR(i, 0, m)
		{
			cin >> o >> l >> r;
			o--;
			RFOR(j, LOGMAXN-1, 0)
			{
				if(P[o][j] > -1 && age[P[o][j]] <= r) o = P[o][j];
			}
			lst[o].push_back(l);
		}
		DFS(0, adj);
		FOR(i, 0, n)
		{
			if(i > 0) putchar(' ');
			printf("%d", party[i]);
		}
		putchar('\n');
	}
	return 0;
}