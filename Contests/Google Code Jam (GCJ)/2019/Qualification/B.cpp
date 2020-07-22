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
		int n;
		cin >> n;
		map<ii, int> mm;
		string s;
		cin >> s;
		int r, c;
		r = c = 0;
		for(char ch : s)
		{
			if(ch == 'E')
			{
				mm[mp(r, c)] = 1;
				c++;
			}
			else
			{
				mm[mp(r, c)] = 0;
				r++;
			}
		}
		string ans;
		r = c = 0;
		if(s[s.size()-1] == 'E')
		{
			while(r < n-1 || c < n-1)
			{
				if(c < n-1 && (mm.find(mp(r, c)) == mm.end() || mm[mp(r, c)] == 0))
				{
					c++;
					ans += 'E';
				}
				else
				{
					r++;
					ans += 'S';
				}
			}
		}
		else
		{
			while(r < n-1 || c < n-1)
			{
				if(r < n-1 && (mm.find(mp(r, c)) == mm.end() || mm[mp(r, c)] == 1))
				{
					r++;
					ans += 'S';
				}
				else
				{
					c++;
					ans += 'E';
				}
			}
		}
		printf("%s\n", ans.c_str());
	}
	return 0;
}