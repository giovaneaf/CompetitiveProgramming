#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define MAXN 35
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9

int n, m;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		cin >> m >> n;
		map<string, string> mm;
		string s, ss;
		getline(cin, s);
		FOR(i, 0, m)
		{
			getline(cin, s);
			getline(cin, ss);
			mm[s] = ss;
		}
		FOR(i, 0, n)
		{
			getline(cin, s);
			stringstream sss(s);
			int j = 0;
			while(sss >> s)
			{
				if(j > 0) cout << ' ';
				if(mm.find(s) != mm.end()) s = mm[s];
				cout << s;
				j++;
			}
			cout << '\n';
		}
		cout << '\n';
	}
	return 0;
}