#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 1010
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9
 
int N, m;
ll mod = 1000000007LL;
 
ll M[55][55];
ll ans[55][55];
 
inline void ones(ll y[55][55])
{
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			y[i][j] = (i == j ? 1LL : 0LL);
}
 
void mul(int a)
{
	ll tmp[55][55];
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
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		cin >> N >> m;
		FOR(i, 0, N)
		{
			FOR(j, 0, N)
			{
				cin >> M[i][j];
			}
		}
		expbysquaring(m);
		FOR(i, 0, N)
		{
			FOR(j, 0, N)
			{
				if(j > 0) putchar(' ');
				printf("%d", ans[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}  