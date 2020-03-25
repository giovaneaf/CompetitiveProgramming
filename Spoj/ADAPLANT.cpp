#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define MAXN 200010
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n, k;
		cin >> n >> k;
		vector<int> v(n);
		FOR(i, 0, n) cin >> v[i];
		k++;
		if(k + 1 >= n)
		{
			printf("%d\n", *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end()));
			continue;
		}
		int l, r;
		l = 0, r = 0;
		set<ii> s;
		priority_queue<ii> pq;
		while(r < k)
		{
			s.insert(mp(v[r], r));
			pq.push(mp(v[r], r));
			r++;
		}
		s.insert(mp(v[r], r));
		pq.push(mp(v[r], r));
		int ans = pq.top().first - s.begin()->first;
		while(r < n-1)
		{
			l++; r++;
			s.insert(mp(v[r], r));
			pq.push(mp(v[r], r));
			while(s.size() && s.begin()->second < l) s.erase(s.begin());
			while(pq.size() && pq.top().second < l) pq.pop();
			ans = max(ans, pq.top().first - s.begin()->first);
		}
		printf("%d\n", ans);
	}
	return 0;
} 