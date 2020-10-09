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
#define MAXN 5010
#define LOGMAXN 20
#define MAXM 1000010
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL

#define ITER 10000000

#define DEBUG 0

int memo[101][2][2][9];
int n;
string s;

int solve(int pos, bool used, bool valid, int rem)
{
	if(pos == n) return valid && (rem == 0);
	if(memo[pos][used][valid][rem] == -1)
	{
		int nrem = (used ? ((rem*10 + s[pos]-'0')%8) : rem);
		int ans = max(solve(pos+1, false, valid || used, nrem), solve(pos+1, true, true, nrem));
		memo[pos][used][valid][rem] = ans;
	}
	//printf("%d %d %d %d = %d\n", pos, used, valid, rem, memo[pos][used][valid][rem]);
	return memo[pos][used][valid][rem];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> s)
	{
		memset(memo, -1, sizeof(memo));
		n = (int) s.size();
		FOR(i, 0, 2)
		{
			solve(0, i == 1, i == 1, 0);
		}
		if(memo[0][false][false][0] == 1 || memo[0][true][true][0] == 1)
		{
			string ans;
			bool valid = false;
			int rem = 0;			
			FOR(i, 0, (int) s.size())
			{
				if(memo[i][true][true][rem] == 1)
				{
					ans += s[i];
					rem = (rem*10 + s[i]-'0')%8;
				}
			}
			if((int) ans.size() > 0)
			{
				printf("YES\n");
				printf("%s\n", ans.c_str());
			}
			else
				printf("NO\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}
