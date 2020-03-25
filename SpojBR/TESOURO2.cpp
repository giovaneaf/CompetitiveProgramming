#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <bitset>
 
using namespace std;
 
int DFS(int idx, int* ouro, vector<vector<int> >& v, int* dp, bitset<1000> b)
{
	if(dp[idx] != -1)
		return dp[idx];
	b.set(idx, 1);
	int ans = ouro[idx];
	for(int i = 0; i < v[idx].size(); i++)
	{
		int u = v[idx][i];
		if(!b.test(u))
			ans = max(ans, ouro[idx] + DFS(u, ouro, v, dp, b));
	}
	return dp[idx] = ans;
}
 
int main()
{
	int N;
	while(scanf("%d", &N) == 1 && N != 0)
	{
		vector<vector<int> > v(N);
		int ouro[N];
		int dp[N];
		memset(dp, -1, sizeof(dp));
		for(int i = 0; i < N; i++)
		{
			int nv;
			scanf("%d %d", &ouro[i], &nv);
			if(nv == 0)
				dp[i] = ouro[i];
			for(int j = 0; j < nv; j++)
			{
				int a;
				scanf("%d", &a);
				v[i].push_back(a-1);
			}
		}
		int ans = -1;
		for(int i = 0; i < N; i++)
		{
			if(dp[i] != -1)
				ans = max(ans, dp[i]);
			else
			{
				bitset<1000> b;
				ans = max(ans, DFS(i, ouro, v, dp, b));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
} 