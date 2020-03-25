#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define MAXN 35
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9

int n, m, k;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> k >> m)
	{
		if(n == 0 && k == 0 && m == 0) break;
		vb seen(n, false);
		int c, cc;
		c = 0; cc = n-1;
		int mark = 0;
		while(mark < n)
		{
			int cnt = 0;
			while(cnt < k)
			{
				cc = (cc == n-1 ? 0 : cc+1);
				if(!seen[cc]) cnt++;
			}
			cnt = 0;
			while(cnt < m)
			{
				c = (c == 0 ? n-1 : c-1);
				if(!seen[c]) cnt++;
			}
			seen[c] = seen[cc] = true;
			printf("%3d", cc+1);
			mark++;
			if(c != cc)
			{
				printf("%3d", c+1);
				mark++;
			}
			if(mark < n) printf(",");
		}
		printf("\n");
	}
	return 0;
}