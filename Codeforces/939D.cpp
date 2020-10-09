#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define forn(i, n) for(int i = 0; i < n; ++i)

#define forr(i, a, b) for(int i = a; i <= b; ++i)

#define EPS 1e-9

int n;
int M[26][26];
vector<bool> visited(100005);
set<pair<int, int>> s;

int bfs(int idx) {
	queue<int> q;
	int sum = 0;
	q.push(idx);
	while(q.size()) {
		int cur = q.front();
		q.pop();
		visited[cur] = true;
		sum++;
		forn(i, 26) {
			if(i == cur or M[cur][i] == 0) continue;
			if(!visited[i]) {
				visited[i] = true;
				s.insert(make_pair(min(cur, i), max(cur, i)));
				q.push(i);
			}
		}
	}
	return sum;
}

int main()
{
	cin >> n;
	string a, b;
	cin >> a;
	cin >> b;
	forn(i, 26) {
		forn(j, 26) {
			M[i][j] = 0;
		}
	}
	forn(i, n) {
		M[a[i]-'a'][b[i]-'a'] = 1;
		M[b[i]-'a'][a[i]-'a'] = 1;
	}
	int size = 0;
	visited.assign(n, false);
	for(int i = 0; i < 26; ++i) {
		if(!visited[i]) {
			bfs(i);
		}
	}
	cout << s.size() << endl;
	for(set<pair<int, int>>::iterator it = s.begin(); it != s.end(); ++it) {
		cout << (char) (it->first + 'a') << " " << (char) (it->second + 'a') << endl;
	}
	return 0;
}