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
#define MAXN 100010
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

string s;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> s)
	{
		string ans;
		int n = (int) s.size()/3;
		map<string, int> words;
		words[s.substr(0, n)]++;
		words[s.substr(n, n)]++;
		words[s.substr(2*n, n)]++;
		for(auto it = words.begin(); it != words.end(); ++it)
		{
			if(it->snd > 1)
			{
				ans = it->fst;
				break;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}