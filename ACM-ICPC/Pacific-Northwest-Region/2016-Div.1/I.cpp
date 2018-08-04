// Sorted xi and greedily started from leftmost for all xi < 0 getting 2*distance from origin
// for each travel and computed if in any travel he can save some letters for the adjacent xi 
// if x(i+1) has the same signal than xi, similarly started from rightmost for all xi > 0
// Time Complexity: O(n*log(n)) - Sorting

// No specific algorithm just think on how to achieve the best solution

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

int n, k;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> k)
	{
		vii v(n);
		for(int i = 0; i < n; ++i)
		{
			int a, b;
			cin >> a >> b;
			v[i] = {a, b};
		}
		sort(v.begin(), v.end());
		int i = 0;
		ll ans = 0;
		while(i < n && v[i].first < 0)
		{
			ans += 2LL*(-v[i].first)*((v[i].second-1)/k + 1);
			int rem = v[i].second%k;
			if(rem > 0)
			    rem = k-rem;
			while(++i < n && v[i].first < 0 && v[i].second <= rem) rem -= v[i].second;
			if(i < n && v[i].first < 0)
				v[i].second -= rem;
		}
		i = n-1;
		while(i >= 0 && v[i].first > 0)
		{
			ans += 2LL*v[i].first*((v[i].second-1)/k + 1);
			int rem = v[i].second%k;
			if(rem > 0)
			    rem = k-rem;
			while(--i >= 0 && v[i].first > 0 && v[i].second <= rem) rem -= v[i].second;
			if(i >= 0 && v[i].first > 0)
				v[i].second -= rem;
		}
		cout << ans << "\n";
	}
	return 0;
}