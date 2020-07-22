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
#define MAXM 110
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007

int T;
int n;
ll x;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n;
		vii v(n);
		int a, b;
		bool can = true;
		cin >> v[0].fst >> v[0].snd;
		if(v[0].snd > v[0].fst) can = false;
		int ng, nc;
		FOR(i, 1, n)
		{
			cin >> v[i].fst >> v[i].snd;
			if(v[i].snd > v[i].fst)
			{
				can = false;
				continue;
			}
			ng = v[i].fst - v[i-1].fst;
			nc = v[i].snd - v[i-1].snd;
			if(ng < 0 || nc < 0 || nc > ng)
			{
				can = false;
				continue;
			}
		}
		printf("%s\n", can ? "YES" : "NO");
	}
	return 0;
}

