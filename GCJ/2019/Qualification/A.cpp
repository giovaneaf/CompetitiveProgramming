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

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	FOR(t, 0, T)
	{
		printf("Case #%d: ", t+1);
		string s;
		cin >> s;
		string a, b;
		FOR(i, 0, s.size())
		{
			int v = int(s[i]-'0');
			if(v == 7)
			{
				a.push_back('2');
				b.push_back('5');
			}
			else if(v == 8)
			{
				a.push_back('3');
				b.push_back('5');
			}
			else if (v == 9)
			{
				a.push_back('3');
				b.push_back('6');
			}
			else
			{
				a.push_back((v+1)/2+'0');
				b.push_back(v/2+'0');
			}
		}
		a.erase(0, a.find_first_not_of('0'));
		b.erase(0, b.find_first_not_of('0'));
		printf("%s %s\n", a.c_str(), b.c_str());
	}
	return 0;
}