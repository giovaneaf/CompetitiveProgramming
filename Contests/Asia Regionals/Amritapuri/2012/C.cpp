/*
	Presentation Error in Live Archive (Bug ?) and Accepted in Codechef
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

struct ent
{
	int x, y, s;
};

int T, n;
ent v[55];
Circle c[55];
bool valid[55];
Tvec pt[2];

bool can(long double t)
{
	if(n == 1) return true;
	FOR(i, 0, n)
	{
		c[i] = {Tvec(v[i].x, v[i].y), (long double) t*v[i].s};
		valid[i] = true;
	}
	sort(c, c+n); 	// sort ascending by radius
	int sz = n;
	FOR(i, 0, n)
	{
		if(!valid[i]) continue;
		FOR(j, i+1, n)
		{
			if(!valid[j]) continue;
			long double d = ~(c[i].center - c[j].center);
			// check if circle i is inside circle j
			if(d < abs(c[i].r - c[j].r) || abs(d - abs(c[i].r - c[j].r)) < EPS)
			{
				valid[j] = false;
				sz--;
			}
		}
	}
	if(sz == 1) return true;
	int pos = 0;
	FOR(i, 0, n)
	{
		if(!valid[i]) continue;
		c[pos++] = c[i];
	}
	FOR(i, 0, sz)
	{
		FOR(j, i+1, sz)
		{
			if(!c[i].isect(c[j]))	// if some pair of circles doesn't intersect
			{
				return false;
			}
		}
	}
	int pts;
	bool found;
	FOR(i, 0, sz)
	{
		FOR(j, i+1, sz)
		{
			pair<Tvec, Tvec> p = c[i].getIsectPoints(c[j]);
			pt[0] = p.fst;
			pts = 1;
			if(abs(p.snd.x - INFLL) > EPS)
			{	
				pt[1] = p.snd;
				pts++;
			}
			FOR(k, 0, pts)
			{
				found = true;
				FOR(l, 0, sz)
				{
					if(!c[l].inside(pt[k]))
					{
						found = false;
						break;
					}
				}
				if(found) return true;
			}
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n;
		map<ii, int> mm;
		int x, y, s;
		FOR(i, 0, n)
		{
			cin >> x >> y >> s;
			if(mm.find(mp(x, y)) == mm.end())
			{
				mm[mp(x, y)] = s;
			}
			else								// treating circles with same center
			{
				mm[mp(x, y)] = min(mm[mp(x, y)], s);
			}
		}
		n = 0;
		for(auto it = mm.begin(); it != mm.end(); ++it) 
			v[n++] = {it->fst.fst, it->fst.snd, it->snd};
		long double l, h, mid;
		l = 0.0, h = 1e9;
		while(h - l > EPS)	// binary search the time
		{
			mid = (h+l)/2;
			if(can(mid)) h = mid;
			else l = mid;
		}
		printf("%.10Lf\n", l);
	}
	return 0;
}
