#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define MAXN 100010
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9

int n, m, k;

int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

bool seen[510][510];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m >> k)
	{
		string M[n];
		FOR(i, 0, n) cin >> M[i];
		int cnt = 0;
		ii p;
		FOR(i, 0, n)
		{
			FOR(j, 0, m)
			{
				seen[i][j] = false;
				if(M[i][j] == '.')
				{
					cnt++;
					p.first = i;
					p.second = j;
				}
			}
		}
		queue<ii> q;
		q.push(mp(p.first, p.second));
		seen[p.first][p.second] = true;
		int size = 1;
		while(q.size())
		{
			p = q.front();
			q.pop();
			if(size == cnt-k) break;
			FOR(i, 0, 4)
			{
				int nr = p.first + dr[i];
				int nc = p.second + dc[i];
				if(nr < 0 || nr >= n || nc < 0 || nc >= m || M[nr][nc] != '.' || seen[nr][nc]) continue;
				seen[nr][nc] = true;
				size++;
				if(size == cnt-k) break;
				q.push(mp(nr, nc));
			}
		}
		FOR(i, 0, n)
		{
			FOR(j, 0, m)
			{
				if(M[i][j] == '.' && !seen[i][j]) M[i][j] = 'X';
			}
			cout << M[i] << '\n';;
		}
	}
	return 0;
}