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
#define LOGMAXN 21
#define MAXM 250010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

ll mod = 1000000007LL;

int n, m;
int quad[MAXN];
int nlog[MAXN];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		FOR(i, 0, n) cin >> quad[i];
		FOR(i, 0, n) cin >> nlog[i];
		sort(quad, quad+n);
		sort(nlog, nlog+n);
		int pq, pn;
		pq = pn = 0;
		int ans = 0;
		while(pq < n && pn < n)
		{
			while(pn < n && nlog[pn] <= quad[pq]) pn++;
			if(pn < n)
			{
				pn++; ans++;
			}
			pq++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
