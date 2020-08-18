#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
#define MAXN 100010
#define LOGMAXN 21
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

int n;
int x, y;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> x >> y)
	{
		cin >> n;
		int t = y;
		int a, b;
		ld f, acc;
		acc = 0.0;
		FOR(i, 0, n)
		{
			cin >> a >> b >> f;
			t -= (b-a);
			acc += (b-a)*f;
		}
		ld ans = (ld) x/((ld) acc + t);
		printf("%.10Lf\n", ans);
	}
	return 0;
}