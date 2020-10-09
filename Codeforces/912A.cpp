#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
 
int main() 
{
	ll A, B;
	cin >> A >> B;
	ll x, y, z;
	cin >> x >> y >> z;
	ll nA, nB;
	nA = x*2LL + y;
	nB = y + 3LL*z;
	cout << max(0LL, nA - A) + max(0LL, nB - B) << endl;
	return 0;
}