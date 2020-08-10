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
#define LOGMAXN 21
#define MAXM 250010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

ll mod = 1000000007LL;

int T, n, m, k;
string str;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	FOR(t, 0, T)
	{
		int ans;
		cin >> n >> k;
		cin >> str;
		if(k == 1)
		{
			printf("%d\n", n);
			continue;
		}
		bool can = false;
		int lpos = 0;
		int rpos;
		FOR(i, 1, n)
		{
			if(str[i] != str[lpos])
			{	
				if(can)	break;
				lpos = i;
			}
			if(i - lpos + 1 >= k)
			{
				can = true;
				rpos = i;
			}
		}
		if(can)
		{
			ans = 0;
			int sp;
			if(lpos > 0)
			{
				ans++;
				sp = 0;
				FOR(i, 1, lpos)
				{
					if(str[i] != str[sp] || i - sp + 1 > k)
					{
						ans++;
						sp = i;
					}
				}
			}
			if(rpos < n-1)
			{
				ans++;
				sp = n-1;
				RFOR(i, n-2, rpos+1)
				{
					if(str[i] != str[sp] || sp - i + 1 > k)
					{
						ans++;
						sp = i;
					}
				}
			}
			ans += (rpos-lpos+1+k-1)/k;
		}
		printf("%d\n", can ? ans : -1);
	}
	return 0;
}
