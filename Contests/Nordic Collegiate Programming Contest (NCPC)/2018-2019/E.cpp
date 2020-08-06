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
#define MAXN 2510
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

ll mod = 1000000007;

int n, m, d;
map<vi, double> memo;
vi v;

double solve(int cnt, int soldiers)
{
	if(v[7] == m) return 1.0;
	if(cnt == d) return 0.0;
	if(memo.find(v) == memo.end())
	{
		int newSoldiers;
		double ans = 0.0;
		double prob = (double) 1.0/soldiers;
		FOR(i, 0, 14)
		{
			if(i == 0 || i == 7) continue;
			if(v[i] > 0)
			{
				v[i]--;
				v[i-1]++;
				if(i == 1 || i == 8)
					newSoldiers = soldiers-1;
				else
					newSoldiers = soldiers;
				ans += (v[i]+1)*prob*solve(cnt+1, newSoldiers);
				v[i]++;
				v[i-1]--;
			}
		}
		memo[v] = ans;
	}
	return memo[v];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m >> d)
	{
		v.assign(14, 0);
		int totHealth = 0;
		int x;
		FOR(i, 0, n)
		{
			cin >> x;
			v[x]++;
			totHealth += x;
		}
		FOR(i, 0, m)
		{
			cin >> x;
			v[x+7]++;
			totHealth += x;
		}
		if(totHealth <= d)
		{
			printf("%.10f\n", 1.0);
		}
		else
		{
			solve(0, n+m);
			printf("%.10f\n", memo[v]);
		}
		memo.clear();
	}
	return 0;
}
