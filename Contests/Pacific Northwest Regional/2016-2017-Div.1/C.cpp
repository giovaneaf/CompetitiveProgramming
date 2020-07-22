// Greedily assigned cameras on rightmost spot without camera respecting problem's constraints
// Time Complexity: O(n*log(n)) - Sorting, keeping priority queue for best spot to put the camera

// No specific algorithm required, just STL's priority queue for O(log(n)) add and remove operations 
// and O(1) finding max operation

#include <bits/stdc++.h>

using namespace std;

#define MAXN 200010
#define LOGMAXN 20
#define INF 1000000010

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k, r;
	while(cin >> n >> k >> r)
	{
		vector<bool> on;
		on.assign(n, false);
		for(int i = 0; i < k; ++i)
		{
			int has;
			cin >> has;
			on[--has] = true;
		}
		priority_queue<int> pq;
		int cam = 0;
		for(int i = 0; i < r; ++i)
		{
			if(on[i])
				cam++;
			else
				pq.push(i);
		}
		int i = r-1;
		int ans = 0;
		while(i < n-1)
		{
			while(cam < 2)
			{
				on[pq.top()] = true;
				pq.pop();
				cam++;
				ans++;
			}
			i++;
			cam += on[i] - on[i-r];
			if(!on[i])
				pq.push(i);
		}
		while(cam < 2)
		{
			on[pq.top()] = true;
			pq.pop();
			cam++;
			ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}