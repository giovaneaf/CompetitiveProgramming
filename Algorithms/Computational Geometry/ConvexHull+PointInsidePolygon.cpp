/* 
    Convex Hull Graham Scan O(n*log(n)) +
    Point inside convex hull in O(log(n)) for each query inside main 
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

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
        return sqrt(x*x + y*y);
    }
};

Tvec p0;

bool cmp (Tvec& a, Tvec& b)                    // sort by polar coordinate for convexHull (p0 is lowest y coordinate point)
{
    ll cross = (a - p0)^(b - p0);
    if(cross == 0LL) return a.distSqr(p0) > b.distSqr(p0);
    return cross > 0LL;
}

Tvec nextToTop(stack<Tvec>& s)                 // get point below the top of the stack
{
    Tvec a = s.top();
    s.pop();
    Tvec b = s.top();
    s.push(a);
    return b;
}

vector<Tvec> convexHull(vector<Tvec> v)       // return the vector containing convex hull points
{
    int low = 0, n = (int) v.size();
    for(int i = 1; i < n; ++i)
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
    for(int i = 1; i < n; ++i) // remove two collinear in relation to p0 (get the farthest)
    {
        while(i < n-1 && ((v[i]-p0)^(v[i+1]-p0)) == 0) i++;
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
    for(int i = 3; i < size; ++i)
    {
        while(((v[i]-s.top()) ^ (nextToTop(s) - s.top())) <= 0) // Warning: if equal to 0 then the 3 points are collinear
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

bool inTriangle(Tvec& pp, Tvec& p1, Tvec& p2, Tvec& p3)  // check if point pp is inside triangle formed by p1, p2 and p3
{
    vector<Tvec> v(3);
    v[0] = p1, v[1] = p2, v[2] = p3;
    bool in = true;
    for(int i = 0; i < 3; ++i)
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

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for(int t = 0; t < T; ++t)
    {
        printf("Case %d\n", t+1);
        int n, m;
        cin >> n >> m;
        vector<Tvec> p(n);                  // read convex hull candidate points
        for(int i = 0; i < n; ++i)
            cin >> p[i].x >> p[i].y;
        vector<Tvec> ch = convexHull(p);    // get convex hull points
        n = (int) ch.size();
        assert(n >= 3);                     // assert convex hull has 3 points
        for(int i = 0; i < m; ++i)
        {
            // check if point is inside convex hull in O(log(n)) there are m given points
            Tvec pp;
            cin >> pp.x >> pp.y;    // read point and check if it's inside convex hull
            int l = 1;
            int h = n-1;
            while(h - l > 1)
            {
                int mid = (h+l)/2;
                if(((pp-ch[0]) ^ (ch[mid]-ch[0])) > 0)
                    h = mid;
                else
                    l = mid;
            }
            bool inside = inTriangle(pp, ch[0], ch[l], ch[h]);
            printf("%lld %lld is %s!\n", pp.x, pp.y, inside ? "unsafe" : "safe");
        }
        if(t < T-1)
            putchar('\n');
    }
    return 0;
}