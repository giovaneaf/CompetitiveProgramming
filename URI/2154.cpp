#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define MAXN 60
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9

int n, m;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		string s;
		FOR(i, 0, n)
		{
			cin >> s;
			int pos = s.find('x');
			int v1 = stoi(s.substr(0, pos));
			int v2 = stoi(s.substr(pos+1, (int) s.size()));
			printf("%dx", v1*v2);
			v2--;
			if(v2 > 1) printf("%d", v2);
			if(i < n-1)
			{
				cin >> s;
				printf(" + ");
			}
		}
		putchar('\n');
	}
	return 0;
}
