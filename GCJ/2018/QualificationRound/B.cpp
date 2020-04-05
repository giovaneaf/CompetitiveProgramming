#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	for(int t = 0; t < T; ++t) {
		printf("Case #%d: ", t+1);
		int N;
		scanf("%d", &N);
		vector<int> even;
		vector<int> odd;
		vector<int> sorted(N);
		for(int i = 0; i < N; ++i) {
			int num;
			if(i&1) {
				scanf("%d", &num);
				odd.push_back(num);
			}
			else {
				scanf("%d", &num);
				even.push_back(num);
			}
			sorted[i] = num;
		}
		sort(odd.begin(), odd.end());
		sort(even.begin(), even.end());
		sort(sorted.begin(), sorted.end());
		bool possible = true;
		int io = 0;
		int ie = 0;
		for(int i = 0; i < N; ++i) {
			if(i&1) {
				if(odd[io] != sorted[i]) {
					printf("%d", i);
					possible = false;
					break;
				}
				io++;
			} else {
				if(even[ie] != sorted[i]) {
					printf("%d", i);
					possible = false;
					break;
				}
				ie++;
			}
		}		
		if(possible) {
			printf("OK");
		}
		putchar('\n');
	}
	return 0;
}