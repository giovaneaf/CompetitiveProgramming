#include <cstdio>
 
int main()
{
	int row, col;
	scanf("%d %d", &row, &col);
	char M[row][col];
	int dp[row][col];
	int merge[row][col];
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			scanf(" %c", &M[i][j]);
			merge[i][j] = 0;
		}
	}
	dp[0][0] = 0;
	for(int i = 1; i < row; i++)
	{
		dp[i][0] = dp[i-1][0];
		if(M[i][0] == '.' && M[i-1][0] == '.')
		{
			dp[i][0]++;
			merge[i][0] = 1;
		}
	}
	for(int j = 1; j < col; j++)
	{
		dp[0][j] = dp[0][j-1];
		if(M[0][j] == '.' && M[0][j-1] == '.')
		{
			dp[0][j]++;
			merge[0][j] = -1;
		}
	}
	for(int i = 1; i < row; i++)
	{
		for(int j = 1; j < col; j++)
		{
			dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1];
			if(M[i][j] == '#')
			{
				continue;
			}
			if(M[i-1][j] == '.')
			{
				merge[i][j] = 1;
				dp[i][j]++;
			}
			if(M[i][j-1] == '.')
			{
				dp[i][j]++;
				if(merge[i][j] == 1)
					merge[i][j] = 2;
				else
					merge[i][j] = -1;
			}
		}
	}
	int Q;
	scanf("%d", &Q);
	for(int i = 0; i < Q; i++)
	{
		int r1, c1, r2, c2;
		scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
		r1--, c1--, r2--, c2--;
		int ans = dp[r2][c2] - dp[r1][c2] - dp[r2][c1] + dp[r1][c1];
		for(int i = r1+1; i <= r2; i++)
			if(merge[i][c1] == 1 || merge[i][c1] == 2)
				ans++;
		for(int j = c1+1; j <= c2; j++)
			if(merge[r1][j] == -1 || merge[r1][j] == 2)
				ans++;
		printf("%d\n", ans);
	}
	return 0;
}