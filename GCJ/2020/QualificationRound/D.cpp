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

int T, B;
int l, r;
int v[110];
int eq, op, bit, pos;
int a, b, q;
char ans;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T >> B;
	FOR(t, 1, T+1)
	{
		eq = op = -1;
		l = 0, r = B-1;
		FOR(i, 0, 10)
		{
			pos = (i&1) ? r-- : l++;
			printf("%d\n", pos+1);
			fflush(stdout);
			cin >> bit;
			v[pos] = bit;
		}
		FOR(i, 0, 5)
		{
			if(v[i] == v[B-1-i]) eq = i;
			else op = i;
		}
		while(r > l)
		{
			if(eq > -1 && op > -1)
			{
				printf("%d\n", eq+1);
				fflush(stdout);
				cin >> a;
				printf("%d\n", op+1);
				fflush(stdout);
				cin >> b;
				if(a != v[eq] && b != v[op])
				{
					// complement
					FOR(i, 0, l)
					{
						v[i] ^= 1; v[B-1-i] ^= 1;
					}
				}
				else if(a == v[eq] && b != v[op])
				{
					// inversion
					FOR(i, 0, l)
					{
						swap(v[i], v[B-1-i]);
					}
				}
				else if(a != v[eq] && b == v[op])
				{
					// comp-inv
					FOR(i, 0, l)
					{
						swap(v[i], v[B-1-i]);
						v[i] ^= 1; v[B-1-i] ^= 1;
					}
				}
				else
				{
					// equal, nothing to do
				}
			}
			else
			{
				pos = (eq > -1 ? eq : op);
				printf("%d\n", pos+1);
				fflush(stdout);
				cin >> a;
				printf("%d\n", pos+1);
				fflush(stdout);
				cin >> a;
				if(a != v[pos])
				{
					FOR(i, 0, l)
					{
						v[i] ^= 1; v[B-1-i] ^= 1;
					}
				}
			}
			FOR(i, 0, 8)
			{
				pos = (i&1) ? r-- : l++;
				printf("%d\n", pos+1);
				fflush(stdout);
				cin >> bit;
				v[pos] = bit;
				if(r < l) break;
			}
			if(eq == -1 || op == -1)
			{
				RFOR(i, l-1, l-5)
				{
					if(v[i] == v[B-1-i]) eq = i;
					else op = i;
				}
			}
		}
		FOR(i, 0, B) printf("%d", v[i]);
		putchar('\n');
		fflush(stdout);
		cin >> ans;
		if(ans == 'N') break;
	}
	return 0;
}

