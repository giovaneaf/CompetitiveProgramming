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

int n;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n)
    {
		if(n == 1)
		{
			printf("0\n");
			continue;
		}
        vector<int> v;
		FOR(i, 2, n+1)
		{
			int sqrti = ceil(sqrt(i));
			int GCD = i;
			FOR(j, 2, sqrti)
			{
				if((i%j) == 0)
				{
					GCD = __gcd(GCD, j);
					GCD = __gcd(GCD, i/j);
				}
			}
			if(GCD > 1) v.push_back(i);
		}
		printf("%d\n", (int) v.size());
		printf("%d", v[0]);
		FOR(i, 1, v.size())
		{
			printf(" %d", v[i]);
		}
		printf("\n");
    }
	return 0;
}