#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
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
#define MAXN 3001
#define LOGMAXN 20
#define MAXM 1000010
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m, d;
	while(cin >> n >> m >> d)
	{
		int sum = 0;
		vi ans(n+2, 0);
		vi c(m);
		FOR(i, 0, m)
		{
			cin >> c[i];
			sum += c[i];
		}
		int plat = 0;
		int pos = 0;
		while(plat < m && pos <= n && n-(pos+d)+1 > sum)
		{
			//printf("%d %d %d %d\n", pos, plat, n-(pos+d)+1, sum);
			FOR(i, 0, c[plat])
			{
				ans[pos+d+i] = plat+1;
			}
			sum -= c[plat];
			pos = pos+d+c[plat]-1;
			c[plat] = 0;
			plat++;
		}
		int start = n;
		RFOR(i, m-1, 0)
		{
			if(c[i] == 0) break;
			FOR(j, 0, c[i]) ans[start--] = i+1;
		}
		bool can = true;
		RFOR(i, n, 1)
		{
			if(ans[i])
			{
				if(n+1-i > d)
				{
					can = false;
				}
				break;
			}
		}
		if(!can)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		FOR(i, 1, n+1)
		{
			if(i > 1) putchar(' ');
			printf("%d", ans[i]);
		}
		putchar('\n');
	}
	return 0;
}
