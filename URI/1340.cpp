#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	while(cin >> n) {
		stack<int> s;
		queue<int> q;
		priority_queue<int> pq;
		bool S, Q, PQ;
		S = Q = PQ = true;
		for(int i = 0; i < n; ++i) {
			int a, b;
			cin >> a >> b;
			if(a == 1) {
				s.push(b);
				q.push(b);
				pq.push(b);
			} else {
				if(s.empty() or s.top() != b) {
					S = false;
				} else s.pop();
				if(q.empty() or q.front() != b) {
					Q = false;
				} else q.pop();
				if(pq.empty() or pq.top() != b) {
					PQ = false;
				} else pq.pop();
			}
		}
		if((S and Q and PQ) or (S and Q) or (S and PQ) or (Q and PQ)) {
			cout << "not sure";
		} else if(PQ) {
			cout << "priority queue";
		} else if(S) {
			cout << "stack";
		} else if(Q) {
			cout << "queue";
		} else {
			cout << "impossible";
		}
		cout << endl;
	}
	return 0;
}