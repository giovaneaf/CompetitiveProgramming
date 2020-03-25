// Because of the limits of the problem you can keep adding the angle until back to angle 0, this step will be done in at most 
// 36000 operations if the angle is 0.01 or 359.99, for example.

// You can also answer 36000/gcd(36000, round(inputAngle*100)) because you can pretend that the gcd value is
// the "step" of each jump and compute in log(36000) operations

// Time Complexity: O(1) - 36000 operations or log(36000) operations

// GCD here: https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/
// Note: The extended euclidian algorithm isn't necessary for this problem, just the basic version

#include <bits/stdc++.h>

#define GCD 0

using namespace std;

int main()
{
	double inputAngle;
	while(cin >> inputAngle)
	{
		int step = round(inputAngle*100);
#if !GCD
		int angle = 0;
		int times = 1;
		while(true)
		{
			angle += step;
			angle %= 36000;
			if(angle == 0) break;
			times++;
		}
		cout << times << '\n';
#endif
#if GCD
		cout << 36000/__gcd(36000, step) << '\n';
#endif
	}
	return 0;
}