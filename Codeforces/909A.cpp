#include <bits/stdc++.h>

using namespace std;
 
int main() 
{
	string a, b;
	cin >> a >> b;
	string ans;
	ans += a[0];
	for(int i = 1; i < a.size(); ++i) {
		if(a[i] >= b[0]) break;
		ans += a[i];
	}
	ans += b[0];
	cout << ans << endl;
	return 0;
}