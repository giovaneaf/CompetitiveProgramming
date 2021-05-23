#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, int> ip;
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
#define LOGMAXN 23
#define MAXM 1110
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-6
#define MAXWORDS 1010
 
ll mod = 1000000009LL;

int T;
int n, m;

int N; // matrix dimension

ll ans[300][300]; // answer
ll M[300][300];   // matrix
ll tmp[300][300];

void ones()
{
	FOR(i, 0, N) 
		FOR(j, 0, N)
			ans[i][j] = (i == j);
}

void mul(ll a[300][300], ll b[300][300])
{
	FOR(i, 0, N) FOR(j, 0, N) tmp[i][j] = 0LL;
	FOR(i, 0, N)
		FOR(j, 0, N)
			FOR(k, 0, N)
				tmp[i][j] = (tmp[i][j] + a[i][k]*b[k][j])%mod;
	FOR(i, 0, N)
		FOR(j, 0, N)
			a[i][j] = tmp[i][j];
}

void fastPow(ll exp)
{
	ones();
	while(exp > 0LL)
	{
		if(exp&1LL)
		{
			mul(ans, M);
		}
		mul(M, M);
		exp >>= 1;
	}
}

int mask[] = {0, 1, 3, 7, 15};

void fillM()
{
    memset(M, 0, sizeof(M));
    int choices = (1 << m);
    N = choices*choices;
    bool skip;
    int ni, nj;
    FOR(k, 0, choices)
    {
        FOR(i, 0, choices)
        {
            skip = false;
            FOR(l, 0, m)
            {
                if((i & (1 << l)) > 0 && (k & (1 << l)) > 0)
                {
                    skip = true;
                    break;
                }
            }
            if(skip) continue;
            FOR(j,  0, choices)
            {
                ni = j;
                nj = 0;
                if(k & (1 << 0))
                {
                    ni = ni | (1 << 2);
                    nj = nj | (1 << 1);
                }
                if(k & (1 << 1))
                {
                    ni = ni | (1 << 3);
                    nj = nj | (1 << 0) | (1 << 2);
                }
                if(k & (1 << 2))
                {
                    ni = ni | (1 << 0);
                    nj = nj | (1 << 1) | (1 << 3);
                }
                if(k & (1 << 3))
                {
                    ni = ni | (1 << 1);
                    nj = nj | (1 << 2);
                }
                ni = ni&mask[m];
                nj = nj&mask[m];
                M[(i<<m) | j][(ni<<m) | nj]++;
            }
        }
    }
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> T)
	{
		while(T--)
		{
            cin >> m >> n;
            fillM();
            fastPow(n);
            ll res = 0LL;
            FOR(j, 0, N)
                res = (res + ans[0][j])%mod;
            printf("%lld\n", res);
		}
	}
	return 0;
}