#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, int> ip;
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
#define MAXN 110
#define LOGMAXN 23
#define MAXM 1000010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

const ll mod = 1000000007LL;

int n;

int M[MAXN][MAXN];

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		memset(M, 0, sizeof(M));
		int d, l, r, c;
		bool valid = true;
		FOR(i, 0, n)
		{
			cin >> d >> l >> r >> c;
			r--, c--;
			if(d == 0 && c+l > 10) valid = false;
			else if(d == 1 && r+l > 10) valid = false;
			if(!valid) continue;
			FOR(i, 0, l)
			{
				if(d == 0) M[r][c+i]++;
				else M[r+i][c]++;
			}
		}
		FOR(i, 0, 10) FOR(j, 0, 10) if(M[i][j] > 1) { valid = false; break; }
		printf("%c\n", valid ? 'Y' : 'N');
	}
	return 0;
}