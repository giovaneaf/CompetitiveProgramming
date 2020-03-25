#include <bits/stdc++.h>

using namespace std;

const int MN = 26;
const int MS = 100010;

struct trie
{
	struct node
	{
		int c;
		int a[MN];
	};
	
	node tree[MS];
	int nodes;

	void clear()
	{
		tree[nodes].c = 0;
		memset(tree[nodes].a, -1, sizeof(tree[nodes].a));
		nodes++;
	}

	void init()
	{
		nodes = 0;
		clear();
	}

	void add(const string& s, int val)
	{
		int cur_node = 0;
		for(int i = 0; i < s.size(); ++i)
		{
			int id = s[i] - 'A';
			if(tree[cur_node].a[id] == -1)
			{
				tree[cur_node].a[id] = nodes;
				clear();
			}
			cur_node = tree[cur_node].a[id];
			tree[cur_node].c += val;			
		}
	}

	int dfs(int cur)
	{
		int ans = abs(tree[cur].c);
		for(int i = 0; i < 26; ++i)
		{
			if(tree[cur].a[i] != -1)
			{
				ans += dfs(tree[cur].a[i]);
			}
		}
		return ans;
	}

};

trie tree;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while(true)
	{
		cin >> n;
		if(n == -1) break;
		string s;
		tree.init();
		int total = 0;
		for(int i = 0; i < n; ++i)
		{
			cin >> s;
			tree.add(s, 1);
			total += s.size();
		}
		for(int i = 0; i < n; ++i)
		{
			cin >> s;
			tree.add(s, -1);
			total += s.size();
		}
		total -= tree.dfs(0);
		cout << (total >> 1) << '\n';
	}
	return 0;
}