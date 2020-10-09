#include <bits/stdc++.h>

using namespace std;
 
int main() 
{
	int n, m;
	cin >> n >> m;
	vector<long long> v1(n);
	vector<long long> v2(m);
	for(int i = 0; i < n; ++i) {
		cin >> v1[i];
	}
	for(int i = 0; i < m; ++i) {
		cin >> v2[i];
	}
	priority_queue<pair<long long, int>> pq;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			pq.push(make_pair(v1[i]*v2[j], i));
		}
	}
	pair<long long, int> p = pq.top();
	pq.pop();
	while(p.second == pq.top().second) {
		pq.pop();
	}
	printf("%lld\n", pq.top().first);
	return 0;
}