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
#define MAXN 100010
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007

int T;
int n;
int M[110][110];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	FOR(t, 1, T+1)
	{
		cin >> n;
		int trace = 0;
		FOR(i, 0, n)
		{
			FOR(j, 0, n)
			{
				cin >> M[i][j];
				if(i == j) trace += M[i][j];
			}
		}
		vb seen(n+1);
		int rows, cols;
		rows = cols = 0;
		FOR(i, 0, n)
		{
			fill(seen.begin(), seen.end(), false);
			FOR(j, 0, n)
			{
				if(seen[M[i][j]])
				{
					rows++;
					break;
				}
				seen[M[i][j]] = true;
			}
		}
		FOR(j, 0, n)
		{
			fill(seen.begin(), seen.end(), false);
			FOR(i, 0, n)
			{
				if(seen[M[i][j]])
				{
					cols++;
					break;
				}
				seen[M[i][j]] = true;
			}
		}
		printf("Case #%d: %d %d %d\n", t, trace, rows, cols);
	}
	return 0;
}

