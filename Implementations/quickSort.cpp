/*
	Quick sort algorithm implementation
	Expected time complexity : O(n*log(n))
	Worst case time complexity : O(n^2)
	Input : l and r are the indices and v is the vector.
	Output : The range [l, r] of the vector v will be sorted (0-index based)
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

template <class T>
int pivotIdx(int l, int r, vector<T>& v)
{
	int pos = l;
	// r is the pivot
	for(int i = l; i < r; ++i)
	{
		if(v[i] <= v[r])
		{
			swap(v[i], v[pos]);
			pos++;
		}
	}
	swap(v[r], v[pos]);
	return pos;
}

template <class T>
void quickSort(int l, int r, vector<T>& v)
{
	if(l >= r)
		return ;
	int m = pivotIdx(l, r, v);
	quickSort(l, m-1, v);
	quickSort(m+1, r, v);
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n = 5;
	vector<double> v(n);
	srand(time(0));
	for(int i = 0; i < n; ++i)
		v[i] = (double)rand() / RAND_MAX;
	/*for(int i = 0; i < n; ++i)
		printf("%f ", v[i]);
	putchar('\n');*/
	quickSort(0, (int) v.size()-1, v);
	/*for(int i = 0; i < n; ++i)
		printf("%f ", v[i]);
	putchar('\n');*/
}