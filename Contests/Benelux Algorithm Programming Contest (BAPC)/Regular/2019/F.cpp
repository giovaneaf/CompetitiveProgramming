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
#define LOGMAXN 21
#define MAXM 250010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

ll mod = 1000000007LL;
int n, k;
int ans[MAXN];
int v[MAXN];
int mx[MAXN];
int sz;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> k)
	{
		sz = 0;
		int h;
		FOR(i, 0, k)
		{
			cin >> n;
			FOR(i, 0, n) cin >> v[i];
			set<int> s;
			set<int>::iterator it;
			mx[n-1] = v[n-1];
			RFOR(j, n-2, 0)
			{
				mx[j] = max(mx[j+1], v[j]);
			}
			s.insert(v[0]);
			FOR(j, 1, n-1)
			{
				h = mx[j+1];
				it = s.lower_bound(h);
				if(it != s.begin())
				{
					it--;
					if(v[j] < *it)
					{
						ans[sz++] = i+1;
						break;
					}
				}
				s.insert(v[j]);
			}
		}
		printf("%d\n", sz);
		FOR(i, 0, sz)
		{
			printf("%d\n", ans[i]);
		}
	}
	return 0;
}
