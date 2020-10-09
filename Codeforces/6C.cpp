#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define MAXN 200010
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9

int n;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while(cin >> n)
	{
		int v[n];
		FOR(i, 0, n) cin >> v[i];
		int a, b;
		vii t(n);
		int time = 0;
		FOR(i, 0, n)
		{
			t[i].first = time;
			time += v[i];
		}
		time = 0;
		RFOR(i, n-1, 0)
		{
			t[i].second = time;
			time += v[i];
		}
		a = b = 0;
		FOR(i, 0, n)
		{
			if(t[i].first <= t[i].second) a++;
			else b++;
		}
		printf("%d %d\n", a, b);
	}
	return 0;
}