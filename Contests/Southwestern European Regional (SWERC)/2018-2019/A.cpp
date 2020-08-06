/*
You can just simulate every one of the k values and keep the counter for the
number of lights turned off, answer the global minimum.
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
#define MAXN 2010
#define LOGMAXN 20
#define INF 1e9
#define EPS 1e-9

int n, k;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    vb v(n, true);
    int mx = 0;
    int off = 0;
    FOR(i, 0, k)
    {
        int x;
        cin >> x;
        for(int j = x-1; j < n; j += x)
        {
            if(v[j])
                off++;
            else
                off--;
            v[j] = !v[j];
        }
        mx = max(mx, off);
    }
    printf("%d\n", mx);
    return 0;
}