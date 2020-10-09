#include <bits/stdc++.h>

#define MAXN 100010
#define INF 1e9
#define EPS 1e-9

#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define mp(a, b) make_pair(a, b)

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef long long ll;

struct point
{
	int x, y;
};

int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while(cin >> n)
	{
		point ans;
		ans.x = 0;
		ans.y = 0;
		int mx = 0;
		FOR(i, 0, n)
		{
			point p;
			cin >> p.x >> p.y;
			if(mx < p.x + p.y)
			{
				ans = p;
				mx = p.x + p.y;
			}
		}
		printf("%d\n", ans.y+ans.x);
	}
	return 0;
}