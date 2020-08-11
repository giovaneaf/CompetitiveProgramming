#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;;
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 20010
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9
 
int n;
 
struct Point
{
	ll p, q;
	bool pos;
	Point(ll p = 0LL, ll q = 0LL, bool pos = true) : p(p), q(q), pos(pos) {}
	//bool operator== (const Point& p1) const { return p == p1.p && q == p1.q && pos == p1.pos; }
	bool operator< (const Point& p1) const 
	{
		if(p != p1.p) return p < p1.p;
		if(q != p1.q) return q < p1.q;
		return pos < p1.pos;
	}
};
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		pair<ll, ll> v[n];
		map<Point, pair<set<int>, int>> mm;
		bool has[n];
		FOR(i, 0, n)
		{
			cin >> v[i].fst >> v[i].snd;
			has[i] = false;
		}
		FOR(i, 0, n)
		{
			FOR(j, i+1, n)
			{
				if(v[i].snd == v[j].snd) continue;
				Point point;
				if(v[i].fst == v[j].fst)
				{
					if(v[i].fst < 0)
						point = Point(-v[i].fst, 1LL, false);
					else
						point = Point(v[i].fst, 1LL, true);
				}
				else
				{
					ll p = v[j].snd - v[i].snd;
					ll q = v[j].fst - v[i].fst;
					ll r = -(v[i].snd*q-p*v[i].fst);
					bool pos = true;
					if((r < 0 && p > 0) || (r > 0 && p < 0))
					{
						pos = false;
					}
					r = llabs(r); p = llabs(p);
					ll gcd = __gcd(r, p);
					r /= gcd; p /= gcd;
					point = Point(r, p, pos);
				}
				auto it = mm.find(point);
				if(it == mm.end())
				{
					//printf("not found: %lld %lld %d\n", point.p, point.q, point.pos);
					mm[point] = mp(set<int>(), 0);
					it = mm.find(point);
				}
				//printf("%d %d %lld %lld %d\n", i, j, point.p, point.q, point.pos);
				bool toAdd = true;
				auto it2 = it->second.first.find(i);
				if(it2 != it->second.first.end()) toAdd = false;
				else it->second.first.insert(i);
				it2 = it->second.first.find(j);
				if(it2 != it->second.first.end()) toAdd = false;
				else it->second.first.insert(j);
				if(toAdd) it->second.second++;
			}
		}
		int ans = 1;
		has[0] = true;
		for(auto it = mm.begin(); it != mm.end(); ++it)
		{
			int sz = (int) it->second.first.size() - it->second.second;
			//printf("mm: %lld %lld %d %d\n", it->first.p, it->first.q, it->first.pos, sz);
			if(!has[sz])
			{
				has[sz] = true;
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
} 