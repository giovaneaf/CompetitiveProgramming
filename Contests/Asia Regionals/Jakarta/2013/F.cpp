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
#define MAXN 50010
#define LOGMAXN 20
#define MAXM 250010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

ll mod = 1000000007LL;

int T, n;
string s;
ll h[MAXN];
ll pw[MAXN];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	ll p = 31LL;
	FOR(t, 0, T)
	{
		cin >> s;
		n = (int) s.size();
		pw[0] = 1LL;
		FOR(i, 1, n) pw[i] = (pw[i-1]*p)%mod;
		h[0] = 0;
		FOR(i, 0, n)
		{			
			h[i+1] = (h[i] + (s[i]-'A'+1)*pw[i])%mod;
		}
		int la, ra, lb, rb, len, ans;
		ans = 0;
		la = 1; rb = n; len = 1;
		ra = la+(len-1); lb = rb-(len-1);
		bool combined;
		while(ra < lb)
		{
			combined = false;
			if(((h[ra]-h[la-1]+mod)*pw[lb-la])%mod == (h[rb] - h[lb-1] + mod)%mod)
			{
				ans += 2;
				la = ra+1; rb = lb-1; len = 1;
				combined = true;
			}
			else len++;
			ra = la+(len-1); lb = rb-(len-1);
		}
		if(!combined || la == rb) ans++;
		printf("Case #%d: %lld\n", t+1, ans);
	}
	return 0;
}
