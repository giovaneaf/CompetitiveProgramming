#include <bits/stdc++.h>
using namespace std;
 
vector<bool> booleanos(2e6, false);
 
int main() {
	int N;
	cin >> N;
	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		if (s[0] == '-') continue;
		if (s.length() > 7) continue;
		if (stoi(s) > 1000001) continue;
		booleanos[stoi(s)] = true;
	}
	for (int i = 0; i < booleanos.size(); i++) {
		if (!booleanos[i]) { cout << i << endl; break; }
	}
	return 0;
}