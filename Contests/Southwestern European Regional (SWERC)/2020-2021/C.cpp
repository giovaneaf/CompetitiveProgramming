#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, int> ip;
typedef pair<int, bool> ib;
 
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define all(v) v.begin(), v.end()
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 1010
#define LOGMAXN 23
#define MAXM 1010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-6
#define MAXWORDS 1010
 
ll mod = 1000000007LL;
 
 double pi = acos(-1);
 
inline bool lt( double a,  double b)
{
	return a < b && abs(a-b) > EPS;
}
 
inline bool leq( double a,  double b)
{
	return a < b || abs(a-b) < EPS;
}
 
inline bool gt( double a,  double b)
{
	return a > b && abs(a-b) > EPS;
}
 
inline bool geq( double a,  double b)
{
	return a > b || abs(a-b) < EPS;
}
 
inline bool eq( double a,  double b)
{
	return abs(a-b) < EPS;
}
 
struct Tvec
{
	 double x, y;
	Tvec( double x = 0.0,  double y = 0.0) : x(x), y(y) {}
	Tvec operator+ (Tvec& v)
	{
		return {x+v.x, y+v.y};
	}
	Tvec operator- (Tvec& v)
	{
		return Tvec(x-v.x, y-v.y);
	}
	Tvec operator* ( double scalar)
	{
		return Tvec(x*scalar, y*scalar);
	}
	 double operator* (Tvec& v)				// dot
	{
		return x*v.x + y*v.y;
	}
	 double operator^ (Tvec& v)				// cross
	{
		return x*v.y - y*v.x;
	}
	 double operator~()						// length
	{
		return sqrt(x*x + y*y);
	}
	void normalize()
	{
		 double norm = ~(*this);
		x /= norm; y /= norm;
	}
	Tvec rotate( double angle)				// rotate counterclockwise
	{
		return Tvec(x*cos(angle) - y*sin(angle), x*sin(angle) + y*cos(angle));
	}
};
 
struct Circle
{
	Tvec center;
	 double r;
	bool operator< (const Circle& c)
	{
		return r < c.r;
	}
	bool inside(Tvec& v)
	{
		 double d = ~(v-center);
		return d < r || abs(d-r) < EPS;
	}
	bool isect(Circle& c)
	{
		 double d = ~(center-c.center);
		 double sumR = r + c.r;
		if(lt(d, abs(r-c.r)) || gt(d, sumR)) return false;
		return true;
	}
	pair<Tvec, Tvec> getIsectPoints(Circle& c)
	{
		// this code doesn't treat special case like two identical circles
		if(!isect(c)) return mp(Tvec(INFLL, INFLL), Tvec(INFLL, INFLL));
		 double d = ~(center-c.center);
		 double sumR = r + c.r;
		Tvec v;
		if(abs(d - abs(r-c.r)) < EPS)	// 1 point tangent circle is inside the other
		{
			if(c.r < r) v = c.center-center;
			else v = center-c.center;
			v.normalize();
			v = (v*r) + center;
			return mp(v, Tvec(INFLL, INFLL));
		}
		if(abs(d - sumR) < EPS)			// 1 point tangent circles aren't inside
		{
			v = c.center-center;
			v.normalize();
			v = (v*r) + center;
			return mp(v, Tvec(INFLL, INFLL));
		}
		// 2 points
		 double angle = acos((r*r+d*d-c.r*c.r)/(2*r*d));
		if(d < abs(r-c.r)) 			// one is inside the other
		{
			if(c.r < r) v = c.center-center;
			else v = center-c.center;
		}
		else v = c.center - center; // one is outside the other
		v.normalize();
		Tvec p1, p2;
		p1 = (v.rotate(angle)*r) + center;
		p2 = (v.rotate(-angle)*r) + center;
		return mp(p1, p2);
	}
};
 
int pset[MAXN];
 
struct UnionFind
{
	int sz;
    UnionFind(int n) 
    {
		sz = n;
        for(int i = 0; i < n; ++i) pset[i] = i;
    }
    int findSet(int i)
    {
        return (pset[i] == i ? i : (pset[i] = findSet(pset[i])));
    }
    bool isSameSet(int i, int j)
    {
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j)     // make set i point to j
    {
        if(isSameSet(i, j)) return;
        pset[findSet(i)] = findSet(j);
    }
	void clear()
	{
		for(int i = 0; i < sz; ++i)
		{ 
			pset[i] = i;
		}
	}
};
 
int n, k;
int x, y;
Circle v[MAXN];
 
bool can(double radius, UnionFind& uf)
{
	uf.clear();
	// 0 is N
	// 1 is E
	// 2 is S
	// 3 is W
	FOR(i, 0, n)
	{
		if(geq(v[i].center.y + radius, y))
			uf.unionSet(i+4, 0);
		if(geq(v[i].center.x + radius, x))
			uf.unionSet(i+4, 1);
		if(leq(v[i].center.y - radius, 0))
			uf.unionSet(i+4, 2);
		if(leq(v[i].center.x - radius, 0))
			uf.unionSet(i+4, 3);
	}
	FOR(i, 0, n)
	{
		FOR(j, i+1, n)
		{
			if(leq(2*radius, ~(v[i].center - v[j].center)))
				continue;
			uf.unionSet(i+4, j+4);
		}
		if(uf.isSameSet(0, 2) || uf.isSameSet(1, 3) || uf.isSameSet(0, 1) || uf.isSameSet(2, 3))
			return false;
	}
	return true;
}
 
int main() 
{
	//ios_base::sync_with_stdio(false); cin.tie(0);
	//cin >> x >> y;
	scanf("%d %d", &x, &y);
	scanf("%d", &n);
	//cin >> n;
	UnionFind uf(n+4);
	FOR(i, 0, n)
	{
		scanf("%lf %lf", &v[i].center.x, &v[i].center.y);
		//cin >> v[i].center.x >> v[i].center.y;
	}
	double l, r, m;
	l = 0;
	r = max(x, y);
	while(r-l > EPS)
	{
		m = (r+l)/2.0;
		if(can(m, uf))
			l = m;
		else
			r = m;
	}
	printf("%.10lf\n", l);
	return 0;
}