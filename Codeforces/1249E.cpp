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
#define MAXN 200010
#define LOGMAXN 20
#define MAXM 1000010
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL

#define DEBUG 0

ll n, c;
ll a[MAXN];
ll b[MAXN];
ll memo[MAXN][2];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> c)
	{
		FOR(i, 1, n)
		{
			cin >> a[i];
		}
		FOR(i, 1, n)
		{
			cin >> b[i];
		}
		memo[0][0] = 0;
		memo[0][1] = c;
		printf("0");
		FOR(i, 1, n)
		{
			memo[i][0] = min(memo[i-1][0] + a[i], memo[i-1][1] + min(a[i], b[i]));
			memo[i][1] = min(memo[i-1][0] + b[i] + c, min(memo[i-1][1] + b[i], min(memo[i-1][0], memo[i-1][1]) + a[i] + c));
			printf(" %lld", min(memo[i][0], memo[i][1]));
		}
		putchar('\n');
	}
	return 0;
}

