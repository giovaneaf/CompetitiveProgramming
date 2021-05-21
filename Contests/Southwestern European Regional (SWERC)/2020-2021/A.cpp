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
#define MAXN 10010
#define LOGMAXN 23
#define MAXM 1010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define MAXWORDS 1010
 
ll mod = 1000000007LL;
int n, k;

struct Thing
{
	string name;
	int freq, last;
	Thing(string name, int freq, int last) : name(name), freq(freq), last(last) {}
	bool operator< (Thing& t)
	{
		if(freq == t.freq)
			return last < t.last;
		return freq < t.freq;
	}
};

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> k)
	{
		vector<Thing> v;
		map<string, int> mm;
		int cnt = 0;
		string s;
		getline(cin, s);
		FOR(i, 0, 3*n)
		{
			getline(cin, s);
			if(mm.find(s) == mm.end())
			{
				mm[s] = cnt++;
				v.push_back(Thing(s, 0, i));
			}
			int id = mm[s];
			v[id].freq++;
			v[id].last = i;
		}
		sort(v.begin(), v.end());
		FOR(i, 0, min(k, cnt))
		{
			printf("%s\n", v[cnt-1-i].name.c_str());
		}
	}	
	return 0;
}