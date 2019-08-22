/*
You can store each of the 2^N possibilities of each column (0 if doesn't have macaron is this row and 1 otherwise).
Then you can compute for a starting configuration what are the possible configurations for the next column putting
all the 3 distinct macarons (the function called B do this).
Then you have all transitions going from one column to the other and you can use fast matrix exponentiation to compute
how many possible ways there are going from initial position (all 0) to the end position(all 0) in the (m+1)-th column.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 260
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9
 
int N;                  
const ll mod = 1e9;

ll M[MAXN][MAXN];
ll ans[MAXN][MAXN];

inline void ones(ll y[MAXN][MAXN])
{
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			y[i][j] = (i == j ? 1LL : 0LL);
}

void mul(int a)
{
	ll tmp[MAXN][MAXN];
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			tmp[i][j] = 0LL;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            for(int k = 0; k < N; k++)
            {
                if(a == 0)
                    tmp[i][j] += (M[i][k]*M[k][j]);
                else
                   tmp[i][j] += (ans[i][k]*M[k][j]); 
                tmp[i][j] %= mod;
            }
        }
    }
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(a == 0)
                M[i][j] = tmp[i][j];
            else
                ans[i][j] = tmp[i][j];
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

int n;
ll m;

void B(int startMask, int nPos, int endMask)
{
    if(nPos == n)
        M[startMask][endMask]++;
    else
    {
        if((startMask & (1 << nPos)) == 0)      // if doesn't have any piece in this position
        {
            B(startMask, nPos+1, endMask);  // put a 1x1 piece in nPos
            B(startMask, nPos+1, endMask | (1 << nPos));  // put a 1x2 piece in nPos
            if(nPos+2 <= n && (startMask & (1 << (nPos+1))) == 0)
                B(startMask, nPos+2, endMask);  // put a 2x1 piece in nPos 
        }
        else                                    // go forward to fill the rest
        {
            B(startMask, nPos+1, endMask);
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n >> m)
    {
        N = (1 << n);
        FOR(i, 0, N)
        {
            FOR(j, 0, N) M[i][j] = 0LL;
            B(i, 0, 0);
        }
        expbysquaring(m);
        printf("%lld\n", ans[0][0]);
    }
	return 0;
}