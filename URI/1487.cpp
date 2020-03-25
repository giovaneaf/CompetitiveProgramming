#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 40
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9


int n, m;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t = 1;
	int maxW;
	while(cin >> n >> maxW)
	{
		if(n == 0 && maxW == 0) break;
		int memo[610];
		memset(memo, 0, sizeof(memo));
		int V[110];
		int W[110];
		FOR(i, 0, n) cin >> W[i] >> V[i];
		FOR(i, 0, n)
		{
			FOR(j, 0, maxW+1)
			{
				if(j >= W[i]) memo[j] = max(memo[j], V[i] + memo[j-W[i]]);
			}
		}
		printf("Instancia %d\n", t++);
		printf("%d\n\n", memo[maxW]);
	}
	return 0;
} 