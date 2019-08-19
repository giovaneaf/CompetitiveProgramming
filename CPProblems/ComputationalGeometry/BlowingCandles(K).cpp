/*
https://codeforces.com/gym/101635
First thing to note is that the only points needed to check is the points that lies on the convex hull removing 
the collinear ones. After that it's needed to use the rotating calipers technique for each line segment of two
consecutive points in convex hull to find the farthest point of this segment, with rotating calipers it's possible
to compute the distance between the farthest points of all line segments of two consecutive points in O(n).
Maybe you need to treat different for the test case where the convex hull has less than 3 points (collinear points)
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
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

struct Tvec
{
    ll x, y;
    Tvec(ll x = 0LL, ll y = 0LL) : x(x), y(y) {}
    Tvec operator- (const Tvec& v)                          // subtraction (2 points -> one vector)
    {
        return {x-v.x, y-v.y};
    }
    ll operator* (const Tvec& v)                            // dot product
    {
        return x*v.x + y*v.y;
    }
    ll operator^ (const Tvec& v)                            // cross product
    {
        return x*v.y - y*v.x;
    }
    ll distSqr(const Tvec& v)                               // squared distance
    {
        return (x-v.x)*(x-v.x) + (y-v.y)*(y-v.y);
    }
    double operator~ ()                                     // length
    {
        return hypot(x, y);
    }
    void print()
    {
        printf("(%lld, %lld)\n", x, y);
    }
};

Tvec p0;

bool cmp (Tvec& a, Tvec& b)                    // sort by polar coordinate for convexHull (p0 is lowest y coordinate point)
{
    ll cross = (a - p0)^(b - p0);
    if(cross == 0LL) return a.distSqr(p0) < b.distSqr(p0);
    return cross > 0LL;
}

Tvec nextToTop(stack<Tvec>& s)
{
    Tvec a = s.top();
    s.pop();
    Tvec b = s.top();
    s.push(a);
    return b;
}

vector<Tvec> convexHull(vector<Tvec> v)
{
    int low = 0, n = (int) v.size();
    FOR(i, 1, n)
    {
        if(v[i].y < v[low].y || (v[i].y == v[low].y && v[i].x < v[low].x))
        {
            low = i;
        }
    }
    swap(v[0], v[low]);
    p0 = v[0];
    sort(v.begin()+1, v.end(), cmp);
    int size = 1;
    for(int i = 1; i < n; ++i) // remove collinear in relation to p0
    {
        while(i < n-1 && ((v[i]-p0)^(v[i+1]-p0)) == 0) 
        {
            i++;
        }
        v[size++] = v[i];
    }
    if(size < 3)
    {
        return vector<Tvec>();
    }
    stack<Tvec> s;
    s.push(v[0]);
    s.push(v[1]);
    s.push(v[2]);
    FOR(i, 3, size)
    {
        while(((v[i]-s.top()) ^ (nextToTop(s) - s.top())) <= 0) // if equal to 0 then the 3 points are collinear
            s.pop();
        s.push(v[i]);
    }
    vector<Tvec> H((int) s.size());
    int idx = s.size()-1;
    while(s.size())
    {
        H[idx--] = s.top();
        s.pop();
    }
    return H;
}

bool inTriangle(Tvec& pp, Tvec& p1, Tvec& p2, Tvec& p3)
{
    vector<Tvec> v(3);
    v[0] = p1, v[1] = p2, v[2] = p3;
    bool in = true;
    FOR(i, 0, 3)
    {
        int next = (i+1 == 3) ? 0 : i+1;
        ll cross = (v[next] - v[i]) ^ (pp - v[i]);
        if(cross == 0LL)
        {
            int minx = min(v[i].x, v[next].x);
            int maxx = max(v[i].x, v[next].x);
            in = (minx <= pp.x && pp.x <= maxx);
            break;
        }
        else if(cross < 0LL)
        {
            in = false;
        }
    }
    return in;
}

// distance from point r to line segment pq
double pToSeg(Tvec& p, Tvec& q, Tvec& r)
{
    if((q-p)*(r-p) >= 0 && (p-q)*(r-q) >= 0)
        return fabs(((q-p)^(r-p))/(~(q-p)));
    else
        return min(~(r-p), ~(r-q));
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<Tvec> p(n);
    FOR(i, 0, n)
        cin >> p[i].x >> p[i].y;
    vector<Tvec> ch = convexHull(p);
    n = (int) ch.size();
    if(n <= 2)
    {
        printf("0.00000000\n");
    }
    else
    {
        int pos = 0;
        int ptr = 1;
        double ans = 2.0*m;
        FOR(pos, 0, n)
        {
            int next = (pos == n-1 ? 0 : pos+1);
            // move while ptr is increasing the distance
            while(((ch[(ptr == n-1 ? 0 : ptr+1)]-ch[pos])^(ch[next]-ch[pos])) <= ((ch[ptr]-ch[pos])^(ch[next]-ch[pos]))) 
                ptr = (ptr == n-1 ? 0 : ptr+1);
            double dist = pToSeg(ch[pos], ch[next], ch[ptr]);
            if(ans > dist)
            {
                ans = dist;
            }
        }
        printf("%.10f\n", ans);
    }
    return 0;
}