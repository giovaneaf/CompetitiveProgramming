#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define MAXN 300010
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s;
	while(getline(cin, s))
	{
		if(s[0] == '*') break;
		stringstream ss(s);
		string str;
		int last = -1;
		bool a = true;
		while(ss >> str)
		{
			if(last == -1)
			{
				last = tolower(str[0])-'a';
			}
			else if (tolower(str[0])-'a' != last)
			{
				a = false;
				break;
			}
		}
		printf("%c\n", a ? 'Y' : 'N');
	}
	return 0;
}

