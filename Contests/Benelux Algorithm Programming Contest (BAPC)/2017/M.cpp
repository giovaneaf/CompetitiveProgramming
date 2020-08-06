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
#define MAXN 100010
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL
 
#define ITER 1000000
#define DEBUG 0
 
int n, m;
int T[MAXN];
int R[MAXN];
int v[MAXN];
ii p[MAXN];
 
bool cmp(const int a, const int b)
{
	return v[a] < v[b];
}
 
int LIS()
{
	int len;
	len = 1;
	memset(R, -1, sizeof(R));
	T[0] = 0;
	FOR(i, 1, n)
	{
		if(v[i] < v[T[0]])
		{
			T[0] = i;
		}
		else
		{
			int ceiling = distance(T, upper_bound(T, T+len, i, cmp));
			T[ceiling] = i;
			len = max(len, ceiling+1);
			R[i] = T[ceiling-1];
		}
	}
	return len;
}
 
bool cmp1(const ii a, const ii b)
{
	if(a.fst == b.fst) return a.snd > b.snd;
	return a.fst < b.fst; 
}
 
bool cmp2(const ii a, const ii b)
{
	if(a.fst == b.fst) return a.snd < b.snd;
	return a.fst > b.fst; 
}
 
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	while(cin >> n)
	{
		int xh, yh, xw, yw;
		cin >> xh >> yh >> xw >> yw;
		int minx, maxx, miny, maxy;
		minx = min(xh, xw);
		maxx = max(xh, xw);
		miny = min(yh, yw);
		maxy = max(yh, yw);
		int sz = 0;
		FOR(i, 0, n)
		{
			cin >> p[sz].fst >> p[sz].snd;
			if(minx <= p[sz].fst && p[sz].fst <= maxx && miny <= p[sz].snd && p[sz].snd <= maxy)
				sz++;
		}
		n = sz;
		if(n == 0)
		{
			printf("0\n");
			continue;
		}
		if(xh <= xw)
		{
			if(yh <= yw)
			{
				sort(p, p+n);
				FOR(i, 0, n) v[i] = p[i].snd;
			}
			else
			{
				sort(p, p+n, cmp1);
				FOR(i, 0, n) v[i] = p[i].snd;
				reverse(v, v+n);
			}
		}
		else
		{
			if(yh <= yw)
			{
				sort(p, p+n, cmp2);
				FOR(i, 0, n) v[i] = p[i].snd;
			}
			else
			{
				sort(p, p+n, greater<ii>());
				FOR(i, 0, n) v[i] = p[i].snd;
				reverse(v, v+n);
			}
		}
		printf("%d\n", LIS());
	}
	return 0;
}