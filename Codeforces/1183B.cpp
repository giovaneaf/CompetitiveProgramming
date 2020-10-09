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
#define MAXN 10010
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int Q, n, k, a, mn, mx;
	cin >> Q;
	while(Q--)
	{
		mn = INF;
		mx = -INF;
		cin >> n >> k;
		FOR(i, 0, n)
		{
			cin >> a;
			mn = min(mn, a);
			mx = max(mx, a);
		}
		if(mn + 2*k < mx)
		{
			printf("-1");
		}
		else
		{
			printf("%d", mn + k);
		}
		putchar('\n');
	}
	return 0;
}

