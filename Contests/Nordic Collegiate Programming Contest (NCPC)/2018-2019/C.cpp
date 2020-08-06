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
#define MAXN 110
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
		vi v(n+1);
		FOR(i, 0, n)
		{
			cin >> v[i];
		}
		int cnt, ans, acc;
		ans = 0;
		cnt = 1;
		acc = 0;
		FOR(i, 1, n)
		{
			if(cnt*(v[i]-v[i-1]) + acc >= 20)
			{
				ans++;
				acc = 0;
				cnt = 1;
			}
			else
			{
				acc += (v[i]-v[i-1])*cnt;
				cnt++;
			}
		}
		printf("%d\n", ans+1);
	}
	return 0;
}
