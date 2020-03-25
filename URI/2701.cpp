#include <bits/stdc++.h>

#define MOD 1000000007
#define mp(a, b) make_pair(a, b)

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int n;
struct gate
{
	int pa, pb, s;
};
gate v[100010];
ll dp[100010][5][5];

vector<vector<ii>> comb(3);

ll B(int cur, int p, int e)
{
	if(cur == -1)
		return (p == e ? 1 : 0);
	if(dp[cur][p][e] == -1LL)
	{
		ll ans = 0LL;
		if(v[cur].s == -1)
		{
			for(ii x : comb[p])
			{
				for(ii y : comb[e])
				{
					ans = (ans + (B(v[cur].pa, x.first, y.first)*B(v[cur].pb, x.second, y.second))%MOD)%MOD;
				}
			}
		}
		else if(v[cur].s == p)
		{
			for(ii x : comb[2])
			{
				for(ii y : comb[e])
				{
					ans = (ans + (B(v[cur].pa, x.first, y.first)*B(v[cur].pb, x.second, y.second))%MOD)%MOD;
				}
			}
		}
		dp[cur][p][e] = ans;
	}
	return dp[cur][p][e];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	comb[0].push_back(mp(1, 1));
	comb[1].push_back(mp(0, 0));
	comb[1].push_back(mp(0, 1));
	comb[1].push_back(mp(1, 0));
	comb[2].push_back(mp(0, 0));
	comb[2].push_back(mp(0, 1));
	comb[2].push_back(mp(1, 0));
	comb[2].push_back(mp(1, 1));
	while(cin >> n)
	{
		for(int i = 0; i < n; ++i)
		{
			cin >> v[i].pa >> v[i].pb >> v[i].s;
			v[i].pa--, v[i].pb--;
		}
		memset(dp, -1LL, sizeof(dp));
		printf("%lld\n", (B(0, 1, 0) + B(0, 0, 1))%MOD);
	}
	return 0;
}