/*
	Radix sort algorithm implementation
	Time complexity : O((n+b)*logb(k)) where k is the 
	maximum value in the array and b is the selected base.
	This implementation only works for non-negative integers elements and the base
	can be selected as an input for the algorithm.
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
void countingSort(vector<T>& v, ll div, int base)
{
	int n = (int) v.size();
	vi count(base, 0);
	for(int i = 0; i < n; ++i)
	{
		count[(v[i]/div)%base]++;
	}
	for(int i = 1; i < base; ++i)
	{
		count[i] += count[i-1];
	}
	vector<T> aux(n);
	for(int i = n-1; i >= 0; --i)
	{
		aux[count[(v[i]/div)%base]-1] = v[i];
		count[(v[i]/div)%base]--;
	}
	for(int i = 0; i < n; ++i)
	{
		v[i] = aux[i];
	}
}

template <typename T>
void radixSort(vector<T>& v, int base)
{
	int mx = 0;
	int n = (int) v.size();
	for(int i = 0; i < n; ++i)
	{
		assert(v[i] >= 0);
		if(v[i] > mx)
			mx = v[i];
	}
	for(ll i = 1; (mx / i) > 0; i *= base)
	{
		countingSort(v, i, base);
	}
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; // vector size
	while(cin >> n)
	{
		vector<ll> v(n);
		for(int i = 0; i < n; ++i)
			cin >> v[i];			// vector elements
		radixSort(v, 10);
		for(int i = 1; i < n; ++i)
			assert(v[i] >= v[i-1]);
		for(int i = 0; i < n; ++i)
			printf("%d ", v[i]);
		putchar('\n');
	}
}