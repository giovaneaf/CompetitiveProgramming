/*
Add roots (change the signal of the polynomial) between an transition AH or HA. Note that the difference between then is 2
so you can add the root between then with integer coordinates.
So the polynomial looks like: (x-r1)*(x-r2)*(x-r3)*...*(x-rn).
You can multiply the polynomials naively.
Since the roots aren't 0 you can check the independent term to check if it's positive or negative at x=0, so you can 
multiply all coefficients by -1 if it started in the wrong signal
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
#define MAXN 10010
#define LOGMAXN 20
#define MAXM 1000010
#define INF 1000000007
#define INFLL 10000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL

string s;
ll root[MAXN];
ll coeff[MAXN][2];

inline int getSignal(int degree, char fst)
{
	if(degree&1) // negative value
	{
		if(fst == 'A') return 1;
		else return -1;
	}
	else 		// positive value
	{
		if(fst == 'A') return -1;
		else return 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> s)
	{
		int n = (int) s.size();
		fill(root, root+n+5, -1);
		int cnt = 0;
		FOR(i, 0, n-1)
		{
			if(s[i] != s[i+1])
			{
				root[cnt++] = -(2*(i+1)+1);
			}
		}
		if(cnt == 0)
		{
			printf("0\n%d\n", (s[0] == 'H' ? 1 : -1));
			continue;
		}
		coeff[0][0] = 1;
		coeff[1][0] = root[0];
		int it = 1;
		FOR(i, 1, cnt)
		{
			coeff[0][it] = 1;
			FOR(j, 1, i+1)
			{
				coeff[j][it] = coeff[j-1][it^1]*root[i] + coeff[j][it^1];
			}
			coeff[i+1][it] = coeff[i][it^1]*root[i];
			it ^= 1;
		}
		it ^= 1;
		printf("%d\n", cnt);
		int signal = getSignal(cnt, s[0]);
		FOR(i, 0, cnt+1)
		{
			if(i > 0) putchar(' ');
			printf("%lld", signal*coeff[i][it]);
		}
		putchar('\n');
	}
	return 0;
}

