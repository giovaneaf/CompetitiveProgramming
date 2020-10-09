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
#define MAXN 200010
#define LOGMAXN 20
#define MAXM 1000010
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL

#define DEBUG 0

int p[MAXN];
int dad[MAXN];
int ans[MAXN];
bool seen[MAXN];

void DFS(int cur, int sz)
{
	seen[cur] = true;
	if(!seen[p[cur]])
	{
		dad[p[cur]] = cur;
		DFS(p[cur], sz+1);
	}
	else
	{
		int node = cur;
		while(node != -1)
		{
			ans[node] = sz;
			node = dad[node];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		ll n;
		cin >> n;
		string s;
		bool can = true;
		ll tmp = n;
		while(tmp > 0)
		{
			int rem = tmp%3;
			if(rem == 2)
				can = false;
			s += (rem+'0');
			tmp /= 3;
		}
		s += '0';
		if(can)
		{
			printf("%lld\n", n);
		}
		else
		{
			int endPos = 0;
			RFOR(i, (int) s.size()-1, 0)
			{
				if(s[i] == '2')
				{
					int j = i;
					while(s[j] >= '2')
					{
						s[j+1]++;
						j++;
					}
					endPos = j;
					break;
				}
			}
			FOR(i, 0, endPos)
			{
				s[i] = '0';
			}
			ll ans = 0LL;
			ll pw = 1;
			FOR(i, 0, (int) s.size())
			{
				ans += pw*(s[i]-'0');
				pw *= 3;
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}

