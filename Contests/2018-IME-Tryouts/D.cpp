// Noted that you should get the cheapest Pokémon available, so you will
// end getting an arithmetic progression(AP) of gap 1
// there are a formula to compute this which is AP(n) = (n+1)*n/2
// so you can binary search for each query what is the maximum number of Pokémons
// you can buy. 
// Be careful, it will overflow long long if your highest target is 10¹⁸.
// Note that the highest Pokémon priece you can get is something like 2*10⁹ because
// applying AP formula will return something like 2*10¹⁸(high) and the highest Pokédollars you
// can have is 10¹⁸.
// Time Complexity: O(n*log(high)) - Binary Search each query

// Arithmetic Progression: https://en.wikipedia.org/wiki/Arithmetic_progression
// Binary Search: https://www.geeksforgeeks.org/binary-search/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll ap(ll x)
{
	return ((x+1LL)*x)/2LL;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	while(n--)
	{
		ll s;
		cin >> s;
		ll low = 0;
		ll high = (long long) 2*(1e9);
		while(high - low > 1LL)
		{
			ll mid = (low+high)/2LL;
			if(s >= ap(mid))
				low = mid;
			else
				high = mid-1;
		}
		cout << (s >= ap(high) ? high : low) << "\n";
	}
	return 0;
}