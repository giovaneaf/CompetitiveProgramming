/*
	Max Histogram problem
	Solution in O(n) using stack	
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, int> ip;
typedef pair<int, bool> ib;
 
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define all(v) v.begin(), v.end()
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 100010
#define LOGMAXN 23
#define MAXM 1000010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define MAXWORDS 1010
 
ll mod = 1000000007LL;

template <typename T>
T maxHistogram(vector<T>& v)
{
	int n = (int) v.size();
	stack<int> s;
	int i = 0;
	T maxArea = 0;
	T area;
	int top;
	for(; i < n; ++i)
	{
		// Keep removing from stack while there are elements that are greater than current
		while(s.size() && v[s.top()] > v[i])
		{
			top = s.top();
			s.pop();
			if(s.size())
				// all elements from [s.top()+1, i-1] are greater or equal
				area = v[top]*(i-s.top()-1);
			else
				area = v[top]*i;	// this element is the smallest in the subarray [0, i-1]
			if(area > maxArea)
				maxArea = area;
		}
		s.push(i);
	}
	while(s.size())
	{
		top = s.top();
		s.pop();
		if(s.size())
			area = v[top]*(i-s.top()-1);
		else
			area = v[top]*i;
		if(area > maxArea)
			maxArea = area;	
	}
	return maxArea;
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<ll> v(n);
	FOR(i, 0, n)
		cin >> v[i];
	printf("%lld\n", maxHistogram(v));
}