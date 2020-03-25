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
bool seen[1010];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		ll pa, pb;
		double ga, gb;
		cin >> pa >> pb >> ga >> gb;
		//printf("%lld %lld\n", pa, pb);
		ga /= 100.0;
		gb /= 100.0;
		bool ans = false;
		if(ga > gb)
		{
			FOR(i, 1, 101)
			{
				pa = pa*(1.0+ga);
				pb = pb*(1.0+gb);
				//printf("%lld %lld\n", pa, pb);
				if(pa > pb)
				{
					ans = true;
					printf("%d anos.\n", i);
					break;
				}
			}
		}
		if(!ans) printf("Mais de 1 seculo.\n");
	}
	return 0;
}

