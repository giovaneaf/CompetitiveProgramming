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
#define MAXN 50010
#define LOGMAXN 20
#define MAXM 250010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

ll mod = 1000000007LL;

int T, n;
char c;
ll t0, s, r;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	ll p = 31LL;
	FOR(t, 0, T)
	{
		printf("Case #%d:\n", t+1);
		cin >> n;
		priority_queue<ll> pq[110];
		FOR(i, 0, n)
		{
			cin >> c;
			if(c == 'P')
			{
				cin >> t0 >> s >> r;
				pq[r].push(s - r*t0);
			}
			else
			{
				cin >> t0;
				int ans = -1;
				FOR(j, 0, 101)
				{
					if(pq[j].empty()) continue;
					if(ans == -1 || pq[j].top() + j*t0 >= pq[ans].top() + ans*t0)
						ans = j;
				}
				if(ans == -1) continue;
				printf("%lld %d\n", pq[ans].top() + ans*t0, ans);
				pq[ans].pop();
			}
		}
	}
	return 0;
}
