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
#define MAXN 1010
#define LOGMAXN 20
#define MAXM 100010
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL
 
#define ITER 10000000
 
#define DEBUG 0

ll a, b;
ll dx[] = {1, -1, 0, 0};
ll dy[] = {0, 0, 1, -1};
ll x[MAXN];
ll y[MAXN];

inline int toInt(char c)
{
	if(c == 'R') return 0;
	if(c == 'L') return 1;
	if(c == 'U') return 2;
	return 3;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> a >> b)
	{
		string s;
		cin >> s;
		ll gx, gy;
		gx = gy = 0;
		int cnt[4] = {};
		FOR(i, 0, (int) s.size())
		{
			int id = toInt(s[i]);
			gx += dx[id];
			gy += dy[id];
			x[i] = gx; y[i] = gy;
			cnt[id]++;
		}
#if DEBUG
		FOR(i, 0, 4)
		{
			printf("%d ", cnt[i]);
		}
		putchar('\n');
		printf("%d %d\n", gx, gy);
#endif
		bool can = false;
		FOR(i, 0, (int) s.size())
		{
			if(gx == 0 && a == x[i])
			{
				if(gy == 0)
				{
					if(b == y[i])
					{
						can = true;
						break;
					}
				}
				else if((b-y[i])%gy == 0)
				{
					int cy = (b-y[i])/gy;
					if(cy < 0) continue;
					can = true;
					break;
				}
			}
			if(gx != 0 && ((a-x[i])%gx == 0))
			{
				int cx = (a-x[i])/gx;
#if DEBUG
				printf("%d %d %d %d\n", cx, y[i], gy, b);
#endif
				if(cx < 0) continue;
				if(y[i]+cx*gy == b)
				{
					can = true;
					break;
				}
			}
		}
		if(a == 0 && b == 0) can = true;
		printf("%s\n", can ? "Yes" : "No");
	}
	return 0;
}