#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 100010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9

int n, m, q, k;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	while(cin >> t)
	{
		cin >> n;
		if(n == 0) break;
		int v[n];
		FOR(i, 0, n) cin >> v[i];
		set<vi> ans;
		printf("Sums of %d:\n", t);
		FOR(i, 0, (1 << n))
		{
			int sum = 0;
			vi x;
			FOR(j, 0, n)
			{
				if((i & (1 << j)) > 0)
				{
					x.emplace_back(v[j]);
					sum += v[j];
				}
			}
			if(sum == t)
			{
				ans.insert(x);
			}
		}
		if(ans.size() == 0)
		{
			printf("NONE\n");
		}
		else
		{
			auto it = ans.end();
			it--;
			while(it != ans.begin())
			{
				auto a = *it;
				FOR(i, 0, (int) a.size())
				{
					if(i > 0) putchar('+');
					printf("%d", a[i]);
				}
				putchar('\n');
				it--;
			}
			auto a = *it;
			FOR(i, 0, (int) a.size())
			{
				if(i > 0) putchar('+');
				printf("%d", a[i]);
			}
			putchar('\n');
		}
	}
    return 0;
}
