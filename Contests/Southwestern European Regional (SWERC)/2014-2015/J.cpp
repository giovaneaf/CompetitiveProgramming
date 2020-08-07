/*
	Fast Fourier Transform (FFT) - Multiplying Polynomials
	code from https://cp-algorithms.com/algebra/fft.html
*/

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
#define MAXN 2010
#define LOGMAXN 20
#define MAXM 250010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

ll mod = 1000000007LL;
ll modv[10] = {1000000007, 1000000009, 1000000021, 1000000033, 1000000087, 1000000093, 1000000097, 1000000103, 1000000123, 1000000181}; 

int n, m, np, mp;
string p[MAXN], t[MAXN];
bool fingerprint[MAXN][MAXN];
ll pw[MAXN];
ll hashp[MAXN];
ll M[MAXN][MAXN];

void RabinKarp(ll pot, ll mod, bool f)
{
	pw[0] = 1LL;
	FOR(i, 1, max(n, m))
	{
		pw[i] = (pw[i-1]*pot)%mod;
	}
	hashp[0] = 0LL;
	FOR(i, 0, np)
	{
		FOR(j, 0, mp)
		{
			hashp[0] = (hashp[0] + p[i][j]*pw[j])%mod;
		}
	}
	FOR(i, 1, m)
	{		
		hashp[i] = (hashp[0]*pw[i])%mod;
		M[0][i] = 0;
	}
	FOR(i, 0, n) M[i][0] = 0;
	FOR(i, 1, n+1)
	{
		FOR(j, 1, m+1)
		{
			M[i][j] = (pw[j-1]*t[i-1][j-1] + M[i][j-1] + M[i-1][j] - M[i-1][j-1] + mod)%mod;
		}
	}
	for(int i = 1; i+np-1 <= n; ++i)
	{
		for(int j = 1; j+mp-1 <= m; ++j)
		{
			if(hashp[j-1] == (M[i+np-1][j+mp-1] - M[i+np-1][j-1] - M[i-1][j+mp-1] + M[i-1][j-1] + mod + mod)%mod)
			{
				if(f) fingerprint[i][j] = true;
				else fingerprint[i][j] = fingerprint[i][j] && true;
			}
			else fingerprint[i][j] = false;
		}
	}
	hashp[0] = 0LL;
	FOR(i, 0, np)
	{
		FOR(j, 0, mp)
		{
			hashp[0] = (hashp[0] + p[i][j]*pw[i])%mod;
		}
	}
	FOR(i, 1, n)
	{
		hashp[i] = (hashp[0]*pw[i])%mod;
		M[i][0] = 0;
	}
	FOR(i, 0, m) M[0][i] = 0;
	FOR(i, 1, n+1)
	{
		FOR(j, 1, m+1)
		{
			M[i][j] = (pw[i-1]*t[i-1][j-1] + M[i][j-1] + M[i-1][j] - M[i-1][j-1] + mod)%mod;
		}
	}
	for(int i = 1; i+np-1 <= n; ++i)
	{
		for(int j = 1; j+mp-1 <= m; ++j)
		{
			if(hashp[i-1] == (M[i+np-1][j+mp-1] - M[i+np-1][j-1] - M[i-1][j+mp-1] + M[i-1][j-1] + mod + mod)%mod)
			{
				fingerprint[i][j] = fingerprint[i][j] && true;
			}
			else fingerprint[i][j] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> np >> mp >> n >> m)
	{
		FOR(i, 0, np)
		{			
			cin >> p[i];
			FOR(j, 0, mp)
			{
				p[i][j] = (p[i][j] == 'x' ? 2 : 1);
			}
		}
		FOR(i, 0, n)
		{			
			cin >> t[i];
			FOR(j, 0, m)
			{
				t[i][j] = (t[i][j] == 'x' ? 2 : 1);
				fingerprint[i][j] = false;
			}
		}
		FOR(i, 0, 2)
		{
			RabinKarp(3LL, modv[i], i == 0);
		}
		int ans = 0;
		for(int i = 1; i+np-1 <= n; ++i)
		{
			for(int j = 1; j+mp-1 <= m; ++j)
			{
				if(fingerprint[i][j])
				{					
					ans++;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
