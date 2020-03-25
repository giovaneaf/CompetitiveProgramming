#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 100010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9
 
int n, m, q;
 
vi st[4*MAXN];
ii v[MAXN];
int arr[MAXN];
 
void init(int cur, int l, int r)
{
	if(l == r)
	{
		st[cur].push_back(v[l].snd);
		return ;
	}
	int mid = (l+r)>>1;
	int left = (cur<<1) + 1;
	int right = left + 1;
	init(left, l, mid);
	init(right, mid+1, r);
	merge(st[left].begin(), st[left].end(),
		  st[right].begin(), st[right].end(),
		  back_inserter(st[cur]));
}
 
int query(int cur, int l, int r, int ql, int qr, int k)
{
	if(l == r)
	{
		return st[cur][0];
	}
	int mid = (l+r)>>1;
	int left = (cur<<1) + 1;
	int right = left + 1;
	int e = (upper_bound(st[left].begin(), st[left].end(), qr)) - st[left].begin();
	int s = (lower_bound(st[left].begin(), st[left].end(), ql)) - st[left].begin();
	int sz = e-s;
	if(sz >= k)
	{
		return query(left, l, mid, ql, qr, k);
	}
	else
	{
		return query(right, mid+1, r, ql, qr, k-sz);
	}
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	FOR(i, 0, n) 
	{
		cin >> v[i].fst;
		arr[i] = v[i].fst;
		v[i].snd = i;
	}
	sort(v, v+n);
	init(0, 0, n-1);
	FOR(i, 0, q)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		printf("%d\n", arr[query(0, 0, n-1, a, b, c)]);
	}
	return 0;
}  