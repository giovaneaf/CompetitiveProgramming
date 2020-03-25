#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 1000010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9
 
int n, a, b;
 
void compute(vi& v, vi& s)
{
	int sz = (int) v.size();
	FOR(i, 1, (1 << sz))
	{
		int sum = 0;
		FOR(j, 0, sz)
		{
			if(i & (1 << j)) sum += v[j];
		}
		s.emplace_back(sum);
	}
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> a >> b)
	{
		vi v1, v2;
		FOR(i, 0, n)
		{
			int v;
			cin >> v;
			if(i < n/2)
				v1.emplace_back(v);
			else
				v2.emplace_back(v);
		}
		vi s1, s2;
		compute(v1, s1);
		compute(v2, s2);
		sort(s2.begin(), s2.end());
		ll ans = (ll) (a <= 0 && 0 <= b);
		for(auto v : s1)
		{
			if(a <= v && v <= b) ans++;
			auto itl = lower_bound(s2.begin(), s2.end(), a-v);
			auto itr = upper_bound(s2.begin(), s2.end(), b-v);
			ans += distance(itl, itr);
		}
		for(auto v : s2)
		{
			if(a <= v && v <= b) ans++;
		}
		printf("%lld\n", ans);
	}
} 