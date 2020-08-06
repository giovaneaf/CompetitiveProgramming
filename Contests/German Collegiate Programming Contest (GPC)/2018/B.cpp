/*
Things to note:
1) The red circle is strictly inside the blue circle.
2) Your current location and destination are strictly inside the blue circle and strictly outside of the red circle.
3) The direct path between them is blocked by the red circle.
So you can claim that the blue circle can be ignored because you'll not try to exit this circle in the shortest path
and always the red circle is blocking the direct path.
So the shortest path is to go from a straight line from start to the tangent (from start point) of the red circle then go in 
the boundary of the circle until reach another tangent (from destination point) and go from a straight line from this
tangent to the destination point.
You have 2 tangents for each point so you get the minimum of the two possible routes.
*/
 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef pair<int, bool> ib;
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 100010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9
#define mp(a, b) make_pair(a, b)
 
const double pi = atan(1)*4;
 
struct Tvec
{
    double x, y;
    Tvec(double x = 0.0, double y = 0.0) : x(x), y(y) {}
    double operator~ () { return hypot(x, y); }
    double operator* (Tvec v) { return x*v.x + y*v.y; }
    Tvec operator* (double scalar) { return Tvec(scalar*x, scalar*y); }
    double operator^ (Tvec v) { return x*v.y - y*v.x; }
    bool operator== (Tvec v) { return fabs(x-v.x) < EPS && fabs(y-v.y) < EPS; }
    Tvec operator- (Tvec v) { return Tvec(x-v.x, y-v.y); }
    Tvec operator+ (Tvec v) { return Tvec(x+v.x, y+v.y); }
    Tvec rotate(double angle) { return Tvec(x*cos(angle)-y*sin(angle),  x*sin(angle)+y*cos(angle)); }
    void normalize() { double norm = ~(*this); x = x/norm; y = y/norm; }
    void print() { printf("(%f, %f)\n", x, y); }
};
 
void solve(Tvec& p, Tvec& c, double r, Tvec& pa, Tvec& pb)
{
    Tvec pc = (c-p);
    double d = ~pc;
    double x = sqrt(d*d - r*r);
    double theta = acos(x/d);
    Tvec a = pc.rotate(theta);
    Tvec b = pc.rotate(-theta);
    a.normalize();
    b.normalize();
    pa = a*x + p;
    pb = b*x + p;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	Tvec ps, pd, pb, pr;
    Tvec p1, p2, p3, p4;
    double rb, rr;
    cin >> ps.x >> ps.y;
    cin >> pd.x >> pd.y;
    cin >> pb.x >> pb.y >> rb;
    cin >> pr.x >> pr.y >> rr;
    solve(ps, pr, rr, p1, p2);
    solve(pd, pr, rr, p4, p3);
    double phia = acos(((p1-pr)*(p3-pr))/((~(p1-pr))*(~(p3-pr))));
    double phib = acos(((p4-pr)*(p2-pr))/((~(p4-pr))*(~(p2-pr))));
    double arca = phia*rr;
    double arcb = phib*rr;
    printf("%.10f\n", min(~(p1-ps) + arca + ~(pd-p3), ~(p2-ps) + arcb + ~(pd-p4)));
    return 0;
}