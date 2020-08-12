/*
	Used for problem Entmoot (C) at Amritapuri 2012
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define mp(a, b) make_pair(a, b)
#define fst first
#define snd second
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

long double pi = acos(-1);

bool lt(long double a, long double b)
{
	return a < b && abs(a-b) > EPS;
}

bool gt(long double a, long double b)
{
	return a > b && abs(a-b) > EPS;
}

struct Tvec
{
	long double x, y;
	Tvec(long double x = 0.0, long double y = 0.0) : x(x), y(y) {}
	Tvec operator+ (Tvec& v)
	{
		return {x+v.x, y+v.y};
	}
	Tvec operator- (Tvec& v)
	{
		return Tvec(x-v.x, y-v.y);
	}
	Tvec operator* (long double scalar)
	{
		return Tvec(x*scalar, y*scalar);
	}
	long double operator* (Tvec& v)				// dot
	{
		return x*v.x + y*v.y;
	}
	long double operator^ (Tvec& v)				// cross
	{
		return x*v.y - y*v.x;
	}
	long double operator~()						// length
	{
		return hypot(x, y);
	}
	void normalize()
	{
		long double norm = ~(*this);
		x /= norm; y /= norm;
	}
	Tvec rotate(long double angle)				// rotate counterclockwise
	{
		return Tvec(x*cos(angle) - y*sin(angle), x*sin(angle) + y*cos(angle));
	}
};

struct Circle
{
	Tvec center;
	long double r;
	bool operator< (const Circle& c)
	{
		return r < c.r;
	}
	bool inside(Tvec& v)
	{
		long double d = ~(v-center);
		return d < r || abs(d-r) < EPS;
	}
	bool isect(Circle& c)
	{
		long double d = ~(center-c.center);
		long double sumR = r + c.r;
		if(lt(d, abs(r-c.r)) || gt(d, sumR)) return false;
		return true;
	}
	pair<Tvec, Tvec> getIsectPoints(Circle& c)
	{
		// this code doesn't treat special case like two identical circles
		if(!isect(c)) return mp(Tvec(INFLL, INFLL), Tvec(INFLL, INFLL));
		long double d = ~(center-c.center);
		long double sumR = r + c.r;
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
		long double angle = acos((r*r+d*d-c.r*c.r)/(2*r*d));
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
	printf("Points are (%.2Lf, %.2Lf) and (%.2Lf, %.2Lf)\n", p.fst.x, p.fst.y, p.snd.x, p.snd.y);
	return 0;
}
