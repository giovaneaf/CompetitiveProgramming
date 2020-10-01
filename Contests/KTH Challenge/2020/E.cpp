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
#define MAXN 510
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

int n, m;
ll xf[MAXN], xg[MAXN];
ll y[MAXN];
ll a[MAXN], b[MAXN], c[MAXN];

pair<double, double> getIsect(int i, int pos)
{
	if(a[pos] == 0)
	{
		if(b[pos] == 0)
			return mp(-1.0, -1.0);
		else
			return mp((double) (y[i]-c[pos])/ (double) b[pos], -1.0);
	}
	else
	{
		double sqrtdelta = sqrt((double) b[pos]*b[pos] - 4*a[pos]*(c[pos]-y[i]));
		return mp((-b[pos]+sqrtdelta)/(2.0*a[pos]), (-b[pos]-sqrtdelta)/(2.0*a[pos]));
	}
}

inline bool between(int x1, int x2, double val)
{
	if(x1 < val && val < x2) return true;
	return false;
}

inline bool inside(int xfl, int xfr, int xgl, int xgr)
{
	if(xfl > xgr || xfr < xgl) return false;
	return true;
}

double area(double l, double r, int i, int pos)
{
	double ans = a[pos]/3.0*r*r*r + b[pos]/2.0*r*r + c[pos]*r - y[i]*r;
	ans -= a[pos]/3.0*l*l*l + b[pos]/2.0*l*l + c[pos]*l - y[i]*l;
	return abs(ans);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		FOR(i, 0, n)
		{
			cin >> xf[i] >> y[i];
		}
		cin >> m;
		FOR(i, 0, m)
		{
			cin >> xg[i] >> a[i] >> b[i] >> c[i];
		}
		set<double> s;
		s.insert(0.0);
		int pos = 0;
		int lpf = 0;
		int lpg = 0;
		FOR(i, 0, n)
		{
			while(pos < m && inside(lpf, xf[i], lpg, xg[pos]))
			{
				pair<double, double> sect = getIsect(i, pos);
				if(between(max(lpf, lpg), min(xf[i], xg[pos]), sect.fst))
					s.insert(sect.fst);
				if(between(max(lpf, lpg), min(xf[i], xg[pos]), sect.snd))
					s.insert(sect.snd);
				if(xg[pos] <= xf[i])
				{
					lpg = xg[pos];
					s.insert(xg[pos]);
					pos++;
				}
				else break;
			}
			lpf = xf[i];
			s.insert(xf[i]);
		}
		auto it = s.begin();
		double lp = *it;
		double rp;
		it++;
		double ans = 0.0;
		int posf, posg;
		posf = 0;
		posg = 0;
		while(it != s.end())
		{
			rp = *it;
			ans += area(lp, rp, posf, posg);
			lp = rp;
			if(fabs(xf[posf] - lp) < EPS || xf[posf] < lp) posf++;
			if(fabs(xg[posg] - lp) < EPS || xg[posg] < lp) posg++;
			it++;
		}
		printf("%.10f\n", ans);
	}
	return 0;
}