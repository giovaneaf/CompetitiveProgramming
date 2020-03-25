#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-9

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	int sum = 0;
	for(int i = 0; i < n; ++i)
	{
		cin >> v[i];
		sum += v[i];
	}
	priority_queue<double> pq;
	for(int i = 0; i < n; ++i)
	{
		pq.push((double) v[i]/sum);
	}
	bool first = true;
	if(pq.top() > 0.45 or fabs(pq.top() - 0.45) < EPS);
	else if(pq.top() > 0.4 or fabs(pq.top() - 0.4) < EPS)
	{
		double per = pq.top();
		pq.pop();
		while(pq.size())
		{
			if(per - 0.1 < pq.top() and fabs(per-0.1-pq.top()) > EPS)
			{
				first = false;
				break;
			}
			pq.pop();
		}
	}
	else
	{
		first = false;
	}
	cout << (first ? '1' : '2') << "\n";
	return 0;
}