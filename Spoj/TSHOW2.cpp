
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define MODN 10  // mod N fornecido pelo problema.
 
void multiply_matrix_mod (const vector<vector<ll>> A, const vector<vector<ll>> B, vector<vector<ll>>& C) 
{
	// A[i][j] : linha i coluna j.  linha e coluna iniciam em zero.
 
	int A_ROW = A.size(); 		// tamanho da linha de A
	int A_COL = A[0].size(); 	// tamanho da coluna de A = tamanho da linha de B
	int B_COL = B[0].size();	// tamanho da coluna de B
	
	for(int i = 0; i < A_ROW; i++)	// zera a matriz C para guardar valor
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
 
ll f(ll n)
{
	vector<vector<ll>> initial(N, vector<ll>(1, 0));
	initial = {{0}, {1}};
	if(n < 2)
		return initial[n][0];
	vector<vector<ll>> mat(N, vector<ll>(N, 0));
	vector<vector<ll>> result(N, vector<ll>(N, 0));
	mat = {{0, 1}, {1, 1}};
	mat_mod_fastexp(mat, n-1, result);
	vector<vector<ll>> ans(N, vector<ll>(1));
	multiply_matrix_mod(result, initial, ans);
	return ans[1][0];
}
 
int main()
{
	int t;
	ll n;
	while(cin >> t)
	{
		while(t--)
		{
			cin >> n;
			printf("%lld\n", f(n-1));
		}
	}
	return 0;
} 