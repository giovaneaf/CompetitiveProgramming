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
 
const int MN = 10;
const int MS = 500010;
bool possible;
 
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
			int id = s[i] - '0';
			if(tree[cur_node].a[id] == -1)
			{
				tree[cur_node].a[id] = nodes;
				clear();
			}
			else if(tree[tree[cur_node].a[id]].c)
			{
				possible = false;
				break;
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
 
trie tree;
 
bool cmp(const string& s1, const string& s2)
{
	return s1.size() < s2.size();
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		tree.init();
		vector<string> s(n);
		possible = true;
		FOR(i, 0, n)
		{
			cin >> s[i];
		}
		sort(s.begin(), s.end(), cmp);
		FOR(i, 0, n)
		{
			if(possible) tree.add(s[i]);
		}
		printf("%s\n", possible ? "YES" : "NO");
	}
	return 0;
}  