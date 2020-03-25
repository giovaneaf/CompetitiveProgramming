#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	while(cin >> n && n)
	{
		vector<long long> v(n);
		for(int i = 0; i < n; ++i)
			cin >> v[i];
		stack<int> s;
		ll maxArea = 0;
		int tp;
		int i = 0;
		while(i < n)
		{
			if(s.empty() or v[s.top()] <= v[i])
				s.push(i++);
			else
			{
				tp = s.top();
				s.pop();
				maxArea = max(maxArea, v[tp]*(s.empty() ? i : i - s.top() - 1));
			}
		}
		while(s.size())
		{
			tp = s.top();
			s.pop();
			maxArea = max(maxArea, v[tp]*(s.empty() ? i : i - s.top() - 1));
		}
		cout << maxArea << "\n";
	}
	return 0;
} 