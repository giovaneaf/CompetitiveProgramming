#include <bits/stdc++.h>
using namespace std;
 
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
 
int n, m, q, k;
string M[9];
 
vb valid(int r, int c)
{
	vb b(9, true);
	FOR(i, 0, 9)
	{
		if(M[r][i] > '0')
			b[M[r][i]-'1'] = false;
		if(M[i][c] > '0')
			b[M[i][c]-'1'] = false;
	}
	int ur = (r/3)*3;
	int uc = (c/3)*3;
	FOR(i, 0, 3)
	{
		FOR(j, 0, 3)
		{
			if(M[ur+i][uc+j] > '0') 
				b[M[ur+i][uc+j] - '1'] = false;
		}
	}
	return b;
}
 
bool solve(int r, int c)
{
	if(r >= 9 || c >= 9) return true;
	int nr = r+1;
	int nc = c;
	if(nr >= 9) 
	{
		nr = 0;
		nc = c+1;
	}
	if(M[r][c] > '0') return solve(nr, nc);
	vb b = valid(r, c);
	FOR(k, 0, 9)
	{	
		if(b[k])
		{
			M[r][c] = k + '1';
			if(solve(nr, nc))
				return true;
		}
	}
	M[r][c] = '0';
	return false;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T;
	cin >> T;
	while(T--)
	{
		FOR(i, 0, 9) 
		{
			FOR(j, 0, 9)
			{
				cin >> M[i][j];
			}
		}
		bool ans = solve(0, 0);
		if(!ans) printf("No solution\n");
		else
		{
			FOR(i, 0, 9)
			{			
				FOR(j, 0, 9)
				{
					if(j > 0) putchar(' ');
					printf("%c", M[i][j]);
				}
				puts("");
			}
		}
	}
    return 0;
} 