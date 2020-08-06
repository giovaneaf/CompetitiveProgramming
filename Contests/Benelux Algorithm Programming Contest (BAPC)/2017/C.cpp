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
#define MAXN 500010
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL
 
#define ITER 1000000
#define DEBUG 0
 
int n, m;
ll v;
ll gcd[MAXN];
set<ll> s;
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	while(cin >> n)
	{
		s.clear();
		int len = 0;
		int tmp;
		FOR(i, 0, n)
		{
			cin >> v;
			FOR(j, 0, len)
			{
				gcd[j] = __gcd(v, gcd[j]);
			}
			gcd[len++] = v;
			sort(gcd, gcd + len);
			tmp = 0;
			FOR(j, 0, len)
			{
				s.insert(gcd[j]);
				if(j == 0)
				{
					gcd[tmp++] = gcd[j];
					continue;
				}
				if(gcd[j] == gcd[j-1]) continue;
				else gcd[tmp++] = gcd[j];
			}
			len = tmp;
		}
		printf("%d\n", (int) s.size());
	}
	return 0;
}