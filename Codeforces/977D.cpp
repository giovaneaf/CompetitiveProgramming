#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define mt make_tuple
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define rREP(i, a, n) for(int i = a; i >= n; --i)


int main()
{
	unordered_map<ll, int> m;
	int n;
	cin >> n;
	vector<ll> v(n);
	REP(i, 0, n)
	{
		cin >> v[i];
		m[v[i]] = i;
	}
	vector<vi> adj(n);
	vector<int> inDeg;
	inDeg.assign(n, 0);
	REP(i, 0, n)
	{
		if(m.find(2*v[i]) != m.end())
		{
			int tmp = m[2*v[i]];
			adj[i].push_back(tmp);
			inDeg[tmp]++;
		}
		if(v[i]%3 == 0)
		{
			if(m.find(v[i]/3) != m.end())
			{
				int tmp = m[v[i]/3];
				adj[i].push_back(tmp);
				inDeg[tmp]++;
			}
		}
	}
	queue<int> q;
	bool possible = true;
	for(int i = 0; i < n; ++i)
	{
		if(inDeg[i] == 0)
		{
			q.push(i);
			break;
		}
	}
	int cnt = 0;
	while(q.size())
	{
		int top = q.front();
		q.pop();
		for(int i = 0; i < adj[top].size(); ++i)
		{
			int u = adj[top][i];
			if(--inDeg[u] == 0)
			{
				q.push(u);
			}
		}
		if(cnt > 0)
			putchar(' ');
		printf("%lld", v[top]);
		cnt++;
	}
	putchar('\n');
	return 0;
}
