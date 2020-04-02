#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
#define MAXN 1000010
#define LOGMAXN 20
#define MAXM 100010
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL
 
#define ITER 1000000
#define DEBUG 0
#define TABLE 1


typedef long long ll;

const int N = 11;
long long GCD(long long a, long long b) { return (b == 0) ? a : GCD(b, a % b); }
inline long long LCM(long long a, long long b) { return a / GCD(a, b) * b; }
inline long long normalize(long long x, long long mod) { x %= mod; if (x < 0) x += mod; return x; }
struct GCD_type { long long x, y, d; };
GCD_type ex_GCD(long long a, long long b)
{
    if (b == 0) return {1, 0, a};
    GCD_type pom = ex_GCD(b, a % b);
    return {pom.y, pom.x - a / b * pom.y, pom.d};
}


ll a[N+1], b[N+1];

ll CRT(int sz)
{
    ll ans = a[0];
    ll lcm = b[0];
    for(int i = 1; i < sz; i++)
    {
        auto pom = ex_GCD(lcm, b[i]);
        int x1 = pom.x;
        int d = pom.d;
        if((a[i] - ans) % d != 0) return -1LL;
        ans = normalize(ans + x1 * (a[i] - ans) / d % (b[i] / d) * lcm, lcm * b[i] / d);
        lcm = LCM(lcm, b[i]);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    while(cin >> t)
    {
        while(t--)
        {
            cin >> a[0] >> b[0] >> a[1] >> b[1];
            ll crt = CRT(2);
            if(crt == -1LL)
            {
                printf("no solution");
            }
            else
            {
                printf("%lld %lld", crt, (b[0]*b[1])/__gcd(b[0], b[1]));
            }
            putchar('\n');
        }
    }
    return 0;
}