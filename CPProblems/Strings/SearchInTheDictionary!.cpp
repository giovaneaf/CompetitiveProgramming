/*
https://www.spoj.com/problems/DICT/
You can use Trie (PATRICIA) data structure that is a data structure very useful to store strings.
*/

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
 
int n, m, q;
 
const int MN = 26;
const int MS = 500010;
bool found;
 
struct trie
{
	struct node
	{
		bool c;
		int a[MN];
	};
	
	node tree[MS];
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
 
	void add(const string& s)
	{
		int cur_node = 0;
		for(int i = 0; i < s.size(); ++i)
		{
			int id = s[i] - 'a';
			if(tree[cur_node].a[id] == -1)
			{
				tree[cur_node].a[id] = nodes;
				clear();
			}
			cur_node = tree[cur_node].a[id];
		}
		tree[cur_node].c = true;			
	}
 
	void dfs(int cur, string s, int root)
	{
		if(tree[cur].c && cur != root)
		{
			printf("%s\n", s.c_str());
			found = true;
		}
		for(int i = 0; i < 26; ++i)
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
 
trie tree;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	tree.init();
	string s;
	FOR(i, 0, n)
	{
		cin >> s;
		tree.add(s);
	}
	cin >> q;
	FOR(i, 0, q)
	{
		printf("Case #%d:\n", i+1);
		cin >> s;
		found = false;
		tree.search(s);
		if(!found)
		{
			printf("No match.\n");
		}
	}
	return 0;
}  
