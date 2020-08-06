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
#define MAXM 100000001
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

ll mod = 1000000007LL;

struct frog
{
	int l, w, h;
	bool operator< (const frog& f)
	{
		return w > f.w;
	}
};

int n, d;
frog v[MAXN];
int H[MAXM];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> d)
	{
		fill(H, H+MAXM, 0);
		FOR(i, 0, n)
		{
			cin >> v[i].l >> v[i].w >> v[i].h;
		}
		sort(v, v+n);
		int ans = 0;
		FOR(i, 0, n)
		{
			if(v[i].l + H[v[i].w] > d) ans++;
			FOR(w, 1, v[i].w)
			{
				H[w] = max(H[w], min(v[i].h + H[min(v[i].w+w, MAXM-1)], MAXM));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
