#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

int dp[1010][2010];

int val(int w, int l, int K)
{
	if(w >= l)
		return w-l;
	else
		return l-w+K;
}

bool B(string& s, int idx, int w, int l, int N, int K)
{
	if(idx == N && abs(w-l) == K)
		return true;
	if(idx == N)
		return false;
	int a = val(w, l, K);
	if(abs(w-l) == K)
		return dp[idx][a] = false;
	if(dp[idx][a] != -1)
		return dp[idx][a];
	if(s[idx] == 'W')
		return dp[idx][a] = B(s, idx + 1, w+1, l, N, K);
	if(s[idx] == 'L')
		return dp[idx][a] = B(s, idx + 1, w, l+1, N, K);
	if(s[idx] == 'D')
		return dp[idx][a] = B(s, idx + 1, w, l, N, K);
	s[idx] = 'W';
	if(B(s, idx+1, w+1, l, N, K))
		return dp[idx][a] = true;
	s[idx] = 'D';
	if(B(s, idx+1, w, l, N, K))
		return dp[idx][a] = true;
	s[idx] = 'L';
	if(B(s, idx+1, w, l+1, N, K))
		return dp[idx][a] = true;
	return dp[idx][a] = false;
}

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	for(int i = 0; i <= N; i++)
		for(int j = 0; j <= 2*K; j++)
			dp[i][j] = -1;
	string s;
	cin >> s;
	if(B(s, 0, 0, 0, N, K))
	{
		cout << s << endl;
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}