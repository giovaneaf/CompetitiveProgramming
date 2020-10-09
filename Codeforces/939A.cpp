#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define forn(i, n) for(int i = 0; i < n; ++i)

#define forr(i, a, b) for(int i = a; i <= b; ++i)

#define EPS 1e-9

int main() 
{
	int n;
	cin >> n;
	vector<int> v(n);
	forn(i, n) {
		cin >> v[i];
		v[i]--;
	}
	bool visited(n);
	bool found = false;
	for(int i = 0; i < n; ++i) {
		if(i == v[v[v[i]]]) {
			found = true;
			break;
		}
	}
	if(found) cout << "YES";
	else cout << "NO";
	putchar('\n');
	return 0;
}