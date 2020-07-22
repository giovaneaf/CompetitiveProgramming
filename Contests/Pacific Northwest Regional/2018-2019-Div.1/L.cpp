#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
#define MAXN 200010
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007LL
 
int n;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	while(cin >> n)
	{
		vii v(n);
		FOR(i, 0, n) cin >> v[i].fst >> v[i].snd;
		int ans = -1;
		int cnt;
		RFOR(people, n, 0)
		{
			cnt = 0;
			FOR(i, 0, n)
			{
				if(v[i].fst <= people && people <= v[i].snd) cnt++;
			}
			if(cnt == people)
			{
				ans = people;
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}