#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, int> ip;
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
#define MAXN 110
#define LOGMAXN 23
#define MAXM 1000010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

const ll mod = 1000000007LL;

int n, m, q;

int V[MAXN][MAXN];
string M[MAXN];

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m)
	{
		memset(V, 0, sizeof(V));
		FOR(i, 0, n)
		{
			cin >> M[i];
		}
		map<vector<int>, int> mm;
		cin >> q;
		string str;
		int cnt = 1;
		vi freq(26, 0);
		FOR(i, 0, q)
		{
			fill(freq.begin(), freq.end(), 0);
			cin >> str;
			for(char& c: str)
			{
				freq[c-'A']++;
			}
			if(mm.find(freq) == mm.end())
			{
				mm[freq] = cnt++;
			}
			else
			{
				mm[freq] = INF;
			}
		}
		FOR(i, 0, n)
		{
			FOR(j, 0, m)
			{
				fill(freq.begin(), freq.end(), 0);
				FOR(k, i, n)
				{
					freq[M[k][j] - 'A']++;
					if(mm.find(freq) != mm.end())
					{
						cnt = mm[freq];
						FOR(kk, i, k+1)
						{
							if(V[kk][j] == INF) continue;
							if(V[kk][j] == 0) V[kk][j] = cnt;
							else if(V[kk][j] != cnt) V[kk][j] = INF;
						}
					}
				}
				fill(freq.begin(), freq.end(), 0);
				FOR(k, j, m)
				{
					freq[M[i][k] - 'A']++;
					if(mm.find(freq) != mm.end())
					{
						cnt = mm[freq];
						FOR(kk, j, k+1)
						{
							if(V[i][kk] == INF) continue;
							if(V[i][kk] == 0) V[i][kk] = cnt;
							else if(V[i][kk] != cnt) V[i][kk] = INF;
						}
					}
				}
				fill(freq.begin(), freq.end(), 0);
				FOR(k, 0, 15)
				{
					if(i+k >= n || j+k >= m) continue;
					freq[M[i+k][j+k] - 'A']++;
					if(mm.find(freq) != mm.end())
					{
						cnt = mm[freq];
						FOR(kk, 0, k+1)
						{
							if(V[i+kk][j+kk] == INF) continue;
							if(V[i+kk][j+kk] == 0) V[i+kk][j+kk] = cnt;
							else if(V[i+kk][j+kk] != cnt) V[i+kk][j+kk] = INF;
						}
					}
				}
				fill(freq.begin(), freq.end(), 0);
				FOR(k, 0, 15)
				{
					if(i-k < 0 || j+k >= m) continue;
					freq[M[i-k][j+k] - 'A']++;
					if(mm.find(freq) != mm.end())
					{
						cnt = mm[freq];
						FOR(kk, 0, k+1)
						{
							if(V[i-kk][j+kk] == INF) continue;
							if(V[i-kk][j+kk] == 0) V[i-kk][j+kk] = cnt;
							else if(V[i-kk][j+kk] != cnt) V[i-kk][j+kk] = INF;
						}
					}
				}
			}
		}
		cnt = 0;
		FOR(i, 0, n)
		{
			FOR(j, 0, m)
			{
				if(V[i][j] == INF) cnt++;
			}
		}
		printf("%d\n", cnt);
		
	}
	return 0;
}