#include <bits/stdc++.h>
 
#define MAXN 10001
#define MOD 10000007
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
 
int n;
 
int main()
{
	while(scanf("%d", &n))
	{
		if(n == 0) break;
		int maxGlobal = 0;
		int maxLocal = 0;
		for(int i = 0; i < n; ++i)
		{
			int cur;
			scanf("%d", &cur);
			maxLocal = max(0, maxLocal + cur);
			maxGlobal = max(maxGlobal, maxLocal);
		}
		if(maxGlobal == 0)
			printf("Losing streak.\n");
		else
			printf("The maximum winning streak is %d.\n", maxGlobal);
	}
	return 0;
}