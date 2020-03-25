#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

#define EPS 1e-9
#define MAXN 1010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int INF = 1e9;
const ll llINF = 1e18;
const int mod = 1000000;
int n, m;
string s[MAXN];
int dp[MAXN][MAXN];
int car[MAXN][MAXN];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m)
	{
		FOR(i, 0, n) cin >> s[i];
		FOR(i, 0, n) dp[i][0] = car[i][0] = 0;
		FOR(j, 1, m) dp[0][j] = car[0][j] = 0;
		FOR(i, 1, n+1)
		{
			FOR(j, 1, m+1)
			{
				dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1];
				dp[i][j] += ((s[i-1][j-1] == 'C') ? 25 : 12);
				car[i][j] = car[i][j-1] + car[i-1][j] - car[i-1][j-1];
				car[i][j] += (s[i-1][j-1] == 'C');
			}
		}
		int l;
		cin >> l;
		int sqr = l*l;
		int mx = -1;
		RFOR(i, n-l+1, 1)
		{
			RFOR(j, m-l+1, 1)
			{
				int cars = car[i+l-1][j+l-1] - car[i+l-1][j-1] - car[i-1][j+l-1] + car[i-1][j-1];
				if(cars < sqr && cars > 0)
				{
					int fuel = dp[i+l-1][j+l-1] - dp[i+l-1][j-1] - dp[i-1][j+l-1] + dp[i-1][j-1];
					mx = max(mx, fuel);
				}
			}
		}
		printf("%d\n", mx);
	}
	return 0;
}