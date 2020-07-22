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
#define MAXN 1010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9
 
int n, m, s;
 
struct Tvector
{
	int x, y;
	Tvector(int x = 0, int y = 0) : x(x), y(y) {}
	Tvector operator-(const Tvector& v) const { return Tvector(x-v.x, y-v.y); }
	int operator*(const Tvector& v) const { return x*v.x + y*v.y; }
	int operator&(const Tvector& v) const { return x*v.y - v.x*y; }
	double len() { return hypot(x, y); }
};
 
double dist(Tvector& p, Tvector& q, Tvector& r)
{
	if((q-p)*(r-p) >= 0 && (p-q)*(r-q) >= 0)
		return (double) abs((q-p)&(r-p))/(p-q).len();
	return min((r-p).len(), (r-q).len());
}
 
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	Tvector p;
	Tvector v[4];
	while(cin >> p.x >> p.y >> v[0].x >> v[0].y >> v[2].x >> v[2].y)
	{
		v[1] = Tvector(v[0].x, v[2].y);
		v[3] = Tvector(v[2].x, v[0].y);
		double ans = DBL_MAX;
		FOR(i, 0, 4)
		{
			int next = (i+1 == 4 ? 0 : i+1);
			ans = min(ans, dist(v[i], v[next], p));
		}
		printf("%.3f\n", ans);
	}
	return 0;
} 