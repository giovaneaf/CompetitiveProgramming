// Check if the number of diagonals that can be splitted in the circle with equal size parts
// is at least equal to two, if it is then the answer is 'Y' otherwise if 'N'
// This can be done using prefixed array and then for each point in first half of circle
// you check if exists the other half of the circle with the value (total size/2 + current size)
// with a binary search (I used lower_bound built C++ function).
// This can also be done with two pointers technique

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int n;
	while(cin >> n)
	{
		vector<ll> acc(n+1);
		acc[0] = 0;
		for(int i = 1; i <= n; ++i)
		{
			cin >> acc[i];
			acc[i] += acc[i-1];			
		}
		if(acc[n]&1) // if sum is odd we cannot split in two equal parts
		{
			printf("N\n");
			continue;
		}
		ll mid = acc[n]/2;
		int nOfDiagonals = 0;
		ll sum = 0;
		for(int i = 1; acc[i-1] < mid; ++i)
		{
			ll search = mid+acc[i-1];
			auto it = lower_bound(acc.begin(), acc.end(), search);
			if(*it == search) nOfDiagonals++;
			if(nOfDiagonals > 1) break;
		}
		printf("%c\n", nOfDiagonals > 1 ? 'Y' : 'N');
	}
	return 0;
}