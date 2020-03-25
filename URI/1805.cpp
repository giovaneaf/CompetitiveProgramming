#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;

int main() {
	ull a, b;
	while(scanf("%llu %llu", &a, &b) != EOF) {;
	    printf("%llu\n", (b*(b+1))/2 - ((a-1)*a)/2);
	}
}