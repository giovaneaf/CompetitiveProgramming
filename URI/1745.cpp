#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	long long ans = 0LL;
	int acc[3] = {0, 0, 0};
	for(int i = 0; i < s.size(); ++i)
	{
		if(s[i] < '0' or s[i] > '9')
		{
			acc[0] = acc[1] = acc[2] = 0;
			continue;
		}
		int val = (s[i]-'0')%3;
		if(val == 0)
		{
			acc[val]++;
			ans += acc[0];
		}
		else if(val == 1)
		{
			swap(acc[0], acc[2]);
			swap(acc[1], acc[2]);
			acc[val]++;
			ans += acc[0];
		}
		else
		{
			swap(acc[0], acc[1]);
			swap(acc[1], acc[2]);
			acc[val]++;
			ans += acc[0];
		}
	}
	cout << ans << "\n";
	return 0;
}