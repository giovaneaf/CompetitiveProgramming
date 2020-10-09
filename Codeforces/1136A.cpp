#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int>
#define vii vector<ii>

int main()
{
	int n;
	cin >> n;
	vii v(n);
	for(int i = 0; i < n; ++i) cin >> v[i].first >> v[i].second;
	int k;
	cin >> k;
	int ans = 0;
	for(int i = 0; i < n; ++i)
	{
		if(k > v[i].second) continue;
		ans = n-i;
		break;
	}
	cout << ans << '\n';
}