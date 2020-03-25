#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 200010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9

int n, m, k;
int M[210][210][26];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	bool snd = false;
	while(cin >> n)
	{
		int a, b;
		memset(M, 0, sizeof(M));
		FOR(i, 0, n) FOR(j, 0, 26) M[i][i][j] = 1;
		if(snd) putchar('\n');
		else snd = true;
		string s;
		while(cin >> a >> b)
		{
			if(a == 0 && b == 0) break;
			a--, b--;
			cin >> s;
			for(char c : s)
			{
				M[a][b][c-'a'] = 1;
			}
		}
		FOR(k, 0, n)
		{
			FOR(i, 0, n)
			{
				FOR(j, 0, n)
				{
					FOR(l, 0, 26)
					{
						if(M[i][k][l] == 1 && M[k][j][l] == 1) M[i][j][l] = 1;
					}
				}
			}
		}
		while(cin >> a >> b)
		{
			if(a == 0 && b == 0) break;
			a--, b--;
			bool can = false;
			FOR(i, 0, 26)
			{
				if(M[a][b][i] == 1)
				{
					putchar('a'+i);
					can = true;
				}
			}
			if(!can)
				putchar('-');
			printf("\n");
		}
	}
	return 0;
} 