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
#define MAXM 250010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

ll mod = 1000000007LL;

struct st
{
	int a, l, r;
	bool operator< (const st& s)
	{
		return r < s.r;
	}
};

int T, n, k;
st v[MAXN];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	FOR(t, 0, T)
	{
		int ans = 0;
		multiset<int> s;
		cin >> n;
		FOR(i, 0, n)
		{
			cin >> v[i].a >> v[i].l >> v[i].r;
			if(s.find(v[i].a) == s.end())
			{
				s.insert(v[i].a); ans++;
			}
		}
		sort(v, v+n);
		set<int>::iterator it;
		FOR(i, 0, n)
		{
			it = s.lower_bound(v[i].l);
			if(it == s.end() || *it > v[i].r)
			{
				s.insert(v[i].r); ans++;
			}
			else if(*it == v[i].a)
			{
				it++;
				if(it == s.end() || *it > v[i].r)
				{
					s.insert(v[i].r); ans++;
				}
			}
		}
		printf("Case #%d: %d\n", t+1, ans);
	}
	return 0;
}
