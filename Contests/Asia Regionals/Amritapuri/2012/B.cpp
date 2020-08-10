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
#define MAXN 1000010
#define LOGMAXN 21
#define MAXM 250010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

ll mod = 1000000007LL;

int T, n, m;
int ans, a, b;
int indeg[MAXN];
int outdeg[MAXN];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	FOR(t, 0, T)
	{
		FOR(i, 0, n)
		{
			indeg[i] = outdeg[i] = 0;
		}
		ans = -1;
		cin >> n >> m;
		FOR(i, 0, m)
		{
			cin >> a >> b;
			a--, b--;
			indeg[b]++; outdeg[a]++;
		}
		FOR(i, 0, n)
		{
			if(indeg[i] == 0 && outdeg[i] == n-1-i)
			{
				ans = 1;
				printf("2 %d\n", i+1);
				break;
			}
		}
		if(ans == -1) 
			printf("1\n");
	}
	return 0;
}
