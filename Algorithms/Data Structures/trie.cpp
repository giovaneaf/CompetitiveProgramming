#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define MAXN 300010
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9

const int MN = 26;
const int MS = 100010;
int ans;

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
		int subtract = 0;
		for(int i = 0; i < MN; ++i)
		{
			if(tree[cur].a[i] != -1)
			{
				subtract += dfs(tree[cur].a[i]);
			}
		}
		if(tree[cur].c-subtract >= 2)
		{
			ans += 2;
			subtract += 2;
		}
		return subtract;
	}

};

int n, m;

trie tree;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	FOR(t, 0, T)
	{
		printf("Case #%d: ", t+1);
		int n;
		cin >> n;
		tree.init();
		string s;
		FOR(i, 0, n)
		{
			cin >> s;
			reverse(s.begin(), s.end());
			tree.add(s, 1);
		}
		ans = 0;
		tree.dfs(0);
		printf("%d\n", ans);
	}
}