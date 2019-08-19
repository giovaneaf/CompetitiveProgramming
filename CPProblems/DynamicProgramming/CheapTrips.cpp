/*
https://www.urionlinejudge.com.br/judge/pt/problems/view/2905
Can be used a memoization table dp(i, j) where i is the current trip and j represents which part of the discount you
are (6 distinct values) after that there are two possibilities: the first one is to pay full value and start the discount
counter starting at trip i or continue with the actual discount and go to the next trip updating the discount value.
Becareful that the discount only is valid while the time window is less than 120.
*/

#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-9
#define MAXN 10001

int n;
double memo[MAXN][6];
double discount[] = {1.0, 0.5, 0.25, 0.25, 0.25, 0.25};
int D[MAXN];
int acc[MAXN+1];
int C[MAXN];

double solve(int pos, int discountIndex)
{
	if(pos == n) return 0.0;
	if(fabs(memo[pos][discountIndex]) > EPS) return memo[pos][discountIndex];
	double ans = C[pos] + solve(pos+1, D[pos] >= 120 ? 0 : 1);
	if(discountIndex > 0)
	{
		int newDiscountIndex = (discountIndex == 5) ? 0 : discountIndex+1; 
		int time = acc[pos+1] - acc[pos+1-discountIndex-1];
		ans = min(ans, discount[discountIndex]*C[pos] + solve(pos+1, time >= 120 ? 0 : newDiscountIndex));
	}
	return memo[pos][discountIndex] = ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		acc[0] = 0;
		for(int i = 0; i < n; ++i)
		{
			cin >> D[i] >> C[i];
			acc[i+1] = acc[i] + D[i];
		}
		memset(memo, 0.0, sizeof(memo));
		printf("%.2f\n", C[0] + solve(1, D[0] >= 120 ? 0 : 1));
	}
	return 0;
}