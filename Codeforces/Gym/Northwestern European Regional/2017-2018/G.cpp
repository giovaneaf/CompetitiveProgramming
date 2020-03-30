#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define MAXN 4100
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9
 
int n;
const double pi = atan(1)*4;
 
struct Point
{
	double x, y;
	Point(double x = 0, double y = 0) : x(x), y(y) {}
	double cross(Point& p)
	{
		return x*p.y - y*p.x;
	}
	Point operator- (Point& p)
	{
		return Point(x-p.x, y-p.y);
	}
	bool inside(Point& p1, Point& p2)
	{
		double maxx, minx, maxy, miny; 
		maxx = max(p1.x, p2.x);
		minx = min(p1.x, p2.x);
		maxy = max(p1.y, p2.y);
		miny = min(p1.y, p2.y);
		if((minx <= x && x <= maxx) || fabs(minx-x) < EPS || fabs(maxx-x) < EPS)
			if((miny <= y && y <= maxy) || fabs(miny-y) < EPS || fabs(maxy-y) < EPS)
				return true;
		return false;
	}
};
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		Point v[n];
		FOR(i, 0, n)
		{
			cin >> v[i].x >> v[i].y;
		}
		int kans = -1;
		double ratio;
		FOR(i, 3, 9)
		{
			double l = 0.0;
			double h = 1e18;
			double angle = 2.0*pi/i;
			Point pin[i];
			while(h-l > EPS)
			{
				double mid = (l+h)/2.0;
				FOR(j, 0, i)
				{
					pin[j] = Point(mid*cos(angle*j), mid*sin(angle*j));
				}
				bool hasInside = false;
				FOR(k, 0, n)
				{
					bool insidek = true;
					FOR(j, 0, i)
					{
						int next = (j+1)%i;
						Point vec = pin[next]-pin[j];
						Point nvec = v[k]-pin[j];
						double cp = vec.cross(nvec);
						if(abs(cp) < EPS && v[k].inside(pin[j], pin[next]))
						{
							insidek = true;
							break;
						}
						if(cp > EPS) continue;
						insidek = false;
						break;
					}
					if(insidek)
					{
						hasInside = true;
						break;
					}
				}
				if(hasInside) h = mid;
				else l = mid;
			}
			l = 0.0;
			h = 1e18;
			Point pout[i];
			while(h-l > EPS)
			{
				double mid = (l+h)/2.0;
				FOR(j, 0, i)
				{
					pout[j] = Point(mid*cos(angle*j), mid*sin(angle*j));
				}
				bool outside = false;
				FOR(k, 0, n)
				{
					bool insidek = true;
					FOR(j, 0, i)
					{
						int next = (j+1)%i;
						Point vec = pout[next]-pout[j];
						Point nvec = v[k]-pout[j];
						double cp = vec.cross(nvec);
						if(abs(cp) < EPS && v[k].inside(pout[j], pout[next]))
						{
							insidek = true;
							break;
						}
						if(cp > EPS) continue;
						insidek = false;
						break;
					}
					if(!insidek)
					{
						outside = true;
					}
				}
				if(outside) l = mid;
				else h = mid;
			}
			double Ainner = 0.0;
			double Aouter = 0.0;
			FOR(j, 0, i)
			{
				int next = (j+1)%i;
				Ainner += pin[j].x*pin[next].y - pin[j].y*pin[next].x;
				Aouter += pout[j].x*pout[next].y - pout[j].y*pout[next].x;
			}
			Ainner = fabs(Ainner); Aouter = fabs(Aouter);
			double rr = Ainner/Aouter;
			if(kans == -1 || rr - ratio > EPS)
			{
				kans = i;
				ratio = rr;
			}
		}
		printf("%d %.9f\n", kans, ratio);
	}
}