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
#define MAXN 200010
#define LOGMAXN 20
#define MAXM 1000010
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL

int n, k;
ll memo[MAXN];
pair<ll, int> v[MAXN];
int vv[MAXN];

ll solve(int pos)
{
	if(pos > n) return INF;
	if(pos == n) return 0LL;
	if(pos+3 > n) return INF;
	if(memo[pos] == -1LL)
	{
		ll ans = solve(pos+3) + v[pos+2].fst - v[pos].fst;
		ll tmp;
		if(pos+4 <= n)
		{
			tmp = solve(pos+4) + v[pos+3].fst - v[pos].fst;
			if(ans > tmp)
			{
				ans = tmp;
			}
		}
		if(pos+5 <= n)
		{
			tmp = solve(pos+5) + v[pos+4].fst - v[pos].fst;
			if(ans > tmp)
			{
				ans = tmp;
			}
		}
		memo[pos] = ans;
	}
	return memo[pos];
}

void recoverAns(int pos, int color)
{
	if(pos >= n)
	{	
		k = color-1;
		return ;
	}
	if(memo[pos+3] + v[pos+2].fst - v[pos].fst == memo[pos])
	{
		FOR(i, 0, 3)
		{
			vv[v[pos+i].snd] = color;
		}
		recoverAns(pos+3, color+1);
	}
	else if(pos+4 <= n && memo[pos+4] + v[pos+3].fst - v[pos].fst == memo[pos])
	{
		FOR(i, 0, 4)
		{
			vv[v[pos+i].snd] = color;
		}
		recoverAns(pos+4, color+1);
	}
	else if (pos+5 <= n)
	{
		FOR(i, 0, 5)
		{
			vv[v[pos+i].snd] = color;
		}
		recoverAns(pos+5, color+1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		ll x;
		FOR(i, 0, n)
		{
			cin >> x;
			v[i] = mp(x, i);
		}
		fill(memo, memo+n, -1LL);
		sort(v, v+n);
		ll ans = solve(0);
		int cnt = 1;
		recoverAns(0, 1);
		printf("%lld %d\n", ans, k);
		FOR(i, 0, n)
		{
			if(i > 0) putchar(' ');
			printf("%d", vv[i]);
		}
		putchar('\n');
	}
	return 0;
}
