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
#define MAXN 510
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define MOD 1000000009

int n, k;
double memo[510][510];

void init(int n)
{
	FOR(i, 0, n)
	{
		memo[i][0] = memo[i][i] = 1;
		FOR(j, 1, i) memo[i][j] = memo[i-1][j] + memo[i-1][j-1];
	}
}

double combination(int n, int k)
{
	if(k > n) return 0.0;
	return memo[n][k];
}

double v[MAXN];
double ans[MAXN];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	init(510);
	while(cin >> n >> k)
	{
		FOR(i, 0, n) cin >> v[i];
		if(k == 1)
		{
			FOR(i, 0, n)
			{
				if(i > 0) putchar(' ');
				printf("%.10f", (double) 100.0/n);
			}
			putchar('\n');
			continue;
		}
		double div, acc, res;
		int ptr, sub; 
		div = memo[n][k];
		FOR(i, 0, n)
		{
			ptr = (i-1+n)%n;
			acc = v[i];
			res = 0;
			sub = 2;
			while(ptr != i)
			{
				res += acc*combination(n-sub, k-2);
				acc += v[ptr];
				sub++;
				ptr = (ptr == 0 ? n-1 : ptr-1);
			}
			ans[i] = res/div;
		}
		FOR(i, 0, n)
		{
			if(i > 0) putchar(' ');
			printf("%.10f", ans[i]);
		}
		putchar('\n');
	}
	return 0;
}