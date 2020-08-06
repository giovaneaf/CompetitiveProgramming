#include <bits/stdc++.h>
 
#define mp(a, b) make_pair(a, b)
 
#define MAXN 1010
#define MOD 2147483647
#define INF 1e9
#define EPS 1e-9
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, bool> ib;
 
int p, k, n;
int dp[MAXN];
int v[MAXN];
 
int mex(set<int>& s)
{
	if(s.empty()) return 0;
	auto it = s.begin();
	if(*it > 0) return 0;
	++it;
	int val = 0;
	for(; it != s.end(); ++it)
	{
		val++;
		if(*it > val) return val;
	}
	return val+1;
}
 
int grundy(int n)
{
	if(n == 0) return 0;
	if(dp[n] != -1) return dp[n];
	set<int> s;
	for(int i = 0; i <= min(n-1, k); ++i)
	{
		int npos = n - i - v[n-i];
		if(npos < 0) continue;
		s.insert(grundy(npos));
	}
	return dp[n] = mex(s);
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> p >> k)
	{
		int xr = 0;
		for(int i = 0; i < p; ++i)
		{
			cin >> n;
			memset(dp, -1, sizeof(dp));
			for(int j = 1; j <= n; ++j)
				cin >> v[j];
			xr ^= grundy(n);
		}
		if(xr == 0)
		{
			cout << "Bob will win.";
		}
		else
		{
			cout << "Alice can win.";
		}
		cout << '\n';
	}
    return 0;
}