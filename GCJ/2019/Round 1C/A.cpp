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
#define MOD 1000000007

int T;
int n;
string v[MAXN];
int len[MAXN];
int cur[MAXN];

inline char winner(char a, char b)
{
	if(a == 'R')
		return (b == 'P' ? b : a);
	else if(a == 'P')
		return (b == 'S' ? b : a);
	else
		return (b == 'R' ? b : a);
}

inline char winner(char a)
{
	if(a == 'R')
		return 'P';
	else if(a == 'P')
		return 'S';
	else
		return 'R';
}

inline char looser(char a)
{
	if(a == 'R')
		return 'S';
	else if(a == 'P')
		return 'R';
	else
		return 'P';
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	FOR(t, 1, T+1)
	{
		cin >> n;
		FOR(i, 0, n)
		{
			cin >> v[i];
			len[i] = (int) v[i].size();
			cur[i] = 0;
		}
		bool can = true;
		int sz = n;
		vb on(n, true);
		string ans = "";
		char w, l;
		char c1, c2;
		while(sz > 0)
		{
			set<char> s;
			FOR(i, 0, n)
			{
				if(on[i])
				{
					s.insert(v[i][cur[i]]);
				}
			}
			if((int) s.size() > 2)
			{
				ans = "IMPOSSIBLE";
				break;
			}
			else if((int) s.size() == 2)
			{
				auto it = s.begin();
				c1 = *it; it++; c2 = *it;
				w = winner(c1, c2);
				l = looser(w);
			}
			else
			{
				auto it = s.begin();
				c1 = *it;
				w = winner(c1);
				l = looser(w);
			}
			ans += w;
			FOR(i, 0, n)
			{
				if(on[i] && v[i][cur[i]] == l)
				{
					on[i] = false;
					sz--;
				}
				cur[i]++;
				if(cur[i] == len[i]) cur[i] = 0;
			}
		}
		printf("Case #%d: %s\n", t, ans.c_str());
	}
	return 0;
}

