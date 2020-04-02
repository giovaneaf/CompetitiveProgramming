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
#define MAXN 110
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007

ll n, period;
int mod;
int MODN;

ll pisanoPeriod(int mod)
{
	int ans = 0;
	int f1, f2, tmp;
	f1 = f2 = 1;
	do
	{
		tmp = f2;
		f2 = (f1 + f2)%mod;
		f1 = tmp;
		ans++;
	} while(f1%mod != 1 || f2%mod != 1);
	return ans;
}

void multiply_matrix_mod (const vector<vector<ll>> A, const vector<vector<ll>> B, vector<vector<ll>>& C) 
{

    int A_ROW = A.size();
    int A_COL = A[0].size();
    int B_COL = B[0].size();
    
    for(int i = 0; i < A_ROW; i++)
    {
        fill(C[i].begin(), C[i].end(), 0);
    }

    for (ll i = 0; i < A_ROW; i++)
    {
        for (ll j = 0; j < B_COL; j++)
        {
            for (ll k = 0; k < A_COL; k++) 
            {
                C[i][j] += (A[i][k]  * B[k][j]) % MODN;
                C[i][j] %= MODN;
            }
        }
    }
    
}

void make_identity(vector<vector<ll>> &mat)
{
    for (unsigned i = 0, l = mat.size(); i < l; i++)
        for (unsigned j = 0; j < l; j++)
            mat[i][j] = (i == j);
}

void mat_mod_fastexp(vector<vector<ll>> matrix, ll exp, vector<vector<ll>> &result) 
{
    make_identity(result); 
    while (exp > 0) 
    { 
        if (exp & 1) 
            multiply_matrix_mod(result, matrix, result);
        exp = exp >> 1; 
        multiply_matrix_mod(matrix, matrix, matrix);
    } 
}

const int N = 2;

ll fib(ll n, int modn)
{
	if(n == 0) return 0;
    if(n <= 2) return 1;
	MODN = modn;
    vector<vector<ll>> initial(N, vector<ll>(1, 0));
    initial = {{1}, {1}};
    vector<vector<ll>> mat(N, vector<ll>(N, 0));
    vector<vector<ll>> result(N, vector<ll>(N, 0));
    mat = {{1, 1}, {1, 0}};
    mat_mod_fastexp(mat, n-2, result);
    vector<vector<ll>> ans(N, vector<ll>(1));
    multiply_matrix_mod(result, initial, ans);
    return ans[0][0]%modn;
}

int main()
{
	while(cin >> n >> mod)
	{
		period = pisanoPeriod(mod);
		ll ans = fib(n, period);
		printf("%lld\n", fib(ans, mod));
	}
	return 0;
}