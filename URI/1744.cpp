#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	ll a, b;
	cin >> a >> b;
	b = a-b;
	string s;
	cin >> s;
	ll ans = 0;
	int j = s.size()-1;
	for(int i = 0; i < s.size(); ++i)
	{
		if(s[i] == 'W')
		{
			while(j > i && s[j] == 'W') j--;
			if(j == i) break;
			swap(s[j], s[i]);
			ans += min(a, (ll) b*(j-i));
		}
	}
	cout << ans << "\n";
	return 0;
}