/*
Followed the instructions
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while(cin >> n)
	{
		set<string> s;
		for(int i = 0; i < n; ++i)
		{
			string in;
			cin >> in;
			string str;
			int j = 0;
			bool ignore = false;
			for(j = 0; j < in.size(); ++j)
			{
				if(in[j] == '@') break;
				if(in[j] == '.') continue;
				if(in[j] == '+') ignore = true;
				else if(!ignore) str.push_back(in[j]);
			}
			j++;
			in = in.substr(j, in.size()-j+1);
			str += in;
			s.insert(str);
		}
		cout << s.size() << '\n';
	}
	return 0;
}