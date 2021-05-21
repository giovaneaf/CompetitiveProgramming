#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
#define LOGMAXN 23
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

const ll mod = 1000000007LL;
int n, m;
string str;
string v[MAXN];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> str)
	{
		cin >> n;
		bool can = false;
		vi freq(26, 0);
		FOR(i, 0, n)
		{			
			cin >> v[i];
			if(v[i][0] == str[(int) str.size()-1])
				can = true;
			freq[v[i][0]-'a']++;
		}
		if(!can)
		{
			printf("?\n");
			continue;
		}
		string ans = "";
		FOR(i, 0, n)
		{
			int nfreq = freq[v[i][(int) v[i].size()-1] - 'a'] - (v[i][0] == v[i][(int) v[i].size()-1] ? 1 : 0);
			if(v[i][0] == str[(int) str.size()-1] && nfreq == 0) 
			{
				printf("%s!\n", v[i].c_str());
				can = false;
				break;
			}
			if(ans == "" && v[i][0] == str[(int) str.size()-1])
			{
				ans = v[i];
			}
		}
		if(can) printf("%s\n", ans.c_str());
	}
	return 0;
}