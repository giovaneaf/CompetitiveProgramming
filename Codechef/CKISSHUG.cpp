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
#define MAXN 100010
#define LOGMAXN 20
#define MAXM 100010
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL
 
#define ITER 1000000
#define DEBUG 0
 
ll n;
const int N = 6;
const ll mod = 1e9+7;
 
ll M[N][N];
ll ans[N][N];
 
inline void ones(ll y[N][N])
{
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			y[i][j] = (i == j ? 1LL : 0LL);
}
 
void mul(int a)
{
	ll tmp[N][N];
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			tmp[i][j] = 0LL;
	if(a == 0)
	{
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				for(int k = 0; k < N; k++)
				{
					tmp[i][j] += (M[i][k]*M[k][j]);
					tmp[i][j] %= mod;
				}
			}
		}
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				M[i][j] = tmp[i][j];
	}
	else
	{
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				for(int k = 0; k < N; k++)
				{
					tmp[i][j] += (ans[i][k]*M[k][j]);
					tmp[i][j] %= mod;
				}
			}
		}
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				ans[i][j] = tmp[i][j];
	}
}
 
void expbysquaring(ll L)
{
	ones(ans);
	while(L > 0)
	{
		if(L & 1)
			mul(1);
		L >>= 1;
		mul(0);
	}
}
int tmp[N][N] = {{0, 0, 0, 1, 0, 1}, 
				 {0, 0, 0, 0, 2, 0}, 
				 {0, 0, 0, 0, 0, 1},
				 {1, 1, 0, 0, 0, 0}, 
				 {0, 1, 0, 0, 0, 0},
				 {0, 0, 2, 0, 0, 0}
				 };

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T;
	while(cin >> T)
	{
		while(T--)
		{
			cin >> n;
			FOR(i, 0, N) FOR(j, 0, N) M[i][j] = tmp[i][j];

			expbysquaring(n);
			
			ll ways = 0LL;
			FOR(i, 0, N) ways = (ways + ans[0][i])%mod;
			printf("%lld\n", ways);
		}
	}
	return 0;
}