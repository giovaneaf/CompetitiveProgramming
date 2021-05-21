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
	while(cin >> n)
	{
		int ans = INF;
		int a, b;
		FOR(i, 0, n)
		{
			cin >> a >> b;
			ans = min(ans, b/a);
		}
		printf("%d\n", ans);
	}	
	return 0;
}