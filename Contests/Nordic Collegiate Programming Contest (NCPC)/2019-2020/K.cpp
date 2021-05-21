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
#define MAXN 100010
#define LOGMAXN 23
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

const ll mod = 1000000007LL;
int n, m, s, d;
int c[MAXN];
int ans[MAXN];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m >> s >> d)
	{
		set<ii> st;
		int av = 0;
		FOR(i, 0, s) 
		{
			cin >> c[i];
			av += c[i];
			st.insert(mp(c[i], i));
			ans[i] = 0;
		}
		int mn, idx;
		while(n > 0)
		{
			mn = st.begin()->fst;
			idx = st.begin()->snd;
			st.erase(st.begin());
			av -= mn;
			ans[idx] = min(n, d-mn);
			n -= ans[idx];
		}
		if(av >= m)
		{
			FOR(i, 0, s)
			{
				if(i > 0) putchar(' ');
				printf("%d", ans[i]);
			}
			puts("");
		}
		else printf("impossible\n");
	}
	return 0;
}