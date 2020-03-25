#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int maximum(int y, int diff, vii& vp) {
	int cnt = 0;
	for(int i = 0; i < vp.size(); i++) {
		bool used = false;
		if(vp[i].second == y) {
			y += diff;
			diff = -diff;
			used = true;
			cnt++;
		}
		if(used) {
			while(i < vp.size()-1 && vp[i].first == vp[i+1].first) i++;
		}
	}
	return cnt;
}

int main() {
	int n;
	while(cin >> n) {
		vii vp(n);
		set<int> sy;
		for(int i = 0; i < n; ++i) {
			int x, y;
			cin >> x >> y;
			vp[i] = make_pair(x, y);
			sy.insert(y);
		}
		sort(vp.begin(), vp.end());
		int mx = 1;
		for(set<int>::iterator it = sy.begin(); it != sy.end(); ++it) {
			mx = max(mx, maximum(*it, -2, vp));
			mx = max(mx, maximum(*it-2, 2, vp));
			mx = max(mx, maximum(*it, 2, vp));
			mx = max(mx, maximum(*it+2, -2, vp));
		}
		cout << mx << endl;
	}
}