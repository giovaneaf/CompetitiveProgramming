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
#define LOGMAXN 21
#define MAXM 250010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

struct st
{
	int s, p, id;
	bool operator< (const st& x) const
	{
		if(s == x.s)
			if(p == x.p) return id < x.id;
			else return p > x.p;
		return s < x.s;
	}
};

ll mod = 1000000007LL;
int n, m;
st v[MAXN];
bool inSet[MAXN];
int a, b;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m)
	{
		set<st> s;
		FOR(i, 0, n)
		{
			v[i] = {0, 0, i};
			inSet[i] = false;
		}
		FOR(i, 0, m)
		{
			cin >> a >> b;
			a--;
			v[a].s++; v[a].p += b;
			if(a == 0)
			{
				while(s.size())
				{
					auto it = s.begin();
					int id = it->id;
					if(v[id].s > v[a].s || (v[id].s == v[a].s && v[id].p < v[a].p))
					{
						if(v[id].s != it->s)
						{
							s.erase(it);
							s.insert(v[id]);
							continue;
						}
						break;
					}
					inSet[it->id] = false;
					s.erase(it);
				}
			}
			else
			{
				if(!inSet[a])
				{
					if(v[a].s > v[0].s || (v[a].s == v[0].s && v[a].p < v[0].p))
					{
						inSet[a] = true;
						s.insert(v[a]);
					}
				}
			}
			printf("%d\n", (int) s.size()+1);
		}
	}
	return 0;
}
