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
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007

int T, n, l, ans, rem, votes, aux, tmp, minimum;
int v;
int memo[MAXN];

int solve(int votes)
{
	if(votes == n+1) return INF;
	if(memo[votes] == -1)
	{
		rem = (100*votes)%n;
		if(2*rem >= n) return memo[votes] = 0;
		tmp = solve(votes+1);
		if(tmp < INF) tmp++;
		memo[votes] = tmp;
	}
	return memo[votes];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	FOR(t, 1, T+1)
	{
		cin >> n >> l;
		votes = n;
		memset(memo, -1, sizeof(memo));
		FOR(i, 0, n+1) solve(i);
		ans = 0;
		multiset<ii> s;
		minimum = memo[0];
		FOR(i, 0, l)
		{
			cin >> v;
			votes -= v;
			if(memo[v] == 0)
			{
				ans += (100*v)/n + 1;	
			}
			else 
			{
				if(memo[v] < minimum)
				{
					s.insert(mp(memo[v], v));
				}
				else
					ans += (100*v)/n;
			}
		}
		for(auto it = s.begin(); it != s.end(); ++it)
		{
			aux = it->second + min(it->first, votes);
			votes = max(0, votes - it->first);
			ans += (100*aux)/n;
			if(memo[aux] == 0) ans++;
		}
		while(votes > 0)
		{
			aux = min(votes, memo[0]);
			votes = max(0, votes - memo[0]);
			ans += (100*aux)/n;
			if(memo[aux] == 0) ans++;
		}
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}

