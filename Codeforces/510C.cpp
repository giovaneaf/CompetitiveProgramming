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
#define MAXN 1010
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
	while(cin >> n)
	{
		set<int> adj[26];
		bool can = true;
		string s[110];
		FOR(i, 0, n)
		{
			cin >> s[i];
		}
		vi deg(26, 0);
		FOR(i, 0, n)
		{
			FOR(j, i+1, n)
			{
				int len = min(s[i].size(), s[j].size());
				bool equal = true;
				FOR(k, 0, len)
				{
					if(s[i][k] != s[j][k])
					{
						if(adj[s[i][k]-'a'].find(s[j][k]-'a') == adj[s[i][k]-'a'].end())
						{
							adj[s[i][k]-'a'].insert(s[j][k]-'a');
							deg[s[j][k]-'a']++;
						}
						equal = false;
						break;
					}
				}
				if(equal && s[i].size() > s[j].size())
				{
					can = false;
					break;
				}
			}
			if(!can) break;
		}
		if(!can)
		{
			printf("Impossible\n");
		}
		else
		{
			queue<int> q;
			FOR(i, 0, 26)
			{
				if(deg[i] == 0) q.push(i);
			}
			string ans;
			while(q.size())
			{
				int cur = q.front();
				q.pop();
				ans += ('a' + cur);
				for(auto it = adj[cur].begin(); it != adj[cur].end(); ++it)
				{
					deg[*it]--;
					if(deg[*it] == 0) q.push(*it);
				}
			}
			printf("%s\n", ans.size() != 26 ? "Impossible" : ans.c_str());
		}
	}
	return 0;
}
