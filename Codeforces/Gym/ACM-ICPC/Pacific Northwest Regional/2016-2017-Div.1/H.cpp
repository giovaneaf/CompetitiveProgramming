// Sorted start time and computed DP[x] where I stored maximum interval from x to n
// DP[x] is maximum on either pick this artist(x) and binary search for next or do not pick (x+1)
// The answer is n - DP[0]
// Time Complexity: O(k*log(k)) - Sorting, DP of size k with binary search

// No specific algorithm just some familiarity with DP (Dynamic Programming) programming paradigm
// There are many DP know problems here:
// https://www.geeksforgeeks.org/dynamic-programming/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 200010
#define LOGMAXN 20
#define INF 1000000010

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
typedef pair<ll, ll> llp;
typedef vector<llp> vll;

ll dp[MAXN];

ll n;
int k;

ll solve(int cur, vll& point)
{
	if(cur >= k) return 0;
	if(dp[cur] == -1LL)
	{
		const llp p = make_pair(point[cur].second, point[cur].second);
		auto it = upper_bound(point.begin(), point.end(), p);
		ll ans2 = point[cur].second - point[cur].first + 1;
		if(it != point.end())
			ans2 += solve(distance(point.begin(), it), point);
		ll ans = solve(cur+1, point);
		dp[cur] = max(ans, ans2);
	}
	return dp[cur];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> k)
	{
		vll point(k);
		for(int i = 0; i < k; ++i)
		{
			ll a, b;
			cin >> a >> b;
			point[i] = {a, b};
		}
		sort(point.begin(), point.end());
		for(int i = 0; i < k; ++i)
			dp[i] = -1LL;
		cout << n - solve(0, point) << "\n";
	}
	return 0;
}