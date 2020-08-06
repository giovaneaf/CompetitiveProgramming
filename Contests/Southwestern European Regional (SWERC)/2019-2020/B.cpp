#include <bits/stdc++.h>
using namespace std;
 
typedef unsigned long long ull;
 
int main() {
 
	map<string, ull> mymap;
 
	string s;
 
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		if(!mymap.count(s)) {
			mymap[s] = 1;
		}
		else {
			mymap[s]++;
		}
	}
 
	ull maxval = 0;
	ull sum = 0;
	string best = "";
 
	for (auto &x : mymap) {
		maxval = max(maxval, x.second);
		if (maxval == x.second) best = x.first;
		sum += x.second;
	}
 
	if (maxval > (sum - maxval)) {
		cout << best << endl;
	}
	else  {
		cout << "NONE" << endl;
	}
 
	return 0;
}