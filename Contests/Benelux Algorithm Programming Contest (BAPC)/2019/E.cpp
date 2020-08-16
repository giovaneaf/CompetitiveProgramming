#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
#define LOGMAXN 21
#define MAXM 250010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

ll mod = 1000000007LL;
int n;
string s;
int memo[MAXN][2];

int solve(int pos, bool b)
{
	if(pos < 0) return b;
	if(memo[pos][b] == -1)
	{
		int ans = min(solve(pos-1, (s[pos]-'0'+b) == 10) + (s[pos]-'0'+b)%10, solve(pos-1, true) + 10 - (s[pos]-'0') - b);
		memo[pos][b] = ans;
	}
	return memo[pos][b];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> s)
	{
		memset(memo, -1, sizeof(memo));
		printf("%d\n", solve((int) s.size()-1, false));
	}
	return 0;
}
