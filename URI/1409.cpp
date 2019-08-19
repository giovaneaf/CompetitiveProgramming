/*
Knapsack problem to compute the minimum mana needed to kill a monster with health x.
Then you change the life of the monster by the minimum mana (pre computed with Knapsack) to kill him then
you can run Dijkstra shortest path to compute the minimum mana to reach the goal. 
Becareful that one room can have more than one monster.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;

int Matrix[1001][1001];

int Dijkstra(vector<vector<int > >& v, int* costMonster, int N, int M)
{
	bool visited[N];
	int dist[N];
	memset(visited, false, sizeof(visited));
	memset(dist, -1, sizeof(dist));
	dist[0] = costMonster[0];
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	pq.push(make_pair(dist[0], 0));
	while(pq.size())
	{
		int a = pq.top().second;
		pq.pop();
		if(a == N-1)
			break;
		if(!visited[a])
		{
			visited[a] = true;
			for(int i = 0; i < v[a].size(); i++)
			{
				int adj = v[a][i];
				int w;
				if(!visited[adj])
				{
					w = costMonster[adj];
					if(dist[adj] == -1 || dist[adj] > w + dist[a])
					{
						dist[adj] = w + dist[a];
						pq.push(make_pair(dist[adj], adj));
					}
				}
			}
		}
	}
	return dist[N-1];
}

int main()
{
	int M, N, G, K;
	while(cin >> M >> N >> G >> K && M > 0)
	{
		int mana[M];
		int dmg[M];
		for(int i = 0; i < M; i++)
		{
			cin >> mana[i] >> dmg[i];
		}
		for(int i = 0; i < 1001; i++)
		{
			Matrix[0][i] = 0;
			Matrix[i][0] = 0;
			int times = 1;
			if(i%dmg[0] == 0)
				times--;
			times += (i/dmg[0]);
			Matrix[1][i] = times*mana[0];
		}
		for(int i = 2; i <= M; i++)
		{
			for(int j = 1; j < 1001; j++)
			{
				if(dmg[i-1] >= j)
				{
					Matrix[i][j] = min(mana[i-1], Matrix[i-1][j]);
				}
				else
				{
					int times = 1;
					if(j%dmg[i-1] == 0)
						times--;
					times += (j/dmg[i-1]);
					int thisSpell = times*mana[i-1];
					Matrix[i][j] = min(thisSpell, mana[i-1] + Matrix[i][j-dmg[i-1]]);
					Matrix[i][j] = min(Matrix[i][j], Matrix[i-1][j]);
				}
			}
		}
		vector<vector<int > > v(N);
		int a, b;
		int costMonster[N];
		memset(costMonster, 0, sizeof(costMonster));
		for(int i = 0; i < G; i++)
		{
			cin >> a >> b;
			v[a-1].push_back(b-1);
			v[b-1].push_back(a-1);
		}
		for(int i = 0; i < K; i++)
		{
			cin >> a >> b;
			costMonster[a-1] += Matrix[M][b];
		}
		cout << Dijkstra(v,costMonster,N,M) << endl;
	}
	return 0;
}