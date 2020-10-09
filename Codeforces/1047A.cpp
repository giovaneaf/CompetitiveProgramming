#include <bits/stdc++.h>

#define MAXN 100010
#define INF 1e9
#define EPS 1e-9

#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define mp(a, b) make_pair(a, b)

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef long long ll;

int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while(cin >> n)
	{
		int d3 = n/3;
		int r3 = n%3;
		bool found = false;
		for(int i = -3; i < 3 && !found; ++i)
		{
			for(int j = -3; j < 3 && !found; ++j)
			{
				for(int k = -3; k < 3 && !found; ++k)
				{
					int n1 = d3+i;
					int n2 = d3+j;
					int n3 = d3+k;
					if(n1 + n2 + n3 == n && n1%3 && n2%3 && n3%3 && n1 > 0 && n2 > 0 && n3 > 0)
					{
						printf("%d %d %d\n", n1, n2, n3);
						found = true;
					}
				}
			}
		}
	}
	return 0;
}
