#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; ++i)

int main()
{
	set<set<char>> s;
	int n;
	cin >> n;
	REP(i, n)
	{
		set<char> st;
		string str;
		cin >> str;
		REP(i, str.size())
		{
			st.insert(str[i]);
		}
		s.insert(st);
	}
	cout << s.size() << "\n";
	return 0;
}