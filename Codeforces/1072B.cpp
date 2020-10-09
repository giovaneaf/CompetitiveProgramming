#include <bits/stdc++.h>

#define mp(a, b) make_pair(a, b)

#define MAXN 100010
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
typedef vector<ii> vii;

int n;
int a[MAXN];
int b[MAXN];
int dp[MAXN][6];
int ans[MAXN];

bool solve(int cur, int last)
{
	if(cur == n) return true;
	if(dp[cur][last] != -1) return dp[cur][last];
	bool can = false;
	for(int i = 0; i <= 3; ++i)
	{
		if(((last|i) == a[cur-1]) && ((last&i) == b[cur-1]))
		{
			if(solve(cur+1, i))
			{
				ans[cur] = i;
				can = true;
				break;
			}
		}
	}
	return dp[cur][last] = can;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		for(int i = 0; i < n-1; ++i)
			cin >> a[i];
		for(int i = 0; i < n-1; ++i)
			cin >> b[i];
		memset(dp, -1, sizeof(dp));
		bool can = false;
		for(int i = 0; i <= 3; ++i)
		{
			if(solve(1, i))
			{
				printf("YES\n");
				printf("%d", i);
				for(int j = 1; j < n; ++j)
				{
					printf(" %d", ans[j]);
				}
				printf("\n");
				can = true;
				break;
			}
		}
		if(!can)
		{
			printf("NO\n");
		}
	}
	return 0;
}