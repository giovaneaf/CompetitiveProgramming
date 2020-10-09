#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define forn(i, n) for(int i = 0; i < n; ++i)

#define forr(i, a, b) for(int i = a; i <= b; ++i)

#define EPS 1e-9

int memo[1000005];
int fa[1000005];
int acc[1000005][10];

int f(int n) {
	if(n == 0) return 0;
	if(fa[n] != -1) return fa[n];
	int ans = 1;
	while(n != 0) {
		int rem = n%10;
		if(rem > 0) ans *= rem;
		n /= 10;
	}
	return fa[n] = ans;
}

int g(int n) {
	if(n < 10) return memo[n] = n;
	if(memo[n] != -1) return memo[n];
	return memo[n] = g(f(n));
}
 
int main()
{
	forr(i, 1, 1000000){
		memo[i] = -1;
		fa[i] = -1;
	}
	forr(i, 1, 1000000) {
		forr(j, 1, 10) {
			if(g(i) == j) {
				acc[i][j] = 1 + acc[i-1][j];
			} else {
				acc[i][j] = acc[i-1][j];
			}
		}
	}
	int q;
	cin >> q;
	while(q--) {
		int a, b, k;
		cin >> a >> b >> k;
		cout << acc[b][k] - acc[a-1][k] << endl;
	}
    return 0;
}