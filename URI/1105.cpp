#include <bits/stdc++.h>

using namespace std;

int main() {
	int b, n;
	scanf("%d %d", &b, &n);
	while(b || n) {
		vector<int> credit(b);
		for(int i = 0; i < b; ++i) {
			scanf("%d", &credit[i]);
		}
		vector<int> debit;
		debit.assign(b, 0);
		for(int i = 0; i < n; ++i) {
			int from, to, qty;
			scanf("%d %d %d", &from, &to, &qty);
			from--, to--;
			debit[from] += qty;
			credit[to] += qty;
		}
		bool possible = true;
		for(int i = 0; i < b; ++i) {
			if(credit[i] < debit[i]) {
				possible = false;
				break;
			}
		}
		printf("%c\n", (possible ? 'S' : 'N'));
		scanf("%d %d", &b, &n);
	}
}