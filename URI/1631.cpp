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

struct Tvector
{
	double x, y;
	Tvector(double x = 0.0, double y = 0.0) : x(x), y(y) {}
	bool operator< (const Tvector& q) const { return x < q.x; }
	Tvector operator- (const Tvector& q) const { return Tvector(x-q.x, y-q.y); }
	double operator* (const	Tvector& q) const { return x*q.x + y*q.y; }
	double operator& (const Tvector& q) const { return x*q.y - q.x*y; }
	double len() const { return hypot(x, y); }
	void print() const { printf("%.3f %.3f\n", x, y); }
};

inline bool eq(double a, double b)
{
	return fabs(a-b) < EPS;
}

int n, m;
Tvector p1, p2;

double computeDist(Tvector& p, Tvector& q, Tvector& r)
{
	if((r-p)*(q-p) >= 0.0 && (r-q)*(p-q) >= 0.0)
	{
		return fabs(((q-p)&(r-p)))/(p-q).len();
	}
	else
	{
		return min((r-p).len(), (r-q).len());
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	double R = 50.0;
	double sqrR = R*R;
	while(cin >> n && n)
	{
		vector<Tvector> p;
		FOR(i, 0, n)
		{
			Tvector tv;
			cin >> tv.x >> tv.y;
			double len = tv.len();
			if(len < sqrR || eq(len, sqrR)) p.emplace_back(tv);
		}
		sort(p.begin(), p.end());
		double ans = DBL_MAX;
		FOR(i, 0, n)
		{
			FOR(j, i+1, n)
			{
				if(eq(p[i].x, p[j].x))
				{
					double x = p[i].x;
					double tosqr = R*R-x*x;
					//assert(tosqr >= 0.0);
					p1 = Tvector(x, -sqrt(tosqr));
					p2 = Tvector(x, sqrt(tosqr));
				}
				else
				{
					double a = (p[i].y - p[j].y)/(p[i].x - p[j].x);
					double b = p[i].y - a*p[i].x;
					//printf("a = %.3f b = %.3f\n", a, b);
					double A = 1+a*a;
					double B = 2*a*b;
					double C = b*b-R*R;
					double delta = B*B-4*A*C;
					//assert(delta >= 0.0);
					double x1 = (-B-sqrt(delta))/(2*A);
					double x2 = (-B+sqrt(delta))/(2*A);
					//assert(R*R - x1*x1 >= 0.0);
					p1 = Tvector(x1, sqrt(R*R - x1*x1));
					//assert(R*R - x2*x2 >= 0.0);
					p2 = Tvector(x2, sqrt(R*R - x2*x2));
					if(!eq(a*p1.x + b, p1.y))
					{
						p1.y *= -1.0;
					}
					if(!eq(a*p2.x + b, p2.y))
					{
						p2.y *= -1.0;
					}
				}
				//p[i].print(), p[j].print(), p1.print(), p2.print();
				double sumL = 0.0;
				double sumR = 0.0;
				FOR(k, 0, n)
				{
					double cp = (p2-p1)&(p[k]-p1);
					if(eq(cp, 0.0)) continue;
					if(cp > 0.0)
						sumL += computeDist(p2, p1, p[k]);
					else
						sumR += computeDist(p2, p1, p[k]);
				}
				double diff = fabs(sumL-sumR);
				if(diff < ans) 
				{
					//printf("updated = %3.f\n", diff);
					ans = diff;
				}
			}
		}
		printf("%.3f\n", ans);
	}
	return 0;
} 