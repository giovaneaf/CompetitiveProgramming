// Just need a data structure to query the number of values greater or equal
// to some value x fast. I did it with segment tree which can query and update 
// in O(log(n)) but a fenwick tree could be used too
// Time Complexity: O(n*log(n))

// Segment Tree: https://www.geeksforgeeks.org/segment-tree-set-1-sum-of-given-range/
// Fenwick Tree (BIT): https://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/

#include <bits/stdc++.h>

using namespace std;

#define MAXS 1000010

int n;

int st[4*MAXS];

void update(int cur, int l, int r, int x)
{
	if(l == r)
	{
		st[cur]++;
		return ;
	}
	int mid = (l + r) >> 1;
	int left = 2*cur+1;
	int right = 2*cur+2;
	if(x <= mid)
		update(left, l, mid, x);
	else
		update(right, mid+1, r, x);
	st[cur] = st[left] + st[right];
}

int query(int cur, int l, int r, int ql, int qr)
{
	if(l > qr || r < ql)
		return 0;
	if(ql <= l && r <= qr)
		return st[cur];
	int mid = (l + r) >> 1;
	int left = 2*cur+1;
	int right = 2*cur+2;
	return query(left, l, mid, ql, qr) + query(right, mid+1, r, ql, qr);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		for(int i = 0; i < 4*MAXS; ++i)
			st[i] = 0;
		for(int i = 0; i < n; ++i)
		{
			int val;
			cin >> val;
			cout << n - query(0, 0, MAXS-1, val, MAXS-1) << "\n";
			update(0, 0, MAXS-1, val);
		}
	}
	return 0;
}