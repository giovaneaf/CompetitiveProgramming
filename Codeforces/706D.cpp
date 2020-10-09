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
const int MS = 6000000;
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

	void add(int v)
	{
		int cur_node = 0;
		for(int i = 29; i >= 0; --i)
		{
			int id = (v&(1<<i)) > 0 ? 1 : 0;
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
		for(int i = 29; i >= 0; --i)
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
		for(int i = 29; i >= 0; --i)
		{
			int id = (v&(1<<i)) > 0 ? 0 : 1;
			if(tree[cur_node].a[id] != -1)
			{
				cur_node = tree[cur_node].a[id];
				ans += (id << i);
			}
			else if(tree[cur_node].a[id^1] != -1)
			{
				cur_node = tree[cur_node].a[id^1];
				ans += ((id^1) << i);
			}
		}
		return ans;
	}
	
};

trie triet;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	triet.init();
	cin >> q;
	char ch;
	int v;
	FOR(i, 0, q)
	{
		cin >> ch >> v;
		if(ch == '+')
		{
			triet.add(v);
		}
		else if(ch == '-')
		{
			triet.remove(v);
		}
		else
		{
			int ans = triet.query(v);
			printf("%d\n", max(v, ans^v));
		}
	}
	return 0;
} 