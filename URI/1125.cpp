#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define MAXN 200010

int n, m;

bool cmp(const ii& a, const ii& b)
{
	if(a.first > b.first || (a.first == b.first && a.second < b.second))
		return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m)
	{
		if(n == 0 && m == 0) break;
		int M[110][110];
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < m; ++j)
			{
				cin >> M[i][j];
				M[i][j]--;
			}
		}
		int S;
		cin >> S;
		while(S--)
		{
			int k;
			cin >> k;
			int points[110];
			for(int i = 0; i < k; ++i)
			{
				cin >> points[i];
			}
			vii score;
			for(int j = 0; j < m; ++j)
			{
				int pt = 0;
				for(int i = 0; i < n; ++i)
				{
					if(M[i][j] < k)
						pt += points[M[i][j]];
				}
				score.push_back(make_pair(pt, j));
			}
			sort(score.begin(), score.end(), cmp);
			printf("%d", score[0].second+1);
			int i = 1;
			while(i < m && score[i].first == score[i-1].first)
			{
				printf(" %d", score[i].second+1);
				i++;
			}
			printf("\n");
		}
	}
	return 0;
}