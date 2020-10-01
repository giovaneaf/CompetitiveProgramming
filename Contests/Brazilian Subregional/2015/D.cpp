#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000

int M[110][110];
int equations[210][210];

int main()
{
	int n, m;
	cin >> n >> m;
	unordered_map<string, int> toIndex;
	vector<string> toString; 
	vector<int> ans;
	int idx = 0;
	int row[n];
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			string s;
			cin >> s;
			if(toIndex.find(s) == toIndex.end())
			{
				toIndex[s] = idx++;
				toString.push_back(s);
			}
			int id = toIndex[s];
			M[i][j] = id;
			equations[i][id]++;
		}
		cin >> row[i];
	}
	int col[m];
	for(int j = 0; j < m; ++j)
	{
		for(int i = 0; i < n; ++i)
		{
			equations[j+n][M[i][j]]++;
		}
	}
	for(int j = 0; j < m; ++j)
	{
		cin >> col[j];
	}
	/*for(int j = 0; j < n+m; ++j)
	{
		for(int i = 0; i < idx; ++i)
		{
			printf("%d ", equations[j][i]);
		}
		putchar('\n');
	}*/
	ans.assign(idx, INF);
	for(int var = 0; var < idx; ++var)
	{
		bool find = false;
		for(int i = 0; i < n; ++i)
		{
			int unknows = 0;
			int index = -1;
			int acc = 0;
			for(int j = 0; j < idx; ++j)
			{
				if(equations[i][j] > 0)
				{
					if(ans[j] != INF)
					{
						acc += equations[i][j]*ans[j];
					}
					else
					{
						unknows++;
						if(unknows > 1) break;
						index = j;
					}
				}
			}
			if(unknows == 1)
			{
				find = true;
				ans[index] = (row[i] - acc)/equations[i][index];
				break;
			}
		}
		if(!find)
		{
			for(int i = 0; i < m; ++i)
			{
				int unknows = 0;
				int index = -1;
				int acc = 0;
				for(int j = 0; j < idx; ++j)
				{
					if(equations[i+n][j] > 0)
					{
						if(ans[j] != INF)
						{
							acc += equations[i+n][j]*ans[j];
						}
						else
						{
							unknows++;
							if(unknows > 1) break;
							index = j;
						}
					}
				}
				if(unknows == 1)
				{
					ans[index] = (col[i] - acc)/equations[i+n][index];
					break;
				}
			}
		}
	}
	sort(toString.begin(), toString.end());
	for(int i = 0; i < idx; ++i)
	{
		cout << toString[i] << " " << ans[toIndex[toString[i]]] << "\n";
	}
	return 0;
}