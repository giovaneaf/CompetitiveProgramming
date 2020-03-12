#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>

using namespace std;

int dp[100];
int N, Xa, Xb;

bool inside(pair<int, int> p1, pair<int, int> p2)
{
	int A1 = abs(p2.first*(Xb-Xa));
	int A2 = abs(p1.first*(Xb-Xa));
	int A3 = abs(p2.second*p1.first-p2.first*p1.second+Xa*(p2.first-p1.first));
	int A4 = abs(p2.second*p1.first-p2.first*p1.second+Xb*(p2.first-p1.first));
	if(A1 == A2 + A3 + A4)
		return true;
	return false;
}

int main()
{
	scanf("%d %d %d", &N, &Xa, &Xb);
	int dp[100] = {};
	vector<pair<int, int> > p(N);
	for(int i = 0; i < N; i++)
	{
		scanf("%d %d", &p[i].second, &p[i].first);
	}
	sort(p.begin(), p.end());
	dp[0] = 1;
	int num = 1;
	for(int i = 1; i < N; i++)
	{
		dp[i] = 1;
		for(int j = i-1; j >= 0; j--)
		{
			if(inside(p[j], p[i]))
			{
				dp[i] = max(dp[i], 1 + dp[j]);
				if(dp[i] > num)
					num = dp[i];
			}
		}
	}
	printf("%d\n", num);
	return 0;
}