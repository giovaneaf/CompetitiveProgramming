#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	while(a || b) {
		set<int> s1, s2;
		int number;
		for(int i = 0; i < a; ++i) {
			scanf("%d", &number);
			s1.insert(number);
		}
		for(int i = 0; i < b; ++i) {
			scanf("%d", &number);
			s2.insert(number);
		}
		set<int> ans;
		set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter((ans), ans.end()));
		int fst = ans.size();
		ans.clear();
		set_difference(s2.begin(), s2.end(), s1.begin(), s1.end(), inserter((ans), ans.end()));
		int snd = ans.size();
		printf("%d\n", min(fst, snd));
		scanf("%d %d", &a, &b);
	}
	return 0;
}