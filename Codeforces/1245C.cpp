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
#define LOGMAXN 20
#define MAXM 1000010
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL

int n;
string s;
ll memo[MAXN];

ll solve(int cur)
{
	if(cur >= n) return 1LL;
	if(memo[cur] == -1LL)
	{
		ll ans = solve(cur+1);
		if(cur < n-1 && ((s[cur] == 'u' && s[cur+1] == 'u') || (s[cur] == 'n' && s[cur+1] == 'n')))
		{
			ans = (ans + solve(cur+2))%MOD;
		}
		memo[cur] = ans;
	}
	return memo[cur];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> s)
	{
		n = (int) s.size();
		bool can = true;
		FOR(i, 0, n)
		{
			if(s[i] == 'm' || s[i] == 'w')
			{
				can = false;
				break;
			}
		}
		fill(memo, memo+n+1, -1LL);
		if(!can)
			printf("0\n");
		else
			printf("%lld\n", solve(0));
	}
	return 0;
}
