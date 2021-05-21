
#include <bits/stdc++.h>
using namespace std;

// Fast Modular Matrix Exponentiation O(|x|^3*(log e)) -> x^e, where |x| = matrix dimension
// Implementation of Fast Modular Matrix Exponentiation

typedef long long ll; 

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
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

const ll mod = 1e9+7;

const int N = 2; // matrix dimension

ll ans[N][N]; // answer
ll M[N][N];   // matrix
ll tmp[N][N];

void ones()
{
	FOR(i, 0, N) 
		FOR(j, 0, N)
			ans[i][j] = (i == j);
}

void mul(ll a[N][N], ll b[N][N])
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

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	// initial matrix
	M[0][0] = 0; M[0][1] = 1;
	M[1][0] = 1; M[1][1] = 1;
	fastPow(4);
	printf("%lld\n", ans[1][0] + ans[1][1]); // (n-2)th fibonacci number modulo mod
	return 0;
} 