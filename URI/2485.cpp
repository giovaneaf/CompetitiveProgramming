#include <iostream>
#include <tuple>
#include <queue>
#include <cstring>

using namespace std;

int search(int i, int j, int M[100][100], int lin, int col)
{
	int dtk = 0;
	bool visited[100][100];
	bool inQueue[100][100];
	memset(visited, false, sizeof(visited));
	memset(inQueue, false, sizeof(inQueue));
	queue< tuple<int, int, int> > q;
	q.push(make_tuple(i, j, 0));
	while(q.size())
	{
		int curDay = get<2>(q.front());
		if(dtk < curDay)
			dtk = curDay;
		i = get<0>(q.front());
		j = get<1>(q.front());
		q.pop();
		if(!visited[i][j])
		{
			visited[i][j] = true;
			inQueue[i][j] = true;
			if(i > 0)
			{
				if(!inQueue[i-1][j] && M[i-1][j] == 1)
				{
					inQueue[i-1][j] = true;
					q.push(make_tuple(i-1, j, curDay+1));
				}
				if(j > 0)
				{
					if(!inQueue[i-1][j-1] && M[i-1][j-1] == 1)
					{
						inQueue[i-1][j-1] = true;
						q.push(make_tuple(i-1, j-1, curDay+1));
					}
				}
				if(j < col-1)
				{
					if(!inQueue[i-1][j+1] && M[i-1][j+1] == 1)
					{
						inQueue[i-1][j+1] = true;
						q.push(make_tuple(i-1, j+1, curDay+1));
					}
				}
			}
			if(j > 0)
			{
				if(!inQueue[i][j-1] && M[i][j-1] == 1)
				{
					inQueue[i][j-1] = true;
					q.push(make_tuple(i, j-1, curDay+1));
				}
			}
			if(i < lin-1)
			{
				if(!inQueue[i+1][j] && M[i+1][j] == 1)
				{
					inQueue[i+1][j] = true;
					q.push(make_tuple(i+1, j, curDay+1));
				}
				if(j > 0)
				{
					if(!inQueue[i+1][j-1] && M[i+1][j-1] == 1)
					{
						inQueue[i+1][j-1] = true;
						q.push(make_tuple(i+1, j-1, curDay+1));
					}
				}
				if(j < col-1)
				{
					if(!inQueue[i+1][j+1] && M[i+1][j+1] == 1)
					{
						inQueue[i+1][j+1] = true;
						q.push(make_tuple(i+1, j+1, curDay+1));
					}
				}
			}
			if(j < col-1)
			{
				if(!inQueue[i][j+1] && M[i][j+1] == 1)
				{
					inQueue[i][j+1] = true;
					q.push(make_tuple(i, j+1, curDay+1));
				}
			}
		}
	}
	return dtk;
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int lin, col;
		cin >> lin >> col;
		int i, j;
		int M[100][100];
		for(i = 0; i < lin; i++)
		{
			for(j = 0; j < col; j++)
			{
				cin >> M[i][j];
			}
		}
		cin >> i >> j;
		int ans = search(i-1, j-1, M, lin, col);
		cout << (ans==0? 1:ans) << endl;
	}
	return 0;
}