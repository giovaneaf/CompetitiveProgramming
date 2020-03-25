#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		string a, b;
		cin >> a >> b;
		bool possible = true;
		if(stoi(a) < stoi(b)) {
			printf("nao encaixa\n");
			continue;
		}
		int ai = a.size()-1;
		for(int i = b.size()-1; i >= 0; --i, ai--) {
			if(b[i] != a[ai]) {
				possible = false;
				break;
			}
		}
		if(possible) {
			printf("encaixa\n");
		} else {
			printf("nao encaixa\n");
		}
	}
}