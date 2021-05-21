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
#define MAXN 100010
#define LOGMAXN 23
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

const ll mod = 1000000007LL;
int n, m;
int v[MAXN];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		FOR(i, 0, n) cin >> v[i];
		int ans, id;
		ans = INF;
		FOR(i, 0, n-2)
		{
			if(max(v[i], v[i+2]) < ans)
			{
				ans = max(v[i], v[i+2]);
				id = i+1;
			}
		}
		printf("%d %d\n", id, ans);
	}
	return 0;
}