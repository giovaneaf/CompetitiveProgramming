#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
#define MAXN 300010
#define LOGMAXN 23
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

const ll mod = 1000000007LL;

int n, m, k;
int v[1000010];
int memo[1000010][2][2];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		memset(v, 0, sizeof(v));
		int x;
		FOR(i, 0, n)
		{			
			cin >> x;
			v[x] = 1;
		}
		cin >> m;
		FOR(i, 0, m) 
		{
			cin >> x;
			if(v[x] == 1) v[x] = 3;
			else v[x] = 2;
		}
		k = 1000001;
		FOR(i, 0, 2) FOR(j, 0, 2) memo[k][i][j] = 0;
		for(k = 1000000; k >= 0; k--)
		{
			FOR(i, 0, 2) FOR(j, 0, 2) memo[k][i][j] = memo[k+1][i][j];
			if(v[k] == 0) continue;
			if(v[k] == 1)
			{
				memo[k][false][false] = max(memo[k][false][false], 1 + memo[k+1][false][true]);
				memo[k][true][false] = max(memo[k][true][false], 1 + memo[k+1][false][true]);
			}
			else if(v[k] == 2)
			{
				memo[k][false][false] = max(memo[k][false][false], 1 + memo[k+1][true][false]);
				memo[k][false][true] = max(memo[k][false][true], 1 + memo[k+1][true][false]);
			}
			else
			{
				memo[k][false][false] = max(memo[k][false][false], 1 + memo[k+1][false][false]);
				memo[k][true][false] = max(memo[k][true][false], 1 + memo[k+1][false][false]);
				memo[k][false][false] = max(memo[k][false][false], 1 + memo[k+1][false][false]);
				memo[k][false][true] = max(memo[k][false][true], 1 + memo[k+1][false][false]);
			}
		}
		printf("%d\n", memo[0][false][false]);
	}
	return 0;
}