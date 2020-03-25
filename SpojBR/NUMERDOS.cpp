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
 
void BFS(int cur, vi* adj, vb& seen, vi& ans)
{
	seen[cur] = true;
	queue<int> q;
	q.push(cur);
	while(q.size())
	{
		cur = q.front();
		q.pop();
		for(int u: adj[cur])
		{
			if(!seen[u])
			{
				ans[u] = 1 + ans[cur];
				seen[u] = true;
				q.push(u);
			}
		}
	}
}
 
struct lex_compare {
    bool operator() (const string& a, const string& b) const {
        if(a.substr(1) != b.substr(1)) return a.substr(1) < b.substr(1);
		return a < b;
    }
};
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t = 1;
    while(cin >> n && n)
	{
		string str, name;
		set<string, lex_compare> s;
		map<string, int> mm;
		vi adj[110];
		cin.ignore();
		int idx = 0;
		FOR(i, 0, n)
		{
			getline(cin, str);
			int pos = str.find(',');
			vi cc;
			while(pos != -1)
			{
				name = str.substr(0, pos);
				if(mm.find(name) == mm.end())
				{
					mm[name] = idx++;
				}
				cc.emplace_back(mm[name]);
				s.insert(name);
				str = str.substr(pos+2);
				pos = str.find(',');
			}
			name = str.substr(0);
			name.pop_back();
			if(mm.find(name) == mm.end())
			{
				mm[name] = idx++;
			}
			cc.emplace_back(mm[name]);
			s.insert(name);
			FOR(i, 0, cc.size())
			{
				FOR(j, 1, cc.size())
				{
					int a, b;
					a = cc[i];
					b = cc[j];
					adj[a].emplace_back(b);
					adj[b].emplace_back(a);
				}
			}
		}
		vi ans(idx, INF);
		if(mm.find("P. Erdos") != mm.end())
		{
			int pos = mm["P. Erdos"];
			ans[pos] = 0;
			vb seen(idx, false);
			BFS(pos, adj, seen, ans);
		}
		if(t > 1) putchar('\n');
		printf("Teste %d\n", t++);
		for(auto it = s.begin(); it != s.end(); ++it)
		{
			if(*it == "P. Erdos") continue;
			int pos = mm[*it];
			if(ans[pos] == INF)
				printf("%s: infinito\n", it->c_str());
			else
				printf("%s: %d\n", it->c_str(), ans[pos]);
		}
	}
    return 0;
}