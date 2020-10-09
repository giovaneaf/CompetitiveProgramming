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
#define MAXN 1010
#define LOGMAXN 23
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

const ll mod = 1000000007LL;

int n, k;
vector<ii> v;
int memo[MAXN];

int solve(int pos)
{
	if(pos == n) return 0;
	if(memo[pos] == -1)
	{
		auto it = lower_bound(v.begin(), v.end(), mp(v[pos].snd, -1));
		int idx = min(n, (int) distance(v.begin(), it));
		int ans = max(solve(pos+1), v[pos].snd-v[pos].fst+solve(idx));
		memo[pos] = ans;
	}
	return memo[pos];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		v.resize(n);
		FOR(i, 0, n)
		{
			cin >> v[i].fst >> v[i].snd;
		}
		sort(v.begin(), v.end());
		memset(memo, -1, sizeof(memo));
		printf("%d\n", solve(0));
	}
	return 0;
}