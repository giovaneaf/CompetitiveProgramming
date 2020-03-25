#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef long long ll;

int n, m;

int mx, nd;

void dfs(int cur, vi* adj, vector<int>& len, vector<bool>& seen)
{
	stack<ii> s;
	s.push({cur, 0});
	while(s.size())
	{
		cur = s.top().first;
		int depth = s.top().second;
		s.pop();
		seen[cur] = true;
		if(depth > mx)
		{
			mx = depth;
			nd = cur;
		}
		len[cur] = max(len[cur], depth);
		for(int i = 0; i < adj[cur].size(); ++i)
		{
			int u = adj[cur][i];
			if(!seen[u])
			{
			   s.push({u, depth+1});
			}
		}
	}
}

void precompute(int n, vi* adj, vector<int>& len)
{
	vector<bool> seen(n, false);
	mx = nd = 0;
    dfs(0, adj, len, seen);
	int u = nd;
	fill(seen.begin(), seen.end(), false);
	mx = nd = 0;
	dfs(u, adj, len, seen);
	fill(seen.begin(), seen.end(), false);
	dfs(nd, adj, len, seen);
}

int main()
{
    while(cin >> n >> m)
    {
        vi g1[n];
        for(int i = 0; i < n-1; ++i)
        {
            int a, b;
            cin >> a >> b;
            a--, b--;
            g1[a].push_back(b);
            g1[b].push_back(a);
        }
        vi g2[m];
        for(int i = 0; i < m-1; ++i)
        {
            int a, b;
            cin >> a >> b;
            a--, b--;
            g2[a].push_back(b);
            g2[b].push_back(a);
        }
        vector<int> length1(n, -1LL);
        precompute(n, g1, length1);
        vector<int> length2(m, -1LL);
        precompute(m, g2, length2);
        sort(length1.begin(), length1.end());
        int diameter = max(length1[n-1], *max_element(length2.begin(), length2.end()));
        vector<ll> acc(n+1);
        acc[0] = 0LL;
        for(int i = 0; i < n; ++i)
            acc[i+1] = acc[i] + length1[i];
        ll ans = 0LL;
		vector<ll> dp(m+1, -1LL);
        for(int i = 0; i < m; ++i)
        {
			if(dp[length2[i]] != -1LL)
			{
				ans += dp[length2[i]];
				continue;
			}
			ll tmp = 0LL;
            if(diameter <= length1[0]+length2[i]+1)
            {
                tmp = (acc[n] - acc[0]) + (ll) n*(length2[i]+1);
            }
            else
            {
				ll val = diameter - length2[i]-1;
				auto it = lower_bound(length1.begin(), length1.end(), val);
				int idx = distance(length1.begin(), it);
				tmp += idx*diameter;
                tmp = ((ll) idx * diameter) + (acc[n] - acc[idx]) + (ll) (n-idx)*(length2[i]+1LL);
            }
			ans += tmp;
			dp[length2[i]] = tmp;
        }
        printf("%.3f\n", (double) ans/(n*m));
    }
    return 0;
}

