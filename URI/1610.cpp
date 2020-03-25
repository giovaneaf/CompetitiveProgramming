#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool Cycle(int node, vector< vector<int> >& v, int* set)
{
	if(set[node] == 0)
	{
		set[node] = -1;
		vector<int>::iterator it;
		for(it = v[node].begin(); it != v[node].end(); it++)
		{

            if(Cycle(*it, v, set))
				return true;
		}
		set[node] = 1;
	}
	else if (set[node] == -1)
        return true;
	return false;
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int N, M;
		cin >> N >> M;
		vector< vector<int> > v(N);
		for(int i = 0; i < M; i++)
		{
			int a, b;
			cin >> a >> b;
			v[a-1].push_back(b-1);
		}
		int set[N];
		memset(set, 0, sizeof(set));
		bool cycle = false;
		for(int i = 0; i < N; i++)
		{
			if(set[i] == 0)
			{
				if(Cycle(i,v, set))
				{
					cycle = true;
					break;
				}
			}
		}
		cout << (cycle? "SIM" : "NAO") << endl;
	}
	return 0;
}