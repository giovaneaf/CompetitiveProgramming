#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		int ans = 0;
		bool has = false;
		for(int i = 0; i < s.size(); ++i)
		{
			if(has)
			{
				has = false;
				ans++;
				i++;
			}
			else if(s[i] == '.') has = true;			
		}
		if(has) ans++;
		printf("Case %d: %d\n", t, ans);
	}
	return 0;
}