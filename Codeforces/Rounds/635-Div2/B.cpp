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
#define MAXN 100010
#define LOGMAXN 20
#define MAXM 110
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007
 
int T;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	int x, n, m;
	FOR(t, 1, T+1)
	{
		cin >> x >> n >> m;
		FOR(i, 0, n) x = min(x/2 + 10, x);
		FOR(i, 0, m) x -= 10;
		printf("%s\n", x <= 0 ? "YES" : "NO");
	}
	return 0;
}