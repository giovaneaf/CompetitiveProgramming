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
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007LL
 
#define ITER 1000000
#define DEBUG 0
 
int n, m;
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	while(cin >> n >> m)
	{
		vi v(n, 0);
		int a, b, c;
		FOR(i, 0, m)
		{
			cin >> a >> b >> c;
			v[a] -= c;
			v[b] += c;
		}
		vi sum(1 << n, 0);
		vi memo(1 << n, 0);
		FOR(i, 0, (1 << n))
		{
			FOR(j, 0, n)
			{
				if(i & (1 << j))
				{
					sum[i] += v[j];
				}
			}
		}
		int mask;
		FOR(i, 0, (1 << n))
		{
			FOR(j, 0, n)
			{
				if((i & (1 << j)) == 0)
				{
					mask = i | (1 << j);
					memo[mask] = max(memo[mask], memo[i] + (sum[mask] == 0 ? 1 : 0));
				}
			}
		}
		printf("%d\n", n - memo[(1 << n)-1]);
	}
	return 0;
}