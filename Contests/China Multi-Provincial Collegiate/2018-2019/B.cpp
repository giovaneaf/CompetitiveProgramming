/*
Here you can compute the angle that the polygon will rotate for each side with dot product then
the point will rotate like an arc of a circle of that angle with radius equal to the distance
between the point and the point i+1 (the rotation point) if you are rotating from i and i+1 to
i+1 and i+2.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
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
#define MAXN 210
#define LOGMAXN 20
#define INF 1e9
#define EPS 1e-9

const double pi = 4*atan(1);

struct Tvec
{
    int x, y;
    Tvec(int x = 0.0, int y = 0.0) : x(x), y(y) {}
    int operator* (Tvec v) { return x*v.x + y*v.y; }
    double operator~ () { return hypot(x, y); }
    Tvec operator- (Tvec v) { return Tvec(x-v.x, y-v.y); }
};

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    FOR(t, 1, T+1)
    {
        int n;
        cin >> n;
        vector<Tvec> v(n);
        FOR(i, 0, n)
        {
            cin >> v[i].x >> v[i].y;
        }
        Tvec p;
        cin >> p.x >> p.y;
        double ans = 0.0;
        FOR(st, 0, n)
        {
            int nd = (st+1)%n;
            int rd = (st+2)%n;
            double angle = acos(((v[nd]-v[st])*(v[rd]-v[nd]))/((~(v[nd]-v[st]))*(~(v[rd]-v[nd]))));
            double r = ~(p-v[nd]);
            ans += angle*r;
        }
        printf("Case #%d: %.3f\n", t, ans);
    }
    return 0;
}