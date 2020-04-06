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
int p, n;
int dr[MAXN][2];
int dc[MAXN][2];
int sumr[MAXN];
int sumc[MAXN];
int x, y;
char d;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	FOR(t, 1, T+1)
	{
		memset(dr, 0, sizeof(dr));
		memset(dc, 0, sizeof(dc));
		memset(sumr, 0, sizeof(sumr));
		memset(sumc, 0, sizeof(sumc));
		cin >> p >> n;
		n++;
		FOR(i, 0, p)
		{
			cin >> x >> y >> d;
			if(d == 'N')
			{
				dr[y+1][0]++;
			}
			else if(d == 'S')
			{
				dr[y-1][1]++;
			}
			else if(d == 'E')
			{
				dc[x+1][0]++;
			}
			else
			{
				dc[x-1][1]++;
			}
		}
		int sumY, sumX;
		sumY = sumX = 0;
		FOR(i, 0, n)
		{
			sumY += dr[i][0];
			sumr[i] += sumY;
			sumX += dc[i][0];
			sumc[i] += sumX;
		}
		sumY = sumX = 0;
		RFOR(i, n-1, 0)
		{
			sumY += dr[i][1];
			sumr[i] += sumY;
			sumX += dc[i][1];
			sumc[i] += sumX;
		}
		x = y = -1;
		FOR(i, 0, n)
		{
			if(x == -1 || sumc[x] < sumc[i])
			{
				x = i;
			}
			if(y == -1 || sumr[y] < sumr[i])
			{
				y = i;
			}
		}
		printf("Case #%d: %d %d\n", t, x, y);
	}
	return 0;
}
