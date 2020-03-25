#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define MAXN 300010
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	ll sum = 0LL;
	vector<int> v(n);
	FOR(i, 0, n)
	{
		cin >> v[i];
		sum += v[i];
	}
	int j = 0;
	ll stolen = 0;
	int ans = 0;
	vector<bool> seen(n);
	while(j >= 0 && j < n)
	{
		if(!seen[j])
		{
			seen[j] = true;
			ans++;
		}
		stolen += min(1, v[j]);
		bool even = (v[j]&1) == 0;
		v[j] = max(0, v[j]-1);
		if(even)
		{
			j--;
		}
		else
		{
			j++;
		}
	}
	printf("%d %lld\n", ans, sum-stolen);
	return 0;
}
