/*

Bitmask DP and try each position minimizing the overall damage taken

*/

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
#define MAXN 2000010
#define LOGMAXN 20
#define MAXM 100010
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL
 
#define ITER 1000000
#define DEBUG 0

ll n;
int v[MAXN];
int memo[MAXN];

int solve(int mask, int dmg)
{
	if(mask == 0) return 0;
	if(memo[mask] == -1)
	{
		int ans = INF;
		int newDmg, newMask;
		FOR(i, 0, n)
		{
			newDmg = dmg;
			newMask = mask;
			if(mask&(1 << i))
			{
				FOR(j, 0, 3)
				{
					if(mask&(1 << ((i+j)%n)))
					{
						newMask = newMask & (~(1 << ((i+j)%n)));
						newDmg -= v[(i+j)%n];
					}
				}
				ans = min(ans, newDmg + solve(newMask, newDmg));
			}
		}
		memo[mask] = ans;
	}
	return memo[mask];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		int dmg = 0;
		FOR(i, 0, n)
		{			
			cin >> v[i];
			dmg += v[i];
		}
		FOR(i, 0, (1 << n)) memo[i] = -1;
		printf("%d\n", solve((1 << n) - 1, dmg));
	}
	return 0;
}