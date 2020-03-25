#include <bits/stdc++.h>

#define INF 1e9
#define MAXN 100010
#define MOD 1000000007
#define mp(a, b) make_pair(a, b)

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int n, m, x, y;
int dp[100][100][21][21][3];
int M[100][100];
int dc[] = {0, 1, -1};

int solve(int r, int c, int cx, int cy, int dir)
{
	if(cx < 0 || cy < 0) return INF;
	if(r == n-1 && c == m-1) return M[r][c];
	if(dp[r][c][cx][cy][dir] == -1)
	{
		int ans;
		if(r == n-1)
		{
			ans = solve(r, c+1, cx - (M[r][c+1] == 0), cy - (M[r][c+1] < 0), 1);
			if(ans != INF)
				ans += M[r][c];
		}
		else
		{
			ans = solve(r+1, c, cx - (M[r+1][c] == 0), cy - (M[r+1][c] < 0), 0);
			if(ans != INF)
				ans += M[r][c];
			for(int i = 1; i < 3; ++i)
			{
				int nr = r;
				int nc = c + dc[i];
				if(nc < 0 || nc >= m || (dir > 0 && dir != i)) continue;
				int tmp = solve(nr, nc, cx - (M[nr][nc] == 0), cy - (M[nr][nc] < 0), i);
				if(tmp != INF)
					tmp += M[r][c];
				ans = min(ans, tmp);
			}
		}
		dp[r][c][cx][cy][dir] = ans;
	}
	return dp[r][c][cx][cy][dir];
}

int main()
{
	while(scanf("%d %d %d %d", &n, &m, &x, &y) != EOF)
	{
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < m; ++j)
			{
				scanf("%d", &M[i][j]);
				for(int k = 0; k <= x; ++k)
					for(int l = 0; l <= y; ++l)
						for(int m = 0; m < 3; ++m)
							dp[i][j][k][l][m] = -1;
			}
		}
		int ans = solve(0, 0, x - (M[0][0] == 0), y - (M[0][0] < 0), 0);
		if(ans == INF)
			printf("Impossivel\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}