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
#define MAXN 200
#define LOGMAXN 20
#define MAXM 1000010
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL

#define DEBUG 0

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		vi v(n);
		FOR(i, 0, n) 
		{
			cin >> v[i];
			v[i] = -v[i];
		}
		int x;
		bool can = true;
		FOR(i, 0, n) 
		{
			cin >> x;
			v[i] += x;
			if(v[i] < 0) can = false;
		}
		if(can)
		{
			int gap = -1;
			FOR(i, 0, n)
			{
				if(v[i] > 0)
				{
					if(gap == -1)
					{
						gap = v[i];
						while(i < n && v[i] > 0)
						{
							if(gap != v[i])
							{
								can = false;
								break;
							}
							i++;
						}
						i--;
						if(!can) break;
					}
					else
					{
						can = false;
						break;
					}
				}
			}
		}
		printf("%s\n", can ? "YES" : "NO");
	}
	return 0;
}
