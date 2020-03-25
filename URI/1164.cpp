#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define MAXN 300010
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	FOR(i, 0, n)
	{
		int x;
		cin >> x;
		ll ans = 1;
		for(int i = 2; i <= round(sqrt(x)); ++i)
		{
			if(x%i == 0)
			{
				ans += i;
				if(x/i != i) ans += x/i;
			}
		}
		if(x == 1) ans = 0;
		printf("%d %seh perfeito\n", x, (ans == x ? "" : "nao "));
	}
	return 0;
}
