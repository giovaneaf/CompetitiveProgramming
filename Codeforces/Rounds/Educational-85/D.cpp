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
#define MAXN 100010
#define LOGMAXN 20
#define MAXM 110
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007

int T;
ll n;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	ll l, r;
	while(T--)
	{
		cin >> n >> l >> r;
		ll pos = 1LL;
		ll cur = 1LL;
		while(cur < n && pos+2LL*((ll) n-cur) <= l)
		{
			pos += 2LL*((ll) n-cur);
			cur++;
		}
		bool space = false;
		while(cur < n && pos <= r)
		{
			FOR(i, cur+1, n+1)
			{
				if(l <= pos && pos <= r)
				{
					if(space) putchar(' ');
					printf("%d", cur);
					space = true;
				}
				pos++;
				if(pos > r) break;
				if(l <= pos && pos <= r)
				{
					if(space) putchar(' ');
					printf("%d", i);
					space = true;
				}
				pos++;
				if(pos > r) break;
			}
			cur++;
		}
		if(cur == n && pos <= r)
		{
			if(space) putchar(' ');
			printf("1");
			space = true;
		}
		putchar('\n');
	}
	return 0;
}

