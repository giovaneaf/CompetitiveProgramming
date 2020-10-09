#include <bits/stdc++.h>

using namespace std;

#define FOR(a, b, c) for(int a = b; a < c; ++a)
	
long long memo[1010][10];

long long C(int n, int k)
{
	k = min(k, n-k);
	if(n <= 1|| k == 0) return 1LL;
	if(memo[n][k] != 0) return memo[n][k];
	return memo[n][k] = C(n-1, k) + C(n-1, k-1);
}

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	long long cp[] = {1, 1, 1, 2, 9};
	long long ans = 1LL;
	int idx = n-k;
	for(int i = k; i > 1; --i)
	{
		ans += cp[i]*C(n, idx++);
	}
	cout << ans << "\n";
    return 0;
}
