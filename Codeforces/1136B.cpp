#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int>
#define vii vector<ii>

int main()
{
	int n, k;
	cin >> n >> k;
	int ans;
	if(k == 1)
		ans = 6 + max(0, n-k-1)*3;
	else if(k == n)
		ans = 6 + max(0, k-2)*3;
	else
	{
		int a, b;
		a = n-k;
		b = k-1;
		ans = 5 + 2*min(a, b) + (min(a, b)-1)*2 + max(a, b)*3;
	}
	cout << ans << '\n';
}