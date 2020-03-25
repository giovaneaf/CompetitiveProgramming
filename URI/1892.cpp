#include <bits/stdc++.h>

using namespace std;

long long swaps;

void merge(string* v, int l, int mid, int h)
{
	string tmp[h-l+1];
	int lp = l;
	int hp = mid+1;
	int i = 0;
	while(lp <= mid and hp <= h)
	{
		if(v[hp] < v[lp]) 
		{
			tmp[i] = v[hp++];
			swaps += (mid-lp+1);
		}
		else
		{
			tmp[i] = v[lp++];
		}
		i++;
	}
	while(lp <= mid)
	{
		tmp[i++] = v[lp++];
	}
	while(hp <= h)
	{
		tmp[i++] = v[hp++];
	}
	for(i = l; i <= h; ++i)
	{
		v[i] = tmp[i-l];
	}
}

void mergeSort(string* v, int l, int h)
{
	if(l >= h) return ;
	int mid = (h+l)/2;
	mergeSort(v, l, mid);
	mergeSort(v, mid+1, h);
	merge(v, l, mid, h);
}

int main()
{
	int n;
	while(cin >> n)
	{
		swaps = 0;
		string arr[n];
		for(int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		mergeSort(arr, 0, n-1);
		printf("%lld\n", swaps);
	}
	return 0;
}