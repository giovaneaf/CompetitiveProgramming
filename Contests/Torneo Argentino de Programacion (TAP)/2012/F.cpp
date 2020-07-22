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
#define MAXN 10010
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

int n;
string s[15];
int pos[15];
vb done;

bool solve(int p, int dad)
{
	if(s[p][pos[p]] == '1')
	{
		s[1] += (p + '0');
		pos[p]++;
		if(pos[p] == (int) s[p].size())
			done[p] = true;
		return false;
	}
	if(dad + '0' == s[p][pos[p]])
	{
		pos[p]++;
		if(pos[p] == (int) s[p].size())
			done[p] = true;
		return true;
	}
	if(solve(s[p][pos[p]]-'0', p))
	{
		pos[p]++;
		if(pos[p] == (int) s[p].size())
			done[p] = true;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		if(n == -1) break;
		memset(pos, 0, sizeof(pos));
		done.assign(15, false);
		FOR(i, 2, n+1) cin >> s[i];
		int p = 2;
		while(p > -1)
		{
			p = -1;
			FOR(i, 2, n+1)
			{
				if(done[i]) continue;
				p = i;
				if(s[i][pos[i]] == '1') break;
			}
			if(p > -1)
				solve(p, -1);
		}
		printf("%s\n", s[1].c_str());
		FOR(i, 0, 15) s[i].clear();
	}
	return 0;
}