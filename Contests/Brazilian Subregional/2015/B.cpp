#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
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
#define MAXM 44100
#define LOGMAXN 20
#define INF 1e9+7
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL

ll n, c;
ll memo[MAXN][3];
ll v[MAXN];

ll solve(int pos, int b)
{
	if(pos == n)
		return 0LL;
	if(memo[pos][b] == -INFLL)
	{
		ll ans = solve(pos+1, b);
		if(b == 1)
			ans = max(ans, v[pos] + solve(pos+1, 0));
		else
			ans = max(ans, -v[pos] - c + solve(pos+1, 1));
		memo[pos][b] = ans;
	}
	return memo[pos][b];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n >> c)
    {
		FOR(i, 0, n)
		{
			cin >> v[i];
			FOR(j, 0, 3)
				memo[i][j] = -INFLL;
		}
		printf("%lld\n", solve(0, 0));
    }
    return 0;
}