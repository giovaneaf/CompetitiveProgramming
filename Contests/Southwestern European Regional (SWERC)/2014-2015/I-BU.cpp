/*
	Bottom-up DP approach
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

int n, split;
pair<ll, ll> memo[4*MAXN][4*MAXN];
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

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	add = '+';
	mult = '*';
	sub = '-';
	while(cin >> n)
	{
		FOR(i, 0, 2*n)
		{
			cin >> c[i];
			c[2*n+i] = c[i];
		}
		int l, r, split;
		string ans;
		FOR(i, 0, 4*n)
		{
			FOR(j, 0, 4*n)
			{
				memo[i][j] = mp(INFLL, -INFLL);
			}
		}
		FOR(i, 0, n)
		{
			memo[2*i][2*i] = mp(stoll(c[2*i]), stoll(c[2*i]));
		}
		int add;
		for(int len = 1; len < n; len++)
		{
			for(int i = 0; i < n; ++i)
			{
				l = 2*i; r = (l + 2*len);
				add = 0;
				pair<ll, ll> tmp = mp(INFLL, -INFLL);
				for(int k = l+1; k < r; k += 2)
				{
					if(k+1 >= 2*n) add = 2*n;
					tmp = getExtremes(k, memo[l][k-1], memo[k+1-add][r-add]);
					memo[l][r].fst = min(memo[l][r].fst, tmp.fst);
					memo[l][r].snd = max(memo[l][r].snd, tmp.snd);
				}
			}
		}
		pair<ll, ll> p;
		for(int i = 0; i < 2*n; i += 2)
		{
			l = i; r = (i + 2*n-2);
			p = memo[l][r];
			ans += to_string(abs(p.fst)) + to_string(abs(p.snd));
		}
		cout << ans << '\n';
	}
	return 0;
}
