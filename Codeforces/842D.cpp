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
const int MS = 6000010;
int bits = 19;
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
		tree[nodes].sz = 0;
		memset(tree[nodes].a, -1, sizeof(tree[nodes].a));
		nodes++;
	}

	void init()
	{
		nodes = 0;
		clear();
	}

	void add(int v)
	{
		int cur_node = 0;
		for(int i = bits; i >= 0; --i)
		{
			int id = (v&(1<<i)) > 0 ? 1 : 0;
			if(tree[cur_node].a[id] == -1)
			{
				tree[cur_node].a[id] = nodes;
				clear();
			}
			/*else
			{
				tree[tree[cur_node].a[id]].sz++;
			}*/
			cur_node = tree[cur_node].a[id];
		}
		if(tree[cur_node].sz == 0)
		{
			cur_node = 0;
			for(int i = bits; i >= 0; --i)
			{
				int id = (v&(1<<i)) > 0 ? 1 : 0;
				tree[tree[cur_node].a[id]].sz++;
				cur_node = tree[cur_node].a[id];
			}
		}
	}
	
	void remove(int v)
	{
		int cur_node = 0;
		for(int i = bits; i >= 0; --i)
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
	
	int query(int v)
	{
		int cur_node = 0;
		int ans = 0;
		for(int i = bits; i >= 0; --i)
		{
			int id = (v&(1LL<<i)) > 0 ? 1 : 0;
			if(tree[cur_node].a[id] == -1) break;
			if(tree[tree[cur_node].a[id]].sz < (1 << i))
			{
				cur_node = tree[cur_node].a[id];
			}
			else if(tree[cur_node].a[id^1] == -1) 
			{
				ans = ans | (1 << i);
				break;
			}
			else
			{
				ans = ans | (1 << i);
				cur_node = tree[cur_node].a[id^1];
			}
		}
		return ans;
	}
	
};

trie triet;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m)
	{
		triet.init();
		int v;
		FOR(i, 0, n)
		{
			cin >> v;
			triet.add(v);
		}
		int xr = 0;
		FOR(i, 0, m)
		{
			cin >> v;
			xr ^= v;
			printf("%d\n", triet.query(xr));
		}
	}
	return 0;
} 