/*
	Aho-Corasick from https://cp-algorithms.com/string/aho_corasick.html
	with the match function (find all ocurrences and print them)
	UVa - 10679 (Solution)
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
#define MAXN 300010
#define LOGMAXN 23
#define MAXM 1000010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define MAXWORDS 1010
 
const ll mod = 1000000007LL;
int n, m;

const int K = 52;

inline int chartoIdx(char ch)
{
	if('a' <= ch && ch <= 'z')
		return ch-'a';
	return ch-'A'+26;
}

struct Vertex {
    int next[K];
	bitset<MAXWORDS> output;
    int p = -1;
    char pch;
    int link = -1;
    int go[K];

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
		output.reset();
    }
};

void add_string(string const& s, int id, vector<Vertex>& t) {
    int v = 0;
    for (char ch : s) {
        int c = chartoIdx(ch);
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
	t[v].output[id] = 1;
}

int go(int v, char ch, vector<Vertex>& t);

int get_link(int v, vector<Vertex>& t) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
		{
            t[v].link = 0;
		}
        else
		{
            t[v].link = go(get_link(t[v].p, t), t[v].pch, t);
			if(t[t[v].link].link == -1)
				get_link(t[v].link, t);
			t[v].output |= t[t[v].link].output;
		}
    }
    return t[v].link;
}

int go(int v, char ch, vector<Vertex>& t) {
    int c = chartoIdx(ch);
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v, t), ch, t);
    }
    return t[v].go[c];
}

bitset<MAXWORDS> ans;

void checkOcc(int v, vector<string>& str, int pos, vector<Vertex>& t)
{
	ans |= t[v].output;
	/*FOR(i, 0, (int) str.size())
	{
		if(t[v].output[i])
		{
			printf("%s found from [%d, %d]\n", str[i].c_str(), pos-((int)str[i].size()-1), pos);
		}
	}*/
}

void checkMatches(string& s, vector<string>& str, vector<Vertex>& t)
{
	int v = 0;
	int c;
	FOR(i, 0, (int) s.size())
	{
		c = chartoIdx(s[i]);
		if(t[v].link == -1)
			get_link(v, t);
		checkOcc(v, str, i, t);
		while(v > 0 && t[v].next[c] == -1)
		{
			v = t[v].link;
		}
		if(t[v].next[c] > -1)
			v = t[v].next[c];
	}
	if(t[v].link == -1)
		get_link(v, t);
	checkOcc(v, str, (int) s.size(), t);
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		string match;
		cin >> match;
		vector<Vertex> t(1);
		cin >> n;
		string s;
		vector<string> str(n);
		FOR(i, 0, n)
		{
			cin >> str[i];
			add_string(str[i], i, t);
		}
		ans.reset();
		checkMatches(match, str, t);
		FOR(i, 0, n)
		{
			printf("%c\n", ans[i] ? 'y' : 'n');
		}
	}
	return 0;
}