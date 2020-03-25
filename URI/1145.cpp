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
	int x, y;
	cin >> x >> y;
	int v = 1;
	while(v <= y)
	{
		FOR(i, 0, x)
		{
			if(i > 0) printf(" ");
			printf("%d", v++);
		}
		putchar('\n');
	}
	return 0;
}

