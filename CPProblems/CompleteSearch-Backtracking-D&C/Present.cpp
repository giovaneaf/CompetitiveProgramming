/*
http://codeforces.com/contest/460/problem/C
Binary search the answer, for each mid value (x) in binary search check 
if it's possible to let all flowers with height x.
*/

#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair<int, int> ii;
typedef long long ll;
 
#define EPS 1e-9
#define MAXN 100010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
 
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
 
const int INF = 1e9;
const ll llINF = 1e18;
const int mod = 1000000;
const double pi = atan(1)*4.0;
 
ll n, m, w;
ll v[MAXN];
 
bool can(ll K)
{
	vector<int> sub(n, 0);
	ll days = 0LL;
	ll cur = 0LL;
	FOR(i, 0, n)
	{
		cur -= sub[i];
		if(v[i] + cur >= K) continue;
		ll gap = K - (v[i] + cur);
		cur += gap;
		days += gap;
		if(days > m) return false;
		if(i+w < n) sub[i+w] = gap;
	}
	return true;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m >> w)
	{
		FOR(i, 0, n)
		{
			cin >> v[i];
		}
		ll l = 0;
		ll h = llINF;
		while(h-l > 1)
		{
			ll mid = (h+l)/2;
			if(can(mid)) l = mid;
			else h = mid-1;
		}
		printf("%lld\n", (can(h) ? h : l));
	}
	return 0;
}