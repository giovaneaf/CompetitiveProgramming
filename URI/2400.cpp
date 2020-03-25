#include <bits/stdc++.h>

#define INF 1000000000
#define MAXN 100010

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

ll inv;

int v[MAXN];

void merge(int l, int m, int r)
{
	int tmp[r-l+1];
	int il = l;
	int ir = m+1;
	int idx = 0;
	while(il <= m && ir <= r)
	{
		int val;
		if(v[ir] < v[il])
		{
			val = v[ir++];
			inv += (ll) (m-il+1);
		}
		else
			val = v[il++];
		tmp[idx++] = val;
	}
	while(il <= m)
		tmp[idx++] = v[il++];
	while(ir <= r)
		tmp[idx++] = v[ir++];
	for(int i = 0; i < r-l+1; ++i)
		v[l+i] = tmp[i];
}

void mergeSort(int l, int r)
{
	if(r > l)
	{
		int mid = (r+l) >> 1;
		mergeSort(l, mid);
		mergeSort(mid+1, r);
		merge(l, mid, r);
	}
}

int main()
{
	inv = 0LL;
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> v[i];
	mergeSort(0, n-1);
	cout << inv << "\n";
	return 0;
}

