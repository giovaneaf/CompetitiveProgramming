/*
	Top-down DP approach
*/

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
#define MAXN 210
#define LOGMAXN 20
#define MAXM 250010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

ll mod = 1000000007LL;

int n;
pair<ll, ll> memo[4*MAXN][4*MAXN];
bool calc[4*MAXN][4*MAXN];
string c[4*MAXN];
string add, mult, sub;

pair<ll, ll> getExtremes(int split, pair<ll, ll> p1, pair<ll, ll> p2)
{
	pair<ll, ll> ans = mp(INFLL, -INFLL);
	if(c[split] == add)
	{
		ans.fst = min(ans.fst, p1.fst+p2.fst);
		ans.fst = min(ans.fst, p1.fst+p2.snd);
		ans.fst = min(ans.fst, p1.snd+p2.fst);
		ans.fst = min(ans.fst, p1.snd+p2.snd);
		ans.snd = max(ans.snd, p1.fst+p2.fst);
		ans.snd = max(ans.snd, p1.fst+p2.snd);
		ans.snd = max(ans.snd, p1.snd+p2.fst);
		ans.snd = max(ans.snd, p1.snd+p2.snd);
	}
	else if(c[split] == mult)
	{
		ans.fst = min(ans.fst, p1.fst*p2.fst);
		ans.fst = min(ans.fst, p1.fst*p2.snd);
		ans.fst = min(ans.fst, p1.snd*p2.fst);
		ans.fst = min(ans.fst, p1.snd*p2.snd);
		ans.snd = max(ans.snd, p1.fst*p2.fst);
		ans.snd = max(ans.snd, p1.fst*p2.snd);
		ans.snd = max(ans.snd, p1.snd*p2.fst);
		ans.snd = max(ans.snd, p1.snd*p2.snd);
	}
	else if(c[split] == sub)
	{
		ans.fst = min(ans.fst, p1.fst-p2.fst);
		ans.fst = min(ans.fst, p1.fst-p2.snd);
		ans.fst = min(ans.fst, p1.snd-p2.fst);
		ans.fst = min(ans.fst, p1.snd-p2.snd);
		ans.snd = max(ans.snd, p1.fst-p2.fst);
		ans.snd = max(ans.snd, p1.fst-p2.snd);
		ans.snd = max(ans.snd, p1.snd-p2.fst);
		ans.snd = max(ans.snd, p1.snd-p2.snd);
	}
	else
	{
		ans.fst = min(ans.fst, p1.fst+p2.fst);
		ans.fst = min(ans.fst, p1.fst+p2.snd);
		ans.fst = min(ans.fst, p1.snd+p2.fst);
		ans.fst = min(ans.fst, p1.snd+p2.snd);
		ans.fst = min(ans.fst, p1.fst*p2.fst);
		ans.fst = min(ans.fst, p1.fst*p2.snd);
		ans.fst = min(ans.fst, p1.snd*p2.fst);
		ans.fst = min(ans.fst, p1.snd*p2.snd);
		ans.fst = min(ans.fst, p1.fst-p2.fst);
		ans.fst = min(ans.fst, p1.fst-p2.snd);
		ans.fst = min(ans.fst, p1.snd-p2.fst);
		ans.fst = min(ans.fst, p1.snd-p2.snd);
		ans.snd = max(ans.snd, p1.fst+p2.fst);
		ans.snd = max(ans.snd, p1.fst+p2.snd);
		ans.snd = max(ans.snd, p1.snd+p2.fst);
		ans.snd = max(ans.snd, p1.snd+p2.snd);
		ans.snd = max(ans.snd, p1.fst*p2.fst);
		ans.snd = max(ans.snd, p1.fst*p2.snd);
		ans.snd = max(ans.snd, p1.snd*p2.fst);
		ans.snd = max(ans.snd, p1.snd*p2.snd);
		ans.snd = max(ans.snd, p1.fst-p2.fst);
		ans.snd = max(ans.snd, p1.fst-p2.snd);
		ans.snd = max(ans.snd, p1.snd-p2.fst);
		ans.snd = max(ans.snd, p1.snd-p2.snd);
	}
	return ans;
}

pair<ll, ll> solve(int l, int r)
{
	if(l >= 2*n)
	{
		l -= 2*n; r -= 2*n;
	}
	if(l == r)
	{
		return mp(stoll(c[l]), stoll(c[l]));
	}
	if(!calc[l][r])
	{
		pair<ll, ll> ans = mp(INFLL, -INFLL);
		pair<ll, ll> p1, p2, tmp;
		for(int k = l+1; k < r; k += 2)
		{
			p1 = solve(l, k-1); 
			p2 = solve(k+1, r);
			tmp = getExtremes(k, p1, p2);
			ans.fst = min(ans.fst, tmp.fst);
			ans.snd = max(ans.snd, tmp.snd);
		}
		memo[l][r] = ans;
		calc[l][r] = true;
	}
	return memo[l][r];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	add = '+';
	mult = '*';
	sub = '-';
	while(cin >> n)
	{
		memset(memo, -1LL, sizeof(memo));
		memset(calc, false, sizeof(calc));
		FOR(i, 0, 2*n)
		{
			cin >> c[i];
			c[2*n+i] = c[i];
		}
		int l, r;
		string ans;
		pair<ll, ll> p;
		for(int i = 0; i < 2*n; i += 2)
		{
			l = i; r = (i + 2*n-2);
			p = solve(l, r);
			ans += to_string(abs(p.fst)) + to_string(abs(p.snd));
		}
		cout << ans << '\n';
	}
	return 0;
}
