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
#define MAXN 1000010
#define LOGMAXN 23
#define MAXM 1110
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-6
#define MAXWORDS 1010
 
ll mod = 1000000007LL;

int T;
int n, m;

ii st[8*MAXN];
int lazy[8*MAXN];
int salary[MAXN];
vi adj[MAXN];
int dfsOrder[2*MAXN];
ii pp[MAXN];
int cnt;

void init(int cur, int l, int r)
{
    if(l > r)
        return ;
    lazy[cur] = 0;
    if(l == r)
    {
        st[cur] = mp(salary[dfsOrder[l]], salary[dfsOrder[l]]);
        return ;
    }
    int mid = (l + r) >> 1;
    int left = 2*cur+1;
    int right = 2*cur+2;
    init(left, l, mid);
    init(right, mid+1, r);
    st[cur] = mp(max(st[left].fst, st[right].fst), min(st[left].snd, st[right].snd));
}

ii query(int cur, int l, int r, int ql, int qr)
{
    int left = 2*cur+1;
    int right = 2*cur+2;
    if(lazy[cur] > 0)
    {
        st[cur] = mp(st[cur].fst + lazy[cur], st[cur].snd + lazy[cur]);
        if(l != r)
        {
            lazy[left] += lazy[cur];
            lazy[right] += lazy[cur];
        }
        lazy[cur] = 0;
    }
    if(ql > r || qr < l) return mp(-INF, INF);
    if(l >= ql && r <= qr)
    {
        return st[cur];
    }
    int mid = (l + r) >> 1;
    ii a = query(left, l, mid, ql, qr);
    ii b = query(right, mid+1, r, ql, qr);
    return mp(max(a.fst, b.fst), min(a.snd, b.snd));
}

void update(int cur, int l, int r, int ql, int qr, int val)
{
    int left = 2*cur+1;
    int right = 2*cur+2;
    if(lazy[cur] > 0)
    {
        st[cur] = mp(st[cur].fst + lazy[cur], st[cur].snd + lazy[cur]);
        if(l != r)
        {
            lazy[left] += lazy[cur];
            lazy[right] += lazy[cur];
        }
        lazy[cur] = 0;
    }
    if(ql > r || qr < l) return ;
    if(l >= ql && r <= qr)
    {
        st[cur] = mp(st[cur].fst + val, st[cur].snd + val);
        if(l != r)
        {
            lazy[left] += val;
            lazy[right] += val;
        }
        return;
    }
    int mid = (l + r) >> 1;
    update(left, l, mid, ql, qr, val);
    update(right, mid+1, r, ql, qr, val);
    st[cur] = mp(max(st[left].fst, st[right].fst), min(st[left].snd, st[right].snd));
}

void DFS(int cur, int dad)
{
	pp[cur].fst = cnt;
	dfsOrder[cnt++] = cur;
	for(int& v : adj[cur])
	{
		if(v == dad) continue;
		DFS(v, cur);
	}
	pp[cur].snd = cnt;
	dfsOrder[cnt++] = cur;
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> T)
	{
		while(T--)
		{
			cin >> n;
			int a, b;
			FOR(i, 1, n)
			{
				cin >> a;
				adj[a-1].push_back(i);
			}
			FOR(i, 0, n)
				cin >> salary[i];
			cnt = 0;
			DFS(0, -1);
			assert(cnt == 2*n);
			n = cnt;
			init(0, 0, n-1);
			cin >> m;
			char ch;
			FOR(i, 0, m)
			{
				cin >> ch;
				cin >> a;
				a--;
				if(ch == 'Q')
				{
					ii ppp = query(0, 0, n-1, pp[a].fst, pp[a].snd);
					printf("%d\n", ppp.fst - ppp.snd);
				}
				else
				{
					cin >> b;
					update(0, 0, n-1, pp[a].fst, pp[a].snd, b);
				}
			}
			FOR(i, 0, n)
				adj[i].clear();
		}
	}
	return 0;
}