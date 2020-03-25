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

int n, m, q, k;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	string s;
	while(T--)
	{
		int v[25];
		int n;
		cin >> n;
		FOR(i, 0, n+1)
		{
			cin >> v[i];
		}
		n++;
		ll d, k;
		cin >> d >> k;
		ll nth = 1;
		while(nth*d < k)
		{
			k -= nth*d;
			//printf("%d %d\n", nth, k);
			nth++;
		}
		ll ans = v[0];
		ll pown = nth;
		FOR(i, 1, n)
		{
			ans += v[i]*pown;
			pown *= nth;
		}
		printf("%lld\n", ans);
	}
    return 0;
}