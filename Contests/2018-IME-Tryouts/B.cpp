// Just followed the instructions
// Time Complexity: O(|s|) - Scan string's length

#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s;
	while(cin >> s)
	{
		if(s.size() == 0) continue;
		string ans;
		if(s[0] == 'C')
			ans.push_back('B');
		else
			ans.push_back('D');
		int cnt = 1;
		for(int i = 1; i < s.size(); ++i)
		{
			if(s[i] != s[i-1])
			{
				if(s[i] == 'C')
					ans.push_back('B');
				else
					ans.push_back('D');
				cnt = 1;
			}
			else
			{
				if(cnt == 2)
				{
					if(s[i] == 'C')
						ans.push_back('P');
					else
						ans.push_back('T');
					cnt = 0;
				}
				else
				{
					if(s[i] == 'C')
						ans.push_back('B');
					else
						ans.push_back('D');
					cnt++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}