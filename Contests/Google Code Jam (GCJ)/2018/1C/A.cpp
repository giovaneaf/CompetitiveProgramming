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

int T, n, l;
string ans;
set<string> s;

bool can(int pos, vector<vb>& av)
{
	if(pos == l)
	{
		return s.find(ans) == s.end();
	}
	FOR(i, 0, 26)
	{
		if(av[pos][i])
		{
			ans[pos] = i+'A';
			if(can(pos+1, av))
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	FOR(t, 1, T+1)
	{
		cin >> n >> l;
		vector<vb> av(30, vb(30, false));
		FOR(i, 0, n)
		{
			cin >> ans;
			s.insert(ans);
			FOR(j, 0, l)
			{
				av[j][ans[j]-'A'] = true;
			}
		}
		ans.resize(l);
		if(!can(0, av))
			ans = "-";
		printf("Case #%d: %s\n", t, ans.c_str());
		s.clear();
	}
	return 0;
}

