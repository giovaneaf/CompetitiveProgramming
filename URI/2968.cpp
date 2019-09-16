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
#define MAXN 100010
#define LOGMAXN 20
#define INF 1e9+7
#define INFLL 1000000000000000000LL
#define EPS 1e-9

int main()
{
	int v, n;
	while(cin >> v >> n)
	{
		FOR(i, 1, 10)
		{
			if(i > 1) putchar(' ');
			printf("%d", (v*n*i+9)/10);
		}
		putchar('\n');
	}
	return 0;
}