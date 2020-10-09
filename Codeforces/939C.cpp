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
	long long A[n];
	long long C[n];
	long long RA[n];
	cin >> C[0];
	A[0] = C[0];
	for(int i = 1; i < n; ++i) {
		cin >> C[i];
		A[i] = C[i] + A[i-1];
	}
	RA[n-1] = C[n-1];
	for(int i = n-2; i >= 0; --i) {
		RA[i] = C[i] + RA[i+1];
	}
	int s, f;
	cin >> s >> f;
	ll mx = 0;
	int time = 0;
	int diff = f-s;
	for(int i = 0; i < n; ++i) {
		ll tmp;
		if(i-diff+1 < 0) {
			tmp = RA[0] - RA[i+1] + RA[(i-diff+1+n)%n];
		} else {
			tmp = A[i] - (i - diff == -1 ?  0 : A[i-diff]); 
		}
		ll aux = f-1-i <= 0 ? f-1-i+n : f-1-i;
		if(tmp > mx or (tmp == mx and time > aux)) {
			mx = tmp;
			time = aux;
		}
	}
	cout << time << endl;
	return 0;
}