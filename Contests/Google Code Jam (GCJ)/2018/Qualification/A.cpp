#include <bits/stdc++.h>

using namespace std;

string s;

typedef long long int ll;

ll dmg() {
	ll mult = 1;
	ll tot = 0;
	for(int i = 0; i < s.size(); ++i) {
		if(s[i] == 'C') mult *= 2;
		else tot += mult;
	}
	return tot;
}

int main() {
	int T;
	cin >> T;
	for(int t = 0; t < T; ++t) {
		printf("Case #%d: ", t+1);
		ll d;
		cin >> d >> s;
		int cnt = 0;
		for(int i = 0; i < s.size(); ++i) {
			if(s[i] == 'S') cnt++;
		}
		if(cnt > d) {
			printf("IMPOSSIBLE");
		} else {
			int ans = 0;
			while(dmg() > d) {
				ans++;
				int index;
				for(int i = 0; i < s.size(); ++i) {
					if(s[i] == 'S') index = i;
				}
				while(index > 0 and s[index] == 'S') index--;
				swap(s[index], s[index+1]);
			}
			printf("%d", ans);
		}
		putchar('\n');
		s.clear();
	}
	return 0;
}