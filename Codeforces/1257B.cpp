#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
#define MAXN 2010
#define LOGMAXN 20
#define MAXM 1000010
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL

int T;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> T)
	{
		while(T--)
		{
			int x, y;
			cin >> x >> y;
			if(x == 1 && y > 1)
			{
				printf("NO\n");
			}
			else if(y <= x)
			{
				printf("YES\n");
			}
			else if(x <= 3 && y <= 3)
			{
				printf("YES\n");
			}
			else if(x >= 4)
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}
	}
	return 0;
}
