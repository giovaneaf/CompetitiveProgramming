#include <bits/stdc++.h>
 
#define MAXN 10001
#define MOD 1000000007
#define INF 1000000000
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
 
int R, C;
int M[510][510];
 
int dp[510][510];
 
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &R, &C);
		for(int i = 0; i < R; ++i)
			for(int j = 0; j < C; ++j)
				scanf("%d", &M[i][j]);
		dp[R-1][C-1] = 1;
		for(int i = R-2; i >= 0; --i)
			dp[i][C-1] = max(1, dp[i+1][C-1] - M[i][C-1]);
		for(int i = C-2; i >= 0; --i)
			dp[R-1][i] = max(1, dp[R-1][i+1] - M[R-1][i]);
		for(int i = R-2; i >= 0; --i)
			for(int j = C-2; j >= 0; --j)
				dp[i][j] = max(1, min(dp[i+1][j], dp[i][j+1]) - M[i][j]);
		/*for(int i = 0; i < R; ++i)
		{
		    for(int j = 0; j < C; ++j)
		    {
		        printf("%d ", dp[i][j]);
		    }
		    putchar('\n');
		}*/
		printf("%d\n", max(1, dp[0][0]));
	}
	return 0;
} 