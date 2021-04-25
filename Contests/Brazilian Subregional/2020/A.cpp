#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, int> ip;
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
#define MAXN 1000010
#define LOGMAXN 23
#define MAXM 1000010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

const ll mod = 1000000007LL;

int n, a, b;
ld E[MAXN];

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> a >> b)
	{
		if(a == 0 && b == 0)
		{
			printf("%.10Lf\n", LDBL_MAX);
			continue;
		}
		memset(E, 0, sizeof(E));
		int cnt = 1;
		int lp, rp;
		rp = -b+1; lp = -a+1;
		ld acc = 0.0;
		ld sum = b-a+1;
		while(cnt <= n && rp <= 0)
		{
			if(lp >= 0) acc += E[lp];
			if(a > 0)
			{				
				E[cnt] = 1.0 + 1.0/sum*acc;
			}
			else
			{
				E[cnt] = ((ld) sum/(sum-1.0))*(1.0 + 1.0/sum*acc);
				acc += E[cnt];
			}
			cnt++; lp++; rp++;
		}
		while(cnt <= n)
		{
			acc -= E[rp-1];
			if(lp >= 0)	acc += E[lp];
			if(a > 0) 
			{
				E[cnt] = 1.0 + 1.0/sum*acc;
			}
			else 
			{
				E[cnt] = ((ld) sum/(sum-1.0))*(1.0 + 1.0/sum*acc);
				acc += E[cnt];
			}
			cnt++; lp++; rp++;
		}
		printf("%.10Lf\n", E[cnt-1]);
	}
	return 0;
}