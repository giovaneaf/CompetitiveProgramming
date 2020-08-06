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
#define MAXN 1010
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

const ll mod = 1000000007;

int n;
string s;

inline int getId(char c)
{
	if(c == 'R') return 0;
	if(c == 'B') return 1;
	return 2;
}

inline char getCounter(char c)
{
	if(c == 'R') return 'S';
	if(c == 'B') return 'K';
	return 'H';
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> s)
	{
		string ans;
		int pos = 0;
		n = (int) s.size();
		vb seen(3, false);
		while(pos < n)
		{
			if(pos + 2 < n)
			{
				bool powerful = true;
				int id;
				FOR(i, 0, 3)
				{
					id = getId(s[pos+i]);
					if(seen[id])
					{
						powerful = false;
						break;
					}
					seen[id] = true;
				}
				if(powerful)
				{
					ans += 'C';
					pos += 3;
				}
				else
				{
					ans += getCounter(s[pos]);
					pos++;
				}
				fill(seen.begin(), seen.end(), false);
			}
			else
			{
				ans += getCounter(s[pos]);
				pos++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

