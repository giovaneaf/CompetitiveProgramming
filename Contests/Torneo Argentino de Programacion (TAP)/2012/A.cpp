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
#define MAXN 10010
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

int n;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		if(n == -1) break;
		vi v(n+1);
		bool finished;
		finished = true;
		FOR(i, 1, n+1)
		{
			cin >> v[i];
			if(v[i] > 0) finished = false;
		}
		int add, lst;
		while(!finished)
		{
			bool can = false;
			add = 0;
			lst = -1;
			finished = true;
			FOR(i, 1, n+1)
			{
				if(v[i] == i)
				{
					v[i] = 0;
					add = 1;
					lst = i;
					can = true;
					break;
				}
			}
			FOR(i, 1, n+1)
			{
				if(lst == i) 
					add = 0;
				v[i] += add;
				if(v[i] > 0)
				{
					finished = false;
				}
			}
			if(!can) break;
		}
		printf("%c\n", finished ? 'S' : 'N');
	}
	return 0;
}