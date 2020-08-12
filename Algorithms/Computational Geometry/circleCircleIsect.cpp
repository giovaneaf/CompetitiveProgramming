/*
	Only tested with a little bit of cases
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
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
#define MAXN 1000001
#define LOGMAXN 21
#define MAXM 250010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

ll mod = 1000000007LL;

int T, n;

double pi = acos(-1);

bool lt(double a, double b)
{
	return a < b && abs(a-b) > EPS;
}

bool gt(double a, double b)
{
	return a > b && abs(a-b) > EPS;
}

struct Tvec
{
	double x, y;
	Tvec(double x = 0.0, double y = 0.0) : x(x), y(y) {}
	Tvec operator+ (Tvec& v)
	{
		return {x+v.x, y+v.y};
	}
	Tvec operator- (Tvec& v)
	{
		return Tvec(x-v.x, y-v.y);
	}
	Tvec operator* (double scalar)
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
		return hypot(x, y);
	}
	void normalize()
	{
		double norm = ~(*this);
		x /= norm; y /= norm;
	}
	Tvec rotate(double angle)				// rotate counterclockwise
	{
		return Tvec(x*cos(angle) - y*sin(angle), x*sin(angle) + y*cos(angle));
	}
};

struct Circle
{
	Tvec center;
	double r;
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

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	Circle c1, c2;
	c1 = {Tvec(0, 0), 1.0}; c2 = {Tvec(2.5, 0.0), 2.1};
	pair<Tvec, Tvec> p = c1.getIsectPoints(c2);
	printf("Points are (%.2f, %.2f) and (%.2f, %.2f)\n", p.fst.x, p.fst.y, p.snd.x, p.snd.y);
	return 0;
}
