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
#define MAXN 10010
#define LOGMAXN 21
#define MAXM 250010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

struct ped
{
	int a, b, id;
	bool operator< (const ped& p)
	{
		if(a == p.a) return b < p.b;
		return a < p.a;
	}
};

ll mod = 1000000007LL;
int n, m;
ped v[MAXN];
int ans[MAXN];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m)
	{
		set<int> s[MAXN];
		FOR(i, 0, n)
		{
			cin >> v[i].a >> v[i].b;
			if(v[i].a > v[i].b) swap(v[i].a, v[i].b);
			v[i].id = i+1;
		}
		int x;
		FOR(j, 0, m)
		{
			cin >> x;
			s[x].insert(j);
		}
		if(m > n)
		{
			printf("impossible\n");
			continue;
		}
		sort(v, v+n);
		int cnt = 0;
		FOR(i, 0, n)
		{
			x = v[i].a;
			if(v[i].a == v[i].b && (int) s[x].size() > 0)
			{
				ans[*s[x].begin()] = v[i].id;
				cnt++;
				s[x].erase(s[x].begin());
			}
		}
		FOR(i, 0, n)
		{
			if(v[i].a == v[i].b) continue;
			if((int) s[v[i].a].size() > 0)
			{
				x = v[i].a;
				ans[*s[x].begin()] = v[i].id;
				cnt++;
				s[x].erase(s[x].begin());
			}
			else if((int) s[v[i].b].size() > 0)
			{
				x = v[i].b;
				ans[*s[x].begin()] = v[i].id;
				cnt++;
				s[x].erase(s[x].begin());
			}
		}
		if(cnt < m) printf("impossible\n");
		else FOR(i, 0, m) printf("%d\n", ans[i]);
	}
	return 0;
}
