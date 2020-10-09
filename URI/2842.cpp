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
#define MAXN 1010
#define LOGMAXN 23
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

const ll mod = 1000000007LL;

int n, k;
int memo[MAXN][MAXN];
string a, b;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int na, nb;
	while(cin >> a >> b)
	{
		a = 'x' + a;
		b = 'y' + b;
		na = (int) a.size();
		nb = (int) b.size();
		FOR(i, 0, na) memo[i][0] = 0;
		FOR(j, 0, nb) memo[0][j] = 0;
		int lcs = 0;
		FOR(i, 1, na)
		{
			FOR(j, 1, nb)
			{
				memo[i][j] = max(memo[i-1][j-1], max(memo[i-1][j], memo[i][j-1]));
				if(a[i] == b[j]) memo[i][j] = max(memo[i][j], 1 + memo[i-1][j-1]);
				lcs = max(memo[i][j], lcs);
			}
		}
		printf("%d\n", na+nb-2-lcs);
	}
	return 0;
}