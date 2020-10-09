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

int n, m;
int v[MAXN];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	vi v(n);
	bool has0, has1;
	has0 = has1;
	FOR(i, 0, n)
	{
		cin >> v[i];
		if(v[i] == 0) has0 = true;
		else has1 = true;
	}
	if(has0 && has1)
	{
		RFOR(i, n-2, 0)
		{
			if(v[i] != v[i+1])
			{
				printf("%d\n", i+1);
				break;
			}
		}
	}
	else
		printf("%d\n", n);
	return 0;
}