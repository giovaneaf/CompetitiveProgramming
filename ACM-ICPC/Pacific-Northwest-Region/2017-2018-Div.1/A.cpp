// Brute force to find any even palindrome substring
// Time Complexity: O(|s|³) - Brute force

// Palindrome: https://www.geeksforgeeks.org/c-program-check-given-string-palindrome/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s;
	while(cin >> s)
	{
		bool odd = true;
		for(int i = 0; i < s.size() && odd; ++i)
		{
			for(int j = i+1; j < s.size(); j += 2)
			{
				string rev = s.substr(i, j-i+1);
				reverse(rev.begin(), rev.end());
				if(s.substr(i, j-i+1) == rev)
				{
					odd = false;
					break;
				}
			}
		}
		cout << (odd ? "Odd." : "Or not.") << "\n";
	}
	return 0;
}