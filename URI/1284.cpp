#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, int> ip;
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
#define MAXN 1000010
#define LOGMAXN 23
#define MAXM 1000010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
 
const ll mod = 1000000007LL;
int n;

struct node
{
	bool word;
	int nChild;
	vi child;
	void clear()
	{
		word = false;
		nChild = 0;
		child.assign(26, -1);
	}
};

vector<node> trie(MAXN);
int a;

void insert(string& s)
{
	int cur = 0;
	for(char& c : s)
	{
		int mp = c-'a';	
		if(trie[cur].child[mp] == -1)
		{
			trie[cur].nChild++;
			trie[cur].child[mp] = a;
			trie[a].clear();
			a++;
		}
		cur = trie[cur].child[mp];
	}
	trie[cur].word = true;
}

int nTypes(string& s)
{
	int type = 0;
	int cur = 0;
	for(char& c : s)
	{
		if(trie[cur].word || trie[cur].nChild > 1 || cur == 0)
		{
			type++;
		}
		cur = trie[cur].child[c-'a'];
	}
	return type;
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		vector<string> v(n);
		trie[0].clear();
		a = 1;
		FOR(i, 0, n)
		{
			cin >> v[i];
			insert(v[i]);
		}
		int types = 0;
		FOR(i, 0, n)
		{
			types += nTypes(v[i]);
		}
		printf("%.2f\n", (double) types/n);
	}
	return 0;
}