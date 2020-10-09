#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

#define EPS 1e-9
#define MAXN 100010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int INF = 1e9;
const ll llINF = 1e18;
const int mod = 1000000;
const double pi = atan(1)*4.0;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while(cin >> n)
	{
		int a, b;
		for(int i = 1; i < n; ++i)
		{
			if(i >= n-i) break;
			if(__gcd(i, n-i) == 1)
			{
				a = i, b = n-i;
			}
		}
		printf("%d %d\n", a, b);
	}
	return 0;
}