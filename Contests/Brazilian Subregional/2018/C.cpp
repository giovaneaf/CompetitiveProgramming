#include <bits/stdc++.h>
 
#define mp(a, b) make_pair(a, b)
 
#define MAXN 100010
#define MOD 1000000007
#define INF 1e9
#define EPS 1e-9
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef pair<int, bool> ib;
 
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