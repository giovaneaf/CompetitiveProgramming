#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define MAXN 200010
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9

int n;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		int mn = INF;
		int ans = 0;
		for(int i = 0; i < n; ++i)
		{
			int a, b;
			cin >> a >> b;
			mn = min(mn, b);
			ans += (mn*a);
		}
		printf("%d\n", ans);
	}
	return 0;
}