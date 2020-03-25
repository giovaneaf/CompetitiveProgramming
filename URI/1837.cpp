#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define MAXN 4100
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9

int mod(int a, int b)
{
	if(b < 0) b = -b;
	int r = a%b;
	if(r < 0) r += b;
	return r;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int a, b;
	while(cin >> a >> b)
	{
		int r = mod(a, b);
		int q = (a-r)/b;
		printf("%d %d\n", q, r);
	}
	return 0;
}
