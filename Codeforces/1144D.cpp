#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define MAXN 200010
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9

int n;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	int v[n];
	int cnt[MAXN] = {};
	int best = 0;
	int idx = 0;
	FOR(i, 0, n)
	{
		cin >> v[i];
		cnt[v[i]]++;
		if(cnt[v[i]] > cnt[best])
		{
			best = v[i];
			idx = i;
		}
	}
	vector<tuple<int, int, int>> ans;
	FOR(i, idx+1, n)
	{
		if(v[i] != best)
		{
			ans.push_back(make_tuple(v[i] > best ? 2 : 1, i+1, i));
		}
	}
	RFOR(i, idx-1, 0)
	{
		if(v[i] != best)
		{
			ans.push_back(make_tuple(v[i] > best ? 2 : 1, i+1, i+2));
		}
	}
	printf("%d\n", (int) ans.size());
	for(auto val:ans)
	{
		printf("%d %d %d\n", get<0>(val),get<1>(val),get<2>(val));
	}
	return 0;
}