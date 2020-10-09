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
	vector<int> v(n);
	FOR(i, 0, n)
	{
		cin >> v[i];
	}
	int ans = n-1;
	if(v[0] == v[n-1])
	{
		int a = 0;
		int b = n-1;
		while(a < n && v[a] == v[0])
		{
			a++;
		}
		while(b >= 0 && v[b] == v[0])
		{
			b--;
		}
		ans = max(max(b, n-1-b), max(a, n-1-a));
	}
	printf("%d\n", ans);
	return 0;
}