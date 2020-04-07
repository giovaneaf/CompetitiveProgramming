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

int T, n, d, id, flavor;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	FOR(t, 1, T+1)
	{
		cin >> n;
		vi f(n+1, 0);
		vb av(n+1, true);
		FOR(i, 0, n)
		{
			cin >> d;
			if(d == -1) break;
			id = -1;
			FOR(j, 0, d)
			{
				cin >> flavor;
				f[flavor]++;
				if(av[flavor] && (id == -1 || f[flavor] < f[id])) id = flavor;
			}
			if(id > -1) av[id] = false;
			printf("%d\n", id);
			fflush(stdout);
		}
		if(d == -1) break;
	}
	return 0;
}

