/*
	Merge sort algorithm implementation
	Time complexity : O(n*log(n))
	Input : l and r are the indices and v is the vector.
	Output : The range [l, r] of the vector v will be sorted (0-index based)
			 Also the number of inversions will be set correctly if it is zero when called
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

ll inversions = 0;

template <class T>
void merge(int l, int m, int r, vector<T>& v)
{
	int lp, rp, pos;
	lp = l; rp = m+1;
	vector<T> aux(r-l+1);
	pos = 0;
	while(lp <= m && rp <= r)
	{
		if(v[lp] <= v[rp])
		{
			aux[pos++] = v[lp++];
		}
		else
		{
			inversions += (m-lp+1);
			aux[pos++] = v[rp++];
		}
	}
	while(lp <= m)
		aux[pos++] = v[lp++];
	while(rp <= r)
		aux[pos++] = v[rp++];
	for(int i = 0; i < (int) aux.size(); ++i)
		v[l+i] = aux[i];
}

template <class T>
void mergeSort(int l, int r, vector<T>& v)
{
	if(l == r)
		return ;
	int m = (l+r) >> 1;
	mergeSort(l, m, v);
	mergeSort(m+1, r, v);
	merge(l, m, r, v);
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	inversions = 0;
	int n = 5;	// vector size
	vector<double> v(n);
	srand(time(0));
	for(int i = 0; i < n; ++i)
		v[i] = (double)rand() / RAND_MAX; // initialize vector with random values
	/*for(int i = 0; i < n; ++i)
		printf("%f ", v[i]);
	putchar('\n');*/
	mergeSort(0, (int) v.size()-1, v);
	/*for(int i = 0; i < n; ++i)
		printf("%f ", v[i]);
	putchar('\n');*/
	//printf("inversions = %ld\n", inversions);
}