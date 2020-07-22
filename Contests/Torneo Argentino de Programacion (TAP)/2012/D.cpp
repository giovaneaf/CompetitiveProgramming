#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, bool> ib;
 
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define all(v) v.begin(), v.end()
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 1010
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

int n;

const int MN = 26;
const int MS = 100010;

struct trie
{
	int nodes;
	
	struct node
	{
		int c;
		int a[MN];
	};

	node tree[MS];

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
		FOR(i, 0, 26)
		{
			if(tree[cur].a[i] != -1)
			{
				ans += dfs(tree[cur].a[i]);
			}
		}
		return ans;
	}

};

trie Trie;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		if(n == -1) break;
		int ans = 0;
		string s;
		Trie.init();
		FOR(i, 0, n)
		{
			cin >> s;
			ans += (int) s.size();
			Trie.add(s, 1);
		}
		FOR(i, 0, n)
		{
			cin >> s;
			ans += (int) s.size();
			Trie.add(s, -1);
		}
		ans -= Trie.dfs(0);
		printf("%d\n", ans >> 1);
	}
	return 0;
}