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
	ll mem;
	while(cin >> mem)
	{
		cin >> n;
		int v[n];
		FOR(i, 0, n) cin >> v[i];
		int mask = 0;
		ll ans = 0;
		int sz = 0;
		FOR(i, 1, (1 << n))
		{
			ll tmp = 0;
			int cnt = 0;
			FOR(j, 0, n)
			{
				if((i & (1 << j)) > 0) 
				{
					tmp += v[j];
					cnt++;
				}
			}
			if(tmp <= mem && (ans < tmp || (ans == tmp && cnt > sz)))
			{
				ans = tmp;
				mask = i;
				sz = cnt;
			}
		}
		FOR(j, 0, n)
		{
			if((mask & (1 << j)) > 0)
				printf("%d ", v[j]);
		}
		printf("sum:%lld\n", ans);
	}
    return 0;
}