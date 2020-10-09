#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define forn(i, n) for(int i = 0; i < n; ++i)

#define forr(i, a, b) for(int i = a; i <= b; ++i)

#define EPS 1e-9

int vowel(char c) {
	return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or c == 'y';
}

int main() 
{
	string a;
	int n;
	cin >> n;
	cin >> a;
	string ans;
	ans.push_back(a[0]);
	for(int i = 1; i < a.size(); ++i) {
		if(vowel(a[i]) and vowel(a[i-1])) {
			a.erase(a.begin() + i);
			i--;
		} else {
			ans.push_back(a[i]);
		}
	}
	cout << ans << endl;
	return 0;
}