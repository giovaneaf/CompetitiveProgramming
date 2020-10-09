#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define forn(i, n) for(int i = 0; i < n; ++i)

#define forr(i, a, b) for(int i = a; i <= b; ++i)

#define EPS 1e-9

int n, a, b;

void genCycle(int x, int y) {
	for(int i = 0; i < x; ++i) {
		for(int j = i*a+1; j < (i+1)*a; j++) {
			printf("%d ", j+1);
		}
		printf("%d ", i*a + 1);
	}
	for(int i = 0; i < y; ++i) {
		for(int j = i*b+1; j < (i+1)*b; j++) {
			printf("%d ", j+1+x*a);
		}
		printf("%d", i*b + 1 + x*a);
		if(i < y-1) putchar(' ');
		else putchar('\n');
	}
}

int main()
{
	cin >> n >> a >> b;
	for(int i = 0; i*a <= n; ++i) {
		if((n-i*a)%b == 0) {
			genCycle(i, (n-i*a)/b);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}