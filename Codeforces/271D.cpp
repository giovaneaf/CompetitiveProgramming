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

const int MN = 26;
const int MS = 2250010;
int ans = 0;

struct node
{
	bool c;
	int a[MN];
};

node tree[MS];
bool bad[MN];

struct trie
{
	int nodes;

	void clear()
	{
		tree[nodes].c = false;
		memset(tree[nodes].a, -1, sizeof(tree[nodes].a));
		nodes++;
	}

	void init()
	{
		nodes = 0;
		clear();
	}

	void add(const string& s, int k)
	{
		int cur_node = 0;
		int bads = 0;
		for(int i = 0; i < s.size(); ++i)
		{
			int id = s[i] - 'a';
			if(bad[id]) bads++;
			if(bads > k) break;
			if(tree[cur_node].a[id] == -1)
			{
				tree[cur_node].a[id] = nodes;
				clear();
			}
			cur_node = tree[cur_node].a[id];
			if(!tree[cur_node].c)
			{
				ans++;
				tree[cur_node].c = true;			
			}
		}
	}

	void dfs(int cur, string s, int root)
	{
		if(tree[cur].c && cur != root)
		{
			printf("%s\n", s.c_str());
		}
		for(int i = 0; i < MN; ++i)
		{
			if(tree[cur].a[i] != -1)
			{
				char ch = ('a' + i);
				dfs(tree[cur].a[i], s + ch, root);
			}
		}
	}
	
	void search(string s)
	{
		int cur_node = 0;
		for(int i = 0; i < s.size(); ++i)
		{
			int id = s[i] - 'a';
			if(tree[cur_node].a[id] == -1)
			{
				return ;
			}
			cur_node = tree[cur_node].a[id];
		}
		dfs(cur_node, s, cur_node);
	}
};

trie triet;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s;
	while(cin >> s)
	{
		triet.init();
		n = s.size();
		string str;
		cin >> str;
		FOR(i, 0, 26)
		{
			bad[i] = (str[i] != '1');
		}
		cin >> k;
		ans = 0;
		for(int i = 0; i < n; ++i)
		{
			str = s.substr(i, n);
			triet.add(str, k);
		}
		printf("%d\n", ans);
	}
	return 0;
} 