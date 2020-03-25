#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 40
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9

const double pi = atan(1)*4;

int n, m;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int r, la, lo;
	while(cin >> r >> la >> lo)
	{
		double x, y, z, p;
		y = fabs(r*sin(la*pi/180.0));
		p = fabs(r*cos(la*pi/180.0));
		x = fabs(p*sin(lo*pi/180.0));
		z = fabs(p*cos(lo*pi/180.0));
		int rx, ry, rz;
		rx = round(100*x);
		ry = round(100*y);
		rz = round(100*z);
		if(la < 0 && ry > 0) y *= -1.0;
		if(lo < 0 && rx > 0) x *= -1.0;
		if(-90 < lo && lo < 90 && rz > 0) z *= -1.0;
		printf("%.2f %.2f %.2f\n", x, y, z);
	}
	return 0;
} 