#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <vector>

using namespace std;

class Compare
{
public:
	bool operator()(pair < vector < int >, int > n1, pair < vector < int >, int > n2)
	{
		return n1.second > n2.second;
	}
};

void auxx(int x, int y, int dist, vector < int >& aux,map < vector < int >, int >& m, priority_queue < pair < vector < int >, int >, vector < pair < vector < int >, int > >, Compare >& pq)
{
	if (aux[x] != aux[y])
	{
		swap(aux[x],aux[y]);
		int cost = aux[x] + aux[y];
		if (m.count(aux) == 0)
		{
			m[aux] = cost + dist;
			pq.push(make_pair(aux,cost + dist));
		}
		else
		{
			if (m[aux] > (cost + dist))
			{
				m[aux] = cost + dist;
				pq.push(make_pair(aux, cost+dist));
			}
		}
		swap(aux[x],aux[y]);
	}
}

int Dijkstra (vector < int >& a, vector < int >& b)
{
	priority_queue < pair < vector < int >, int >, vector < pair < vector < int >, int > >, Compare > pq;
	set < vector < int > > s;
	vector < int > aux;
	map < vector < int >, int > m;
	m[a] = 0;
	pq.push(make_pair(a,0));
	
	while(!pq.empty())
	{
		pair < vector < int >, int > p = pq.top();
		aux = p.first;
		int dist = p.second;
		pq.pop();
		if (aux == b)
			return m[b];
		if (s.find(aux) == s.end())
		{
			s.insert(aux);
			auxx (0, 1, dist, aux, m, pq);
			auxx (0, 4, dist, aux, m, pq);
			auxx (1, 2, dist, aux, m, pq);
			auxx (1, 5, dist, aux, m, pq);
			auxx (2, 3, dist, aux, m, pq);
			auxx (2, 6, dist, aux, m, pq);
			auxx (3, 7, dist, aux, m, pq);
			auxx (4, 5, dist, aux, m, pq);
			auxx (5, 6, dist, aux, m, pq);
			auxx (6, 7, dist, aux, m, pq);
		}	
	}
	return m[b];
}

int main()
{
	vector < int > a;
	vector < int > b;
	int i, C;
	for (i = 0; i < 8; i++)
	{
		cin >> C;
		a.push_back(C);
	}
	for (i = 0; i < 8; i++)
	{
		cin >> C;
		b.push_back(C);
	}
	if (a == b)
		cout << "0" << endl;
	else
			cout << Dijkstra(a,b) << endl;
	return 0;
}