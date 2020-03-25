#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

#define EPS 1e-9
#define MAXN 1010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int INF = 1e9;
const ll llINF = 1e18;
const int mod = 1000000;

struct Line
{
	ll a, b;
	Line(ll a = 0LL, ll b = 0LL) : a(a), b(b) {}
	bool operator< (const Line& rhs) const { return a < rhs.a; }
	ll compute(ll pos) { return b + a*pos; }
	ll intersect(Line& l) { return (ll) ceil((double)(l.b-b)/(a-l.a)); }
};

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		vector<pair<ll, ll>> v(n);
		FOR(i, 0, n)
		{
			cin >> v[i].first >> v[i].second;
		}
		set<Line> s;
		ll best = 0LL;
		FOR(i, 0, n)
		{
			ll pos = v[i].first;
			if(pos == 0LL) continue;
			while(s.size() >= 2)
			{
				auto it = s.begin();
				Line first = *it;
				it++;
				Line second = *it;
				if(first.compute(pos) > second.compute(pos)) break;
				s.erase(s.begin());
			}
			if(!s.empty())
			{
				Line sol = *s.begin();
				best = max(best, sol.compute(pos));
			}
			
			Line part = Line(pos, best - v[i].second - v[i].first*pos);
			
			while(s.size() >= 2)
			{
				auto lw1 = s.end();
				lw1--;
				auto lw2 = lw1;
				lw2--;
				Line l1 = *lw1;
				Line l2 = *lw2;
				
				ll t1 = l2.intersect(l1);
				ll t2 = l1.intersect(part);
				
				if(t2 > t1) break;
					
				s.erase(lw1);
			
			}
			s.insert(part);
		}
		best -= v[n-1].second;
		if(best > 0)
		{
			printf("Ganha %lld\n", best);
		}
		else
		{
			printf("Perde %lld\n", -best);
		}
	}
	return 0;
}