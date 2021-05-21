/*
	Trie implementation (dictionary) with the following operations:
	add() 			- Add the word s to dictionary with word ID i 
					  time complexity is (O(|s|*log(|a|)))
	exists()		- Check if given word s is in dictionary 
					  time complexity is linear in word length (O(|s|*log(|a|))
	autoComplete()	- Find all dictionary words that matches the given prefix string
					  time complexity is O(|S|*|a|)
	where
	|s| is the size of the word
	|a| is the size of the alphabet
	|S| is the sum of length of all words dictionary
	The space complexity of the trie is O(|S|*|a|).
*/

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
#define MAXN 100010
#define LOGMAXN 23
#define MAXM 1000010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define MAXWORDS 1010
 
ll mod = 1000000007LL;

const int MS = 100010;		// maximum number of nodes (words) + 1 (root)

struct Trie
{
	struct node
	{
		int wid;	// value of the word ID
		map<char, int> c;
	};
	
	node tree[MS];
	int nodes;
	
	Trie()
	{
		clear();
	}
	
	// clear current index of nodes value
	void clearNode()
	{
		tree[nodes].wid = -1;
		nodes++;
	}
	
	void add(string& str, int wid)
	{
		int cur = 0;
		for(char& ch : str)
		{
			if((int) tree[cur].c.count(ch) == 0)
			{
				tree[cur].c[ch] = nodes;
				clearNode();
			}
			cur = tree[cur].c[ch];
		}
		tree[cur].wid = wid;
	}
	
	bool exists(string& str)
	{
		int cur = 0;
		for(char& ch : str)
		{
			if((int) tree[cur].c.count(ch) == 0)
			{
				return false;
			}
			cur = tree[cur].c[ch];
		}
		return tree[cur].wid > -1;
	}
	
	void DFS(int cur, vi& sugestions)
	{
		// If word is complete then add it to suggestions
		if(tree[cur].wid > -1)
			sugestions.push_back(tree[cur].wid);
		// traverse all remaining childs
		for(auto it = tree[cur].c.begin(); it != tree[cur].c.end(); ++it)
		{
			DFS(it->snd, sugestions);
		}
	}
	
	vi autoComplete(string& str)
	{
		int cur = 0;
		for(char& ch : str)
		{
			if((int) tree[cur].c.count(ch) == 0)
			{
				return vi();
			}
			cur = tree[cur].c[ch];
		}
		vi sugestions;
		// DFS for all subtree since all have the same prefix from auto complete
		DFS(cur, sugestions);
		return sugestions;
	}
	
	void clear()
	{
		nodes = 0;
		clearNode();
	}
	
};

Trie trie;

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;					// read the number of words in dictionary
	vector<string> v(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> v[i];				// read the n dictionary words
		trie.add(v[i], i);			// add the word to the trie
	}
	string s;
	while(cin >> s)				// read until end of input (query strings)
	{
		// check if word exists in dictionary
		printf("string %s %s in dictionary\n", s.c_str(), trie.exists(s) ? "is" : "is not");
		// find all auto complete words
		vi autoComplete = trie.autoComplete(s);
		if((int) autoComplete.size() == 0)
			printf("Dictionary has no autocomplete words\n");
		else
		{
			printf("Found the following autocomplete words:\n");
			int cnt = 0;
			for(int& id : autoComplete)
			{
				cnt++;
				printf("%d: %s\n", cnt, v[id].c_str());
			}
		}
	}
}