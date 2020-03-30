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
#define MAXN 1000010
#define LOGMAXN 20
#define MAXM 100010
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL
 
#define ITER 1000000
#define DEBUG 0
 
int n, m;
int mn[MAXN];
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		vi v(n);
		int a, b;
		a = 0; b = 1;
		bool can = true;
		FOR(i, 0, n)
		{
			cin >> v[i];
			if(i > 0 && v[i] < v[i-1]) can = false;
		}
		if(can)
		{
			printf("1 1\n");
			continue;
		}
		mn[n-1] = n-1;
		RFOR(i, n-2, 0)
		{
			if(v[mn[i+1]] <= v[i])
			{
				mn[i] = mn[i+1];
			}
			else
			{
				mn[i] = i;
			}
		}
		int id;
		can = true;
		FOR(i, 0, n-1)
		{
			id = mn[i];
			if(v[id] < v[i] && id > i)
			{
				a = i;
				b = id;
				break;
			}
		}
		FOR(i, 1, a)
		{
			if(v[i] < v[i-1])
			{
				can = false;
				break;
			}
		}
		FOR(i, a+1, b+1)
		{
			if(v[i] > v[i-1])
			{
				can = false;
				break;
			}
		}
		FOR(i, b+2, n)
		{
			if(v[i] < v[i-1])
			{
				can = false;
				break;
			}
		}
		if(can)
			printf("%d %d\n", a+1, b+1);
		else
			printf("impossible\n");
	}
	return 0;
}