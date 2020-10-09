#include <bits/stdc++.h>

#define mp(a, b) make_pair(a, b)

#define MAXN 210
#define LOGMAXN 20
#define MOD 1000000007
#define INF 1e9
#define EPS 1e-9

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef pair<int, bool> ib;
typedef vector<ii> vii;

int w, h, k;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> w >> h >> k)
	{
		int ans = 2*(w+h-2);
		for(int i = 1; i < k; ++i)
		{
			w -= 4;
			h -= 4;
			ans += 2*(w+h-2);
		}
		cout << ans << '\n';
	}
	return 0;
}