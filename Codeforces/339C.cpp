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
#define MAXN 1010
#define LOGMAXN 20
#define MAXM 100010
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL
 
#define ITER 10000000
 
#define DEBUG 0

int n;
int v[MAXN];
int memo[MAXN][15][11];
string s;

bool solve(int pos, int diff, int w)
{
	if(pos == n) return true;
	if(memo[pos][diff][w] == -1)
	{
		FOR(i, 0, 10)
		{
			if(s[i] == '1' && i != w)
			{
				v[pos] = i+1;
				int ndiff = i+1 - diff;
				if(ndiff <= 0) continue;
				if(solve(pos+1, ndiff, i))
				{
					return memo[pos][diff][w] = true;
				}
			}
		}
	}
	return memo[pos][diff][w] = false;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> s)
	{
		memset(memo, -1, sizeof(memo));
		cin >> n;
		if(solve(0, 0, 14))
		{
			printf("YES\n");
			FOR(i, 0, n)
			{
				if(i > 0) putchar(' ');
				printf("%d", v[i]);
			}
			putchar('\n');
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}