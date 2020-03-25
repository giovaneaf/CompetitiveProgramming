#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define MAXN 200010

int main()
{
	int n, t;
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> t)
	{
		if(n == 0 && t == 0) break;
		int val;
		cin >> val;
		ll lcm = val;
		vector<bool> used(100010, false);
		used[val] = true;
		for(int i = 1; i < n; ++i)
		{
			cin >> val;
			lcm = (val*lcm)/__gcd((ll) val, lcm);
			used[val] = true;
		}
		int ans = -1;
		for(int i = 2; i <= t; ++i)
		{
			if(used[i]) continue;
			ll nlcm = (i*lcm)/__gcd((ll) i, lcm);
			if(nlcm == (ll) t)
			{
				ans = i;
				break;
			}
		}
		if(ans == -1) printf("impossivel\n");
		else printf("%d\n", ans);
	}
	return 0;
}