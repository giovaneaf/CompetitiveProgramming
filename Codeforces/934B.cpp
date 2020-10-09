#include <bits/stdc++.h>

using namespace std;
 
int main()
{
	int k;
	cin >> k;
	if(k > 36) {
		printf("-1\n");
	} else {
		for(int i = 0; i < k/2; ++i) {
			printf("8");
		}
		if(k%2 == 1) printf("9");
		putchar('\n');
	}
    return 0;
}