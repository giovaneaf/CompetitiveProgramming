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
#define MAXN 10010
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

ll d, h;
int b, n;
string l, s;
vi digits;
ll memo[60][2][2];

ll B(int pos, bool tight, bool sumZero)
{
	if(pos == n) return sumZero ? 0LL : 1LL;
	if(memo[pos][tight][sumZero] == -1LL)
	{
		ll ans = 0LL;
		for(int& digit : digits)
		{
			if(tight && s[pos] < digit + '0') break;
			ans += B(pos+1, tight && (digit + '0' == s[pos]), (sumZero && (digit == 0)));
		}
		if(digits[0] > 0 && sumZero)
		{
			ans += B(pos+1, tight && ('0' == s[pos]), sumZero);
		}
		memo[pos][tight][sumZero] = ans;
	}
	return memo[pos][tight][sumZero];
}

ll solve(ll x)
{
	s = "";
	while(x > 0LL)
	{
		s += (x%b)+'0';
		x /= b;
	}
	reverse(s.begin(), s.end());
	n = (int) s.size(); 
	memset(memo, -1LL, sizeof(memo));
	int zero = 0;
	if(digits[0] == 0) zero = 1;
	return B(0, true, true) + zero;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> d >> h >> b >> l)
	{
		if(d == -1) break;
		FOR(i, 0, (int) l.size())
		{
			if(l[i] == 'S') digits.emplace_back(i);
		}
		if(digits.empty())
			printf("0\n");
		else
			printf("%lld\n", solve(h) - solve(d-1));
		digits.clear();
	}
	return 0;
}
