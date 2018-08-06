// The expected number is n + (p - (1-p))*a
// Time Complexity: O(1) // just compute this formula

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, a, p;
	while(cin >> n >> a >> p)
	{
		long double win = p/100.0;
		long double gap = (win - (1-win))*a; // (probability to win - probability to loose)*number of battles
		long double ans = n + gap;
		printf("%.7Lf\n", ans);
	}
	return 0;
}