#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
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
#define MAXN 3001
#define LOGMAXN 20
#define MAXM 1000010
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL
 
struct Aquarium
{
	int m, f;
	bool operator< (const Aquarium& a) const
	{
		if(m == a.m) return f < a.f;
		return m < a.m;
	}
};
 
int n;
int memo[MAXN][MAXN][2][2];
Aquarium v[MAXN];
 
int solve(int cur, int qempty1, int has1, int has2)
{
	if(cur == n)
		return (has1 && has2) ? 0LL : INF;
	if(memo[cur][qempty1][has1][has2] == -1)
	{
		int ans = solve(cur+1, qempty1 + (v[cur].m == 0 && v[cur].f == 0), 1, has2);
		if(ans < INF)
			ans += max(0, v[cur].m + v[cur].f - 1);
		int tmp = solve(cur+1, qempty1 - min(qempty1, v[cur].m), has1, 1);
		if(tmp < INF)
			tmp += 2*v[cur].m - min(qempty1, v[cur].m);
		memo[cur][qempty1][has1][has2] = min(ans, tmp);
	}
	return memo[cur][qempty1][has1][has2];
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		FOR(i, 0, n)
			FOR(j, 0, n)
				FOR(k, 0, 2)
					FOR(l, 0, 2)
						memo[i][j][k][l] = -1;
		int sumM = 0;
		FOR(i, 0, n)
		{
			cin >> v[i].m >> v[i].f;
			sumM += v[i].m;
		}
		sort(v, v+n);
		int ans = 0;
		if(sumM > 0)
			ans = solve(0, 0, 0, 0);
		printf("%d\n", ans);
	}
	return 0;
}
