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
#define MAXN 100010
#define LOGMAXN 21
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

const ll mod = 1000000007LL;

int n;
ii v[MAXN];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		FOR(i, 0, n)
		{			
			cin >> v[i].fst;
			v[i].snd = i+1;
		}
		sort(v, v+n);
		int acc = 0;
		FOR(i, 0, n-1)
		{
			acc += v[i].fst;
		}
		if(acc >= v[n-1].fst) 
		{
			RFOR(i, n-1, 0)
			{
				if(i < n-1) putchar(' ');
				printf("%d", v[i].snd);
			}
		}
		else
		{
			printf("impossible");
		}
		puts("");
	}
	return 0;
}