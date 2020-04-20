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
int n[3];
int x, sz;
 
inline bool hasAll(multiset<int>* s)
{
	return (int) s[0].size() > 0 && (int) s[1].size() > 0 && (int) s[2].size() > 0;
}
 
inline int getOther(int a, int b)
{
	if(a > b) swap(a, b);
	if(a == 0 && b == 1) return 2;
	if(a == 0 && b == 2) return 1;
	return 0;
}
 
inline ll compute(int a, int b, int c)
{
	return (ll) ((ll) a-b)*((ll) a-b) + ((ll) a-c)*((ll) a-c) + ((ll) c-b)*((ll) c-b);
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	while(T--)
	{
		FOR(i, 0, 3) cin >> n[i];
		vii v(n[0]+n[1]+n[2]);
		sz = 0;
		FOR(i, 0, 3)
		{
			FOR(j, 0, n[i])
			{
				cin >> x;
				v[sz++] = mp(x, i);
			}
		}
		sort(v.begin(), v.end());
		int lp, rp, other, mid;
		lp = rp = 0;
		multiset<int> s[3];
		ll ans = INFLL;
		while(lp < sz || rp < sz)
		{
			while(rp < sz && !hasAll(s))
			{
				s[v[rp].snd].insert(v[rp].fst);
				rp++;
			}
			do
			{
				rp--;
				if(hasAll(s))
				{
					other = getOther(v[lp].snd, v[rp].snd);
					mid = (v[lp].fst + v[rp].fst + 1)/2;
					auto it = s[other].lower_bound(mid);
					if(it != s[other].end())
					{
						ans = min(ans, compute(v[lp].fst, v[rp].fst, *it));
					}
					if(it != s[other].begin())
					{
						it--;
						ans = min(ans, compute(v[lp].fst, v[rp].fst, *it));
					}
				}
				if(lp < sz)
				{
					s[v[lp].snd].erase(s[v[lp].snd].find(v[lp].fst));
					lp++;
				}
				rp++;
			} while(lp < rp && hasAll(s));
		}
		printf("%lld\n", ans);
	}
	return 0;
}