#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL
 
#define ITER 1000000
#define DEBUG 0
 
int s, l, n;
string toString[210];
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> s >> l >> n)
	{
		string ss, sss;
		map<string, int> mm;
		set<string> mySet;
		FOR(i, 0, s)
		{
			cin >> ss;
			mySet.insert(ss);
		}
		int cnt = 0;
		for(auto it = mySet.begin(); it != mySet.end(); ++it)
		{
			mm[*it] = cnt;
			toString[cnt++] = *it;
		}
		vector<vb> adj(s+2, vb(s+2, false));
		FOR(i, 0, l)
		{
			cin >> ss >> sss;
			int a = mm[ss], b = mm[sss];
			adj[a][b] = adj[b][a] = true;
		}
		vi v(n);
		getline(cin, ss);
		getline(cin, ss);
		stringstream strstream(ss);
		int pp = 0;
		while(strstream >> ss)
		{
			v[pp++] = mm[ss];
		}
		vb active(n, true);
		vi pos(s, 0);
		string ans = "";
		FOR(i, 0, n)
		{
			if(i > 0) ans += ' ';
			FOR(j, 0, s)
			{
				while(pos[j] < n && !active[pos[j]]) pos[j]++;
				while(pos[j] < n && j != v[pos[j]] && adj[j][v[pos[j]]])
				{
					pos[j]++;
					while(pos[j] < n && !active[pos[j]]) pos[j]++;
				}
				if(pos[j] < n && j == v[pos[j]])
				{
					active[pos[j]] = false;
					ans += toString[j];
					break;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}