#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 40
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9


int n, m;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> m >> n)
	{
		if(n == 0 && m == 0) break;
		vi v(n);
		FOR(i, 0, n) cin >> v[i];
		int ans = m;
		FOR(i, 0, n)
		{
			auto it = upper_bound(v.begin(), v.end(), v[i]+m-1);
			//printf("%d %d %d %d\n", v[i], v[i]+m-1, *it, m - (int) distance(v.begin()+i, it));
			ans = min(ans, m - (int) distance(v.begin()+i, it));
		}
		printf("%d\n", ans);
	}
	return 0;
} 