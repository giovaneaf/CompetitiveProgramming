#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;

int main() {
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t) {
	    int n;
	    scanf("%d", &n);
	    vector<int> v(n);
	    for(int i = 0; i < n; ++i) {
	        scanf("%d", &v[i]);
	    }
	    nth_element(v.begin(), v.begin() + n/2, v.end());
	    printf("Case %d: %d\n", t+1, v[n/2]);
	}
}