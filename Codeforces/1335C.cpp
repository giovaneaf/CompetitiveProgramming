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
#define LOGMAXN 20
#define MAXM 110
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007

int T;
int n, x;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n;
		vi f(n, 0);
		map<int, int> mm;
		int sz = 0;
		FOR(i, 0, n)
		{
			cin >> x;
			if(mm.find(x) == mm.end())
			{
				mm[x] = sz++;
			}
			f[mm[x]]++;
		}
		sort(f.begin(), f.begin()+sz);
		int ans = 0;
		int h = f[sz-1];
		ans = max(ans, min(h, sz-1));
		RFOR(i, h-1, 0)
			ans = max(ans, min(i, sz));
		printf("%d\n", ans);
	}
	return 0;
}
