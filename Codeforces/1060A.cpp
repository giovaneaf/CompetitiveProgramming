#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while(cin >> n)
	{
		string s;
		cin >> s;
		//cout << s << '\n';
		int eights = 0;
		for(int i = 0; i < s.size(); ++i)
		{
			if(s[i] == '8') eights++;
		}
		printf("%d\n", min(eights, n/11));
	}
	return 0;
}