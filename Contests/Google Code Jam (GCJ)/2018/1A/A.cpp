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
#define MAXN 110
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007

int T, n, m, H, V, nChips;
string M[MAXN];
int row[MAXN], col[MAXN];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	FOR(t, 1, T+1)
	{
		vi rc, cc;
		nChips = 0;
		bool can = true;
		cin >> n >> m >> H >> V;
		memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));
		FOR(i, 0, n)
		{
			cin >> M[i];
			FOR(j, 0, m)
			{
				if(M[i][j] == '@')
				{
					row[i]++; col[j]++;
					nChips++;
				}
			}
		}
		if((nChips%(H+1)) == 0 && (nChips%(V+1)) == 0)
		{
			int sum, cuts, chips;
			sum = cuts = 0;
			chips = nChips/(H+1);
			rc.push_back(0);
			FOR(i, 0, n)		// check H
			{
				sum += row[i];
				if(sum > chips)
				{
					can = false;
					break;
				}
				if(cuts < H && sum == chips)
				{
					sum = 0;
					cuts++;
					rc.push_back(i+1);
				}
			}
			if(sum != chips || cuts < H) can = false;
			if(can)
			{
				sum = cuts = 0;
				chips = nChips/(V+1);
				cc.push_back(0);
				FOR(j, 0, m)		// check V
				{
					sum += col[j];
					if(sum > chips)
					{
						can = false;
						break;
					}
					if(cuts < V && sum == chips)
					{
						sum = 0;
						cuts++;
						cc.push_back(j+1);
					}
				}
				if(sum != chips || cuts < V) can = false;
				if(can)
				{
					chips = nChips/((H+1)*(V+1));
					rc.push_back(n); cc.push_back(m);
					FOR(i, 0, (int) rc.size()-1)
					{
						FOR(j, 0, (int) cc.size()-1)
						{
							//printf("%d %d %d %d\n", rc[i], rc[i+1], cc[j], cc[j+1]);
							sum = 0;
							FOR(k, rc[i], rc[i+1])
								FOR(l, cc[j], cc[j+1])
									if(M[k][l] == '@') sum++;
							if(sum != chips)
							{
								can = false;
								break;
							}
						}
						if(!can) break;
					}
				}
			}
		}
		else can = false;
		printf("Case #%d: %s\n", t, can ? "POSSIBLE" : "IMPOSSIBLE");
	}
	return 0;
}

