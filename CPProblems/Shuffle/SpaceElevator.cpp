/*
https://www.urionlinejudge.com.br/judge/pt/problems/view/1226
Binary search the answer. Compute how many numbers don't have 4 or 13 and are less than or equal to x.
You can use dynamic programming to compute for each binary search iteration how many values are less than equal to x
and don't have any 4 or 13. You can use a dp(pos, limit, one) that stores how many numbers are possible to do starting
at that state and going until de end, where pos is the position of the digit, limit is needed to check if you can exceed
the actual digit number and one is to check if the last digit was one, if it's one then you can't choose the number 3.
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 510
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9
#define comp(a, b) ((a)+(b))

ull n;
ull dp[20][2][2];
int sz;

ull solve(int pos, bool one, bool tight, string& s)
{
	if(pos == sz) return 1ULL;
	if(dp[pos][one][tight] == 15000000000000000000ULL)
	{
		ull ans = 0ULL;
		FOR(i, 0, 10)
		{
			if(tight && (s[pos]-'0' < i)) break;
			if(i == 4 || (one && i == 3)) continue;
			ans += solve(pos+1, i == 1, tight && ((s[pos] - '0') == i), s);
		}
		dp[pos][one][tight] = ans;
	}
	return dp[pos][one][tight];
}

void filldp()
{
    for(int i = 0; i < 20; ++i)
        for(int j = 0; j < 2; ++j)
            for(int k = 0; k < 2; ++k)
                dp[i][j][k] = 15000000000000000000ULL;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		ull l = 1ULL;
		ull h = 10000000000000000000ULL;
		string s;
		ull num;
		while(h - l > 1)
		{
			ull mid = l + (h-l)/2;
			s = to_string(mid);
			sz = (int) s.size();
			filldp();
			num = solve(0, false, true, s);
			if(num >= n+1) h = mid;
			else l = mid+1ULL;
		}
		s = to_string(l);
		sz = (int) s.size();
		filldp();
		num = solve(0, false, true, s);
		printf("%llu\n", num == n+1 ? l : h);
	}
	return 0;
} 