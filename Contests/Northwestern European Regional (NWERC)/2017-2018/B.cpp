#include <bits/stdc++.h>
 
using namespace std;
 
#define ii pair<int, int>
#define vii vector<ii>
 
int main()
{
	int n;
	while(cin >> n)
	{
		int t = 0;
		int b = 2;
		int ans = 1;
		while((b-1+n)%n != t && b%n != t && (b+1)%n != t)
		{
			ans++; t++; b += 2;
		}
		cout << ans << '\n';
	}
}