#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 100010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9

int n, m, k;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t = 1;
	while(cin >> n >> m)
	{
		if(n == 0 && m == 0) break;
		int sz[6];
		FOR(i, 0, n) cin >> sz[i];
		vector<pair<int, ii>> vv(m);
		FOR(i, 0, m)
		{
			cin >> vv[i].fst >> vv[i].snd.fst >> vv[i].snd.snd;
			vv[i].fst--;
		}
		vi v(n);
		FOR(i, 0, n) v[i] = i;
		int ans = -1;
		do
		{
			int msg = 0;
			vi cur(6, 1);
			set<ii> s[6];
			int buffer = 0;
			int tmp = 0;
			FOR(i, 0, m)
			{
				int a, l, r;
				a = vv[i].fst;
				l = vv[i].snd.fst;
				r = vv[i].snd.snd;
				if(msg < n && v[msg] == a && l == cur[a])
				{
					cur[a] = r+1;
					if(cur[a] >= sz[a]) msg++;
					while(msg < n && s[v[msg]].size() && s[v[msg]].begin()->fst == cur[v[msg]])
					{
						buffer -= s[v[msg]].begin()->snd - s[v[msg]].begin()->fst + 1;
						cur[v[msg]] = s[v[msg]].begin()->snd + 1;
						s[v[msg]].erase(s[v[msg]].begin());
						if(cur[v[msg]] >= sz[v[msg]]) msg++;
					}
				}
				else
				{
					buffer += r - l + 1;
					tmp = max(tmp, buffer);
					s[a].insert(mp(l, r));
				}
			}
			if(ans == -1 || ans > tmp) ans = tmp;
		} while(next_permutation(v.begin(), v.end()));
		printf("Case %d: %d\n\n", t++, ans);
	}
    return 0;
}
