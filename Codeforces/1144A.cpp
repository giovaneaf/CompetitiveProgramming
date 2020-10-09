#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define MAXN 100010
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9

bool solve(int lr, int hr, int lc, int hc, int tgt, string* s)
{
	int sum = 0;
	FOR(i, lr, hr)
	{
		FOR(j, lc, hc)
		{
			if(s[i][j] == '@') sum++;
		}
	}
	return sum == tgt;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	FOR(i, 0, n)
	{
		string str;
		cin >> str;
		set<int> s;
		bool can = true;
		FOR(i, 0, (int) str.size())
		{
			if(s.count(str[i]-'a') == 1)
			{
				can = false;
				break;
			}
			s.insert(str[i]-'a');
		}
		int pos = *s.begin();
		auto it = s.begin();
		it++;
		for(;it != s.end(); ++it)
		{
			if(pos+1 != *it)
			{
				can = false;
				break;
			}
			pos++;
		}
		printf("%s\n", can ? "Yes" : "No");
	}
	return 0;
}