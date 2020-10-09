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
#define MAXN 210000
#define LOGMAXN 20
#define INF 1e9+7
#define INFLL 1000000000000000000LL
#define EPS 1e-9

typedef struct Edge Edge;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    FOR(t, 0, T)
    {
        int n, x;
        cin >> n >> x;
        int mx = -INF;
        int mdi = 0;
        FOR(i, 0, n)
        {
            int di, hi;
            cin >> di >> hi;
            mx = max(mx, di-hi);
            mdi = max(mdi, di);
        }
        if(mdi >= x)
        {
            printf("1\n");
        }
        else if(mx > 0)
        {
            int t = (int) ceil((double) (x-mdi)/mx);
            printf("%d\n", t + (x-t*mx > 0 ? 1 : 0));
        }
        else
            printf("-1\n");
    }
    return 0;
}