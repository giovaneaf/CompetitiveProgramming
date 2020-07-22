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
#define MAXN 1010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9
 
int n, m, s;
 
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> s)
	{
		int v = 0;
		FOR(i, 0, n)
		{
			int val;
			cin >> val;
			v = max(val, v);
		}
		printf("%d\n", (int) ceil((double) v/1000.0*s));
	}
	return 0;
} 