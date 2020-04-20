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
#define MAXN 100010
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007

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

int T;
int n, m;
int res;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T >> n >> m;
	vi numbers({16, 9, 5, 7, 11, 13, 17});
	int sum, num;
	int cnt;
	FOR(t, 1, T+1)
	{
		cnt = 0;
		for(int& x : numbers)
		{
			FOR(i, 0, 18)
			{
				if(i > 0) putchar(' ');
				printf("%d", x);
			}
			putchar('\n');
			fflush(stdout);
			sum = 0;
			FOR(i, 0, 18)
			{
				cin >> num;
				sum += num;
			}
			a[cnt] = sum%x;
			b[cnt] = x;
			cnt++;
		}
		printf("%d\n", CRT(cnt));
		fflush(stdout);
		cin >> res;
		if(res == -1) break;
	}
	return 0;
}