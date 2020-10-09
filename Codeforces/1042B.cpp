#include <bits/stdc++.h>

#define mp(a, b) make_pair(a, b)

#define MAXN 1010
#define LOGMAXN 20
#define MOD 1000000007
#define INF 1e9
#define EPS 1e-9

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef pair<int, bool> ib;

int n;
int C[MAXN];
int V[MAXN];
int dp[MAXN][(1 << 3)+5];

int solve(int pos, int mask)
{
	if(pos == n)
	{
		if(mask == (1 << 3) - 1) return 0;
		else return INF;
	}
	if(dp[pos][mask] != -1) return dp[pos][mask];
	int ans = solve(pos+1, mask | V[pos]);
	if(ans != INF)
		ans += C[pos];
	ans = min(ans, solve(pos+1, mask));
	return dp[pos][mask] = ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		for(int i = 0; i < n; ++i)
		{
			cin >> C[i];
			string s;
			cin >> s;
			V[i] = 0;
			for(int j = 0; j < s.size(); ++j)
			{
				V[i] |= (1 << (s[j]-'A'));
			}
		}
		memset(dp, -1, sizeof(dp));
		int ans = solve(0, 0);
		cout << (ans == INF ? -1 : ans) << '\n';
	}
	return 0;
}