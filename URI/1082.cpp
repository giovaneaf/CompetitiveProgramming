#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

typedef vector<int> vi;

vector<int> BFS(int index, vector<vi> v, bool* visited)
{
	queue<int> q;
	q.push(index);
	vector<int> l;
	while(q.size())
	{
		int u = q.front();
		q.pop();
		if(!visited[u])
		{
			visited[u] = true;
			l.push_back(u);
			for(int i = 0; i < v[u].size(); i++)
			{
				q.push(v[u][i]);
			}
		}
	}
	sort(l.begin(), l.end());
	return l;
}

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int V,E;
        cin >> V >> E;
        vector<vi> v(V);
        int i;
        for (i = 0; i < E; i++)
        {
            char s,d;
            cin >> s >> d;
            v[s-'a'].push_back(d-'a');
            v[d-'a'].push_back(s-'a');
        }
        bool visited[26];
        memset(visited, false, sizeof (bool)*V);
        int n = 0;
        cout << "Case #" << t+1 << ":\n";
        for (i = 0; i < V; i++)
        {
			if(!visited[i])
			{
				n++;
				vector<int> l;
				l = BFS(i, v, visited);
				for(int j = 0; j < l.size(); j++)
					cout << char (l[j] + 'a') << ",";
				cout << endl;
			}
        }
        cout << n << " connected components\n\n";
    }
    return 0;
}