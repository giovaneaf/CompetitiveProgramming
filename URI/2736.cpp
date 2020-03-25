#include <bits/stdc++.h>

#define INF 1e9
#define MAXN 200030
#define MOD 1000000007
#define mp(a, b) make_pair(a, b)

using namespace std;
typedef long long ll;
typedef unsigned long long int ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;

ull dp[21][2][2];
string s;
int m, y11, y22;

ull solve(int pos, bool tight, bool res)
{
	if(pos == s.size()) return 1ULL;
	if(dp[pos][tight][res] == 15000000000000000000ULL)
	{
		ull ans = 0;
		for(int i = 0; i < 10; ++i)
		{
			if(i == m || (tight && ((i + '0') > s[pos])) || (res && i == y22)) continue;
			ans += solve(pos+1, tight && ((i + '0') == s[pos]), i == y11);
		}
		dp[pos][tight][res] = ans;
	}
	return dp[pos][tight][res];
}

void filldp()
{
    for(int i = 0; i < 21; ++i)
        for(int j = 0; j < 2; ++j)
            for(int k = 0; k < 2; ++k)
                dp[i][j][k] = 15000000000000000000ULL;
}

int main()
{
    ull n;
    while(scanf("%llu", &n) != EOF)
    {
		int y;
		scanf("%d %d", &m, &y);
		y22 = y%10;
		y /= 10;
		y11 = y%10;
    	ull l = 0ULL;
    	ull h = 10000000000000000000ULL;
    	while(h - l > 1ULL)
    	{
    		ull mid = l + (h-l)/2;
    		filldp();
    		s = to_string(mid);
    		ull ans = solve(0, true, false);
			if(ans >= n+1)
			{
				h = mid;
			}
			else
			{
				l = mid+1ULL;
			}
    	}
		s = to_string(l);
		filldp();
		printf("%llu\n", (solve(0, true, false) == n+1 ? l : h));
    }
	return 0;
}