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
	int m1, m2;
	m1 = 0;
	m2 = 1000000;
	forn(i, n) {
		int a;
		cin >> a;
		if(a <= 500000) m1 = max(a, m1);
		else m2 = min(m2, a);
	}
	if(m1 == 0) {
		cout << 1000000 - m2 << endl;
	} else if(m2 == 1000000) {
		cout << m1 - 1 << endl;
	} else {
		cout << max(m1-1, 1000000 - m2) << endl;
	}
    return 0;
}