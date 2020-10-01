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

int n;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		string s;
		getline(cin, s);
		set<string> words;
		bool assumption;
		int ans = -1;
		FOR(i, 0, n)
		{
			getline(cin, s);
			stringstream ss(s);
			assumption = true;
			while(ss >> s)
			{
				if(s == "->")
				{
					assumption = false;
				}
				else if(assumption)
				{
					if(ans == -1 && words.find(s) == words.end())
					{
						ans = i+1;
					}
				}
				else
				{
					words.insert(s);
				}
			}
		}
		if(ans == -1) printf("correct\n");
		else printf("%d\n", ans);
	}
	return 0;
}
