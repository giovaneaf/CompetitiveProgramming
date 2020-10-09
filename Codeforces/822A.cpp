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

inline int fat(int n)
{
	int ans = 1;
	RFOR(i, n, 1) ans *= i;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int a, b;
	while(cin >> a >> b)
	{
		printf("%d\n", fat(min(a, b)));
	}
	return 0;
}