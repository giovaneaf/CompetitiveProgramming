#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll; 
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 100010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9
 
int n, m, k;
bool M[1010][1010];
bool seen[1010];
int timet[1010];
bool hasBridge;
 
int checkBridge(int cur, int p)
{
	static int t = 0;
	seen[cur] = true;
	timet[cur] = t++;
	int la = t;
	FOR(u, 0, n)
	{
		if(M[cur][u] && u != p)
		{
			if(!seen[u])
			{
				int rec = checkBridge(u, cur);
				if(rec > timet[cur])
				{
					hasBridge = true;
				}
				la = min(la, rec);
			}
			else
				la = min(la, timet[u]);
		}
	}
	return la;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m)
	{
		if(n == 0 && m == 0) break;
		hasBridge = false;
		memset(M, false, sizeof(M));
		memset(seen, false, sizeof(seen));
		FOR(i, 0, m)
		{
			int a, b;
			cin >> a >> b;
			a--, b--;
			M[a][b] = M[b][a] = true;
		}
		checkBridge(0, -1);
		printf("%c\n", hasBridge ? 'N' : 'S');
	}
    return 0;
}