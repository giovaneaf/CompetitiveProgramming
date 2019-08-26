/*
Here I used ternary search to compute the best y position because the function of cost in unimodal (exists only a single
minimum value). You can store for each x position (column) the highest y and lowest y at that position. Then you can find
the best y position using ternary search. The function f below computes the translations in y for an 
intermediate value (mid). If both low and high for a particular x position are higher or lower than mid then the cost 
will be 2*distance of the farthest point to mid, will be 2*going from each of the 2 y values otherwise.
Then the answer will be the sum of the translation in y computed by f at the best y position + X-1 (moving each column)
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
#define MAXN 100010
#define LOGMAXN 20
#define INF 1e9
#define EPS 1e-9

int X, Y, n, x, y;

ll f(int mid, vii& pp)
{
    ll ans = 0LL;
    for(ii p : pp)
    {
        if(p.fst != INF && p.snd != -INF)
        {
            if(mid < p.fst)
                ans += abs(p.snd - mid);
            else if(mid > p.snd)
                ans += abs(mid - p.fst);
            else
                ans += abs(p.fst - mid) + abs(p.snd-mid);
        }
        else if(p.fst != INF)
            ans += abs(p.fst - mid);
        else if(p.snd != -INF)
            ans += abs(p.snd - mid);
    }
    return ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> X >> Y;
    cin >> n;
    vii p(X, {INF, -INF});
    FOR(i, 0, n)
    {
        cin >> x >> y;
        p[x] = mp(min(p[x].fst, y), max(p[x].snd, y));
    }
    int l = 0;
    int h = Y-1;
    while(h - l > 1)
    {
        int a = l + (h-l)/3;
        int b = h - (h-l)/3;
        if(f(a, p) < f(b, p))
            h = b-1;
        else
            l = a+1;
    }
    printf("%lld\n", 2*min(f(l, p), f(h, p))+X-1);
    return 0;
}