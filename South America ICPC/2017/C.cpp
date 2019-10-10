/*
Count frequencies and check the possible cases:
if the least frequent value + 2 is equal to the highest frequent value and all between then are equal to 
least frequent value + 1 then you need to change the highest frequent to the least frequent.
else if the least frequent value is one less then all other values then you need to add the least frequent value.
else if the highest frequent value is one plus then all other values then you need to remove the highest frequent value.
otherwise you print '*' because you can't do this in one operation.
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int K, N;
	while(cin >> K >> N)
	{
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
	}
	return 0;
}