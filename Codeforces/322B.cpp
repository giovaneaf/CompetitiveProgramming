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
#define MAXN 1000010
#define LOGMAXN 20
#define MAXM 1000010
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL

#define ITER 10000000

#define DEBUG 0


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int v[3];
	int ans = 0;
	int mn = 2;
	FOR(i, 0, 3)
	{
		cin >> v[i];
		mn = min(mn, v[i]);
	}
	for(int x = min(mn, 2); x >= 0; --x)
	{
		int tmp = x;
		FOR(j, 0, 3)
		{
			tmp += (v[j]-x)/3;
		}
		ans = max(tmp, ans);
	}
	printf("%d\n", ans);
	return 0;
}
