#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, bool> ib;
 
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define all(v) v.begin(), v.end()
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 100010
#define LOGMAXN 21
#define MAXM 250010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

ll mod = 1000000007LL;

int n;
int v[11];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		int votes = 0;
		FOR(i, 0, n)
		{			
			cin >> v[i];
			votes += v[i];
		}
		sort(v, v+n);
		double percent = (double) v[n-1]*100.0/votes;
		if(percent > 45.0 || abs(percent - 45.0) < EPS)
		{
			printf("1\n");
			continue;
		}
		if(percent > 40.0 || abs(percent - 40.0) < EPS)
		{
			bool has10 = false;
			double tmp;
			FOR(i, 0, n-1)
			{
				tmp = (double) v[i]*100.0/votes;
				if(percent - tmp > 10.0 || abs(percent - tmp - 10.0) < EPS) continue;
				has10 = true;
			}
			printf("%d\n", has10 ? 2 : 1);
			continue;
		}
		printf("2\n");
	}
	return 0;
}
