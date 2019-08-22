/*
Note that the number of distinct areas is at least (H+1)*(V+1).
Then you note that each inversion added in vertical or horizontal adds one more distinct region.
Finally you end noting that the vertical and horizontal inversions can be counted independently.
So the answer is number of inversions in vertical + number of inversions in horizontal + (H+1)*(V+1).
To efficiently count inversions you can use merge sort (my code), segment tree, fenwick tree.
Maybe it's better to see the picture that don't appear in URI in this link: https://codeforces.com/gym/101908/problem/C
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef pair<int, bool> ib;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 100010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9
#define mp(a, b) make_pair(a, b)

ll swaps;

void merge(vector<ii>& v, int l, int mid, int h)
{
	int tmp[h-l+1];
	int lp = l;
	int hp = mid+1;
	int i = 0;
	while(lp <= mid and hp <= h)
	{
		if(v[hp].second < v[lp].second) 
		{
			tmp[i] = v[hp++].second;
			swaps += (mid-lp+1);
		}
		else
		{
			tmp[i] = v[lp++].second;
		}
		i++;
	}
	while(lp <= mid)
	{
		tmp[i++] = v[lp++].second;
	}
	while(hp <= h)
	{
		tmp[i++] = v[hp++].second;
	}
	for(i = l; i <= h; ++i)
	{
		v[i].second = tmp[i-l];
	}
}

void mergeSort(vector<ii>& v, int l, int h)
{
	if(l >= h) return ;
	int mid = (h+l)>>1;
	mergeSort(v, l, mid);
	mergeSort(v, mid+1, h);
	merge(v, l, mid, h);
}

int main()
{
	int x, y;
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> x >> y)
	{
		swaps = 0;
		ll h, v;
		cin >> h >> v;
		vector<ii> v1(MAXN);
		for(int i = 0; i < h; ++i)
			cin >> v1[i].first >> v1[i].second;
		sort(v1.begin(), v1.begin()+h);
		mergeSort(v1, 0, h-1);
		for(int i = 0; i < v; ++i)
			cin >> v1[i].first >> v1[i].second;
		sort(v1.begin(), v1.begin()+v);
		mergeSort(v1, 0, v-1);
		cout << (swaps + (h+1)*(v+1)) << '\n';
	}
	return 0;
}