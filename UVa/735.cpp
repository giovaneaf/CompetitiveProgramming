#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
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
	while(cin >> n)
	{
		if(n <= 0)
		{
			printf("END OF OUTPUT\n");
			break;
		}
		bool can = false;
		int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 24, 26, 27, 28, 30, 32, 33, 34, 36, 38, 39, 40, 42, 45, 48, 50, 51, 54, 57, 60};
		int sz = sizeof(v)/sizeof(int);
		int c = 0;
		ll p = 0LL;
		FOR(i, 0, sz)
		{
			FOR(j, i, sz)
			{
				FOR(k, j, sz)
				{
					if(v[i]+v[j]+v[k] == n)
					{
						c++;
						if(v[i] == v[j] && v[j] == v[k]) p++;
						else if(v[i] == v[j]) p += 3;
						else if(v[j] == v[k]) p += 3;
						else p += 6;
						can = true;
					}
				}
			}
		}
		if(can)
		{
			printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", n, c);
			printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %lld.\n", n, p);
		}
		else
		{
			printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", n);
		}
		printf("**********************************************************************\n");
	}
    return 0;
}