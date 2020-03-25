#include <bits/stdc++.h>

using namespace std;

int main()
{
	int K, N;
	cin >> K >> N;
	vector<pair<int, int> > v(K);
	for(int i = 0; i < K; i++)
		v[i] = make_pair(0, i+1);
	for (int i = 0; i < N; i++)
	{
		int data;
		cin >> data;
		v[--data].first++;
	}
	sort(v.begin(), v.end());
	if(v[K-1].first == v[0].first + 2 and v[0].first == v[1].first - 1 and v[K-1].first == v[K-2].first + 1)
		cout << "-" << v[K-1].second << " +" << v[0].second;
	else if(v[K-1].first == v[0].first + 1 and v[K-1].first == v[K-2].first + 1)
		cout << "-" << v[K-1].second;
	else if(v[0].first + 1 == v[K-1].first)
		cout << "+" << v[0].second;
	else
		cout << "*";
	cout << endl;
	return 0;
}