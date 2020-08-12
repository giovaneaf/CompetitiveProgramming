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
#define MAXN 10010
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

int n;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		if(n == -1) break;
		int ans = 0;
		FOR(a, 1, n+1)
		{
			FOR(b, 1, n/a+1)
			{
				if(a*b > n || a < b) break;
				if(((n-a*b)%(a+b)) == 0 && b >= ((n-a*b)/(a+b)))
				{
					ans++;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}