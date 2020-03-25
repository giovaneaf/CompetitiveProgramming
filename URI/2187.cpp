#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define MAXN 10010
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9

int n, m;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int v[4] = {1, 5, 10, 50};
	int memo[4][MAXN];
	FOR(i, 0, MAXN) memo[0][i] = i;
	FOR(i, 1, 4)
	{
		FOR(j, 0, MAXN)
		{
			if(j < v[i]) memo[i][j] = memo[i-1][j];
			else memo[i][j] = 1+memo[i][j-v[i]];
		}
	}
	/*FOR(i, 0, 4)
	{
		FOR(j, 0, 20)
		{
			printf("%d ", memo[i][j]);
		}
		putchar('\n');
	}*/
	int t = 1;
	while(cin >> n && n)
	{
		printf("Teste %d\n", t++);
		int ans[] = {0, 0, 0, 0};
		int pos = 3;
		RFOR(pos, 3, 0)
		{
			while(n >= v[pos] && memo[pos][n] == memo[pos][n-v[pos]]+1) 
			{
				n -= v[pos];
				ans[pos]++;
			}
		}
		RFOR(i, 3, 0) 
		{
			if(i < 3) putchar(' ');
			printf("%d", ans[i]);
		}
		printf("\n\n");
	}
	return 0;
}
