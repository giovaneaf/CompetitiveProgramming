#include <bits/stdc++.h>

#define INF 2000000000

using namespace std;

int ST[400010];
int lazy[400010];
vector<tuple<int, int, int>> shop;

void init(int cur, int l, int r)
{
	if(l > r) return ;
	ST[cur] = INF;
	lazy[cur] = INF;
	if(l == r) return ;
	int mid = (l+r)/2;
	init(2*cur+1, l, mid);
	init(2*cur+2, mid+1, r);
}

void update(int cur, int l, int r, int ql, int qr, int cost)
{
	int left = 2*cur+1;
	int right = 2*cur+2;
	if(lazy[cur] != INF)
	{
		ST[cur] = min(ST[cur], lazy[cur]);
		if(l != r)
		{
			lazy[left] = min(lazy[cur], lazy[left]);
			lazy[right] = min(lazy[cur], lazy[right]);
		}
		lazy[cur] = INF;
	}
	if(ql > r || qr < l) return ;
	if(l >= ql and r <= qr)
	{
		lazy[cur] = cost;
		return ;
	}
	int mid = (l+r)/2;
	update(left, l, mid, ql, qr, cost);
	update(right, mid+1, r, ql, qr, cost);
}

int query(int cur, int l, int r, int target)
{
	int left = 2*cur+1;
	int right = 2*cur+2;
	if(lazy[cur] != INF)
	{
		ST[cur] = min(ST[cur], lazy[cur]);
		if(l != r)
		{
			lazy[left] = min(lazy[cur], lazy[left]);
			lazy[right] = min(lazy[cur], lazy[right]);
		}
		lazy[cur] = INF;
	}
	if(l == r)
	{
		return ST[cur];
	}
	int mid = (l+r)/2;
	if(target <= mid)
	{
		return query(left, l, mid, target);
	}
	else
	{
		return query(right, mid+1, r, target);
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	init(0, 0, n-1);
	vector<int> E(n+1);
	E[0] = 0;
	for(int i = 0; i < n; ++i)
	{
		cin >> E[i+1];
		E[i+1] += E[i];
	}
	for(int i = 0; i < m; ++i)
	{
		int l, s, c;
		cin >> l >> s >> c;
		if(s >= E[l] - (l-1 >= 0 ? E[l-1] : 0))
			shop.push_back(make_tuple(--l, s, c));
	}
	sort(shop.begin(), shop.end());
	bool possible = true;
	for(int i = 0; i < shop.size(); ++i)
	{
		int level = get<0>(shop[i]);
		int stamina = get<1>(shop[i]);
		int cost = get<2>(shop[i]);
		if(level == 0)
		{
			auto it = upper_bound(E.begin(), E.end(), stamina);
			int idx = (int) (it - E.begin());
			if(idx <= level+1)
			{
				possible = false;
				break;
			}
			update(0, 0, n-1, level, idx-2, cost);
		}
		else
		{
			auto it = upper_bound(E.begin(), E.end(), stamina + E[level]);
			int idx = (int) (it - E.begin());
			if(idx <= level+1)
			{
				possible = false;
				break;
			}
			int prevCost = query(0, 0, n-1, level-1);
			if(prevCost == INF)
			{
				possible = false;
				break;
			}
			update(0, 0, n-1, level, idx-2, cost+prevCost);
		}
	}
	int ans = query(0, 0, n-1, n-1);
	if(!possible || ans == INF)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", ans);
	}
	return 0;
}