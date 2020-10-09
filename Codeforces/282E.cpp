#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
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

int n, m, q, k;

const int MN = 2;
const int MS = 4000010;
int ans = 0;

struct node
{
	int sz;
	int a[MN];
};

node tree[MS];

struct trie
{
	int nodes;

	void clear()
	{
		//tree[nodes].c = false;
		tree[nodes].sz = 1;
		memset(tree[nodes].a, -1, sizeof(tree[nodes].a));
		nodes++;
	}

	void init()
	{
		nodes = 0;
		clear();
	}

	void add(long long v)
	{
		int cur_node = 0;
		for(int i = 39; i >= 0; --i)
		{
			int id = (v&(1LL<<i)) > 0 ? 1 : 0;
			if(tree[cur_node].a[id] == -1)
			{
				tree[cur_node].a[id] = nodes;
				clear();
			}
			else
			{
				tree[tree[cur_node].a[id]].sz++;
			}
			cur_node = tree[cur_node].a[id];
		}
	}
	
	void remove(int v)
	{
		int cur_node = 0;
		for(int i = 39; i >= 0; --i)
		{
			int id = (v&(1<<i)) > 0 ? 1 : 0;
			if(tree[tree[cur_node].a[id]].sz < 2)
			{
				tree[cur_node].a[id] = -1;
				break;
			}
			else
			{
				tree[tree[cur_node].a[id]].sz--;
			}
			cur_node = tree[cur_node].a[id];
		}
	}
	
	ll query(ll v)
	{
		int cur_node = 0;
		ll ans = 0LL;
		for(int i = 39; i >= 0; --i)
		{
			int id = (v&(1LL<<i)) > 0 ? 0 : 1;
			if(tree[cur_node].a[id] != -1)
			{
				cur_node = tree[cur_node].a[id];
				ans += ((ll) id << i);
			}
			else if(tree[cur_node].a[id^1] != -1)
			{
				cur_node = tree[cur_node].a[id^1];
				ans += ((ll) (id^1) << i);
			}
		}
		return ans;
	}
	
};

trie triet;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		triet.init();
		ll v[100010];
		ll xr = 0;
		FOR(i, 0, n)
		{
			cin >> v[i];
			xr ^= v[i];
		}
		ll ans = xr;
		ll rxr = 0LL;
		RFOR(i, n-1, 0)
		{
			triet.add(rxr);
			ans = max(ans, triet.query(xr)^xr);
			ans = max(ans, rxr);
			rxr ^= v[i];
			xr ^= v[i];
		}
		triet.add(rxr);
		ans = max(ans, triet.query(xr)^xr);
		ans = max(ans, rxr);
		printf("%lld\n", ans);
	}
	return 0;
} 