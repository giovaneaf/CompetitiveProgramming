#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 1000010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9
 
struct show
{
	int l, r, id, o;
	show(int l = 0, int r = 0, int id = 0, int o = 0) : l(l), r(r), id(id), o(o) {}
	bool operator< (const show& p) { return l < p.l; }
};
 
int n, m, k;
int memo[(1 << 10)][1010];
vector<show> v;
 
 
int solve(int mask, int pos)
{
	//printf("%d %d\n", mask, pos);
	if(pos == (int) v.size())
	{
		if(mask == ((1 << n)-1)) return 0;
		else return -1;
	}
	if(memo[mask][pos] == INF)
	{
		int ans = solve(mask, pos+1);
		auto it = lower_bound(v.begin(), v.end(), show(v[pos].r, 0, 0, 0));
		int tmp = solve((mask | (1 << v[pos].id)), distance(v.begin(), it));
		if(tmp != -1)
			ans = max(ans, tmp+v[pos].o);
		memo[mask][pos] = ans;
	}
	return memo[mask][pos];
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		FOR(i, 0, n)
		{
			cin >> m;
			while(m--)
			{
				int l, r, o;
				cin >> l >> r >> o;
				v.emplace_back(show(l, r, i, o));
			}
		}
		sort(v.begin(), v.end());
		FOR(i, 0, (int) v.size())
		{
			FOR(j, 0, (1 << n))
			{
				memo[j][i] = INF;
			}
		}
		printf("%d\n", solve(0, 0));
		v.clear();
	}
}