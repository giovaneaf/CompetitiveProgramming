#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
	    int n;
	    scanf("%d", &n);
	    int total = 0;
	    int v[n];
	    for(int i = 0; i < n; ++i) {
	    	scanf("%d", &v[i]);
	    	total += v[i];
	    }
	    int above = 0;
	    double average = ((double) total)/n;
	    for(int i = 0; i < n; ++i) {
	    	if(v[i] > average) above++;
	    }
	    printf("%.3f%\n", ((double) 100*above)/n);
	}
}