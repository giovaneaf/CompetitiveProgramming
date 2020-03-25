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
    #define MAXN 3010
    #define MAXM 44100
    #define LOGMAXN 20
    #define INF 1e9+7
    #define INFLL 1000000000000000000LL
    #define EPS 1e-9
    #define MOD 1000000007LL
     
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
     
    void fastMatrixPow(ll exp)
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
     
    ll fib(ll n)
    {
    	M[0][0] = 1; M[0][1] = 1; 
    	M[1][0] = 1; M[1][1] = 0;
    	fastMatrixPow(n-1);
    	return ans[0][0] + ans[0][1];
    }
     
    ll fastPow(ll n, ll exp)
    {
    	if(exp <= 0) return 1LL;
    	if(exp&1) return (n*fastPow((n*n)%mod, exp/2LL))%mod;
    	return fastPow((n*n)%mod, exp/2LL);
    }
     
    int main()
    {
    	ll n;
    	while(cin >> n)
    	{
    		if(n == 1LL) printf("2\n");
    		else printf("%lld\n", fastPow(2LL, n+1LL)*((4*fib(n))%mod-n-3LL+mod)%mod);
    	}
    	return 0;
    }