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
#define EPS 1e-9

int n;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	string a, b;
	while(getline(cin, a))
	{
		getline(cin, b);
		int len = 0;
		FOR(i, 0, (int)b.size())
		{
			FOR(j, i, (int) b.size())
			{
				int pos = a.find(b.substr(i, j-i+1));
				if(pos != -1) len = max(len, j-i+1);
			}
		}
		cout << len << '\n';
	}
	return 0;
}
