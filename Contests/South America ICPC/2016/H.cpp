/*
Greedily choose the highest value to be free whenever it's possible.
You can find it in O(log(n)) with a priority_queue, for example.
*/

#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
    int N, K;
    int priece[100000];
    int i,j,cont;
    while(cin >> N >> K)
	{
		j = 0;
		for (i=0;i<N;i++)
		{
			cin >> priece[i];
		}
		int sum = 0;
		i = 0;
		cont = 0;
		while (i<K && i<N)
		{
			sum += priece[i];
			i++;
			cont++;
		}
		priority_queue<int,vector<int>, greater<int> > pq;
		while (N > cont+K+1)
		{
			for (j=0;j<K+1;j++)
			{
				pq.push(priece[cont+j]);
			}
			cont += K+1;
			for (j=0;j<K;j++)
			{
				sum += pq.top();
				pq.pop();
				i++;
			}
		}
		j = 0;
		while(j<K+1 && cont+j < N)
		{
			pq.push(priece[cont+j]);
			j++;
		}
		while (N-i > i/K)
		{
			sum += pq.top();
			pq.pop();
			i++;
		}
		cout << sum << endl;
	}
    return 0;
}
