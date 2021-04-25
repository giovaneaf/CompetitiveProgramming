/*
	Max heap implementation with the following operations:
	findMax() 	- Find the maximum element of the heap in constant time (O(1))
	push()		- Insert element inside heap in logarithmic time (O(log(n)))
	pop()		- Remove maximum element inside heap in logarithmic time (O(log(n)))
	buildHeap() - Construct a heap from a set of values in linear time (O(n))
	heapSort()	- Sort the given vector in O(n*log(n)) using buildHeap operation
	size() 		- Return the current size of the heap
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
struct Heap
{
	vector<T> v;
	int n;
	// maxSz is maximum size of the heap
	Heap(int maxSz)
	{
		v.resize(maxSz);
		n = 0;
	}
	T findMax()
	{
		return v[0];
	}
	int size()
	{
		return n;
	}
	void push(T val)
	{
		assert(n < (int) v.size());
		int par = ((n-1) >> 1);
		int cur = n;
		v[n++] = val;
		while(v[par] < v[cur])
		{
			swap(v[cur], v[par]);
			cur = par;
			par = ((par-1) >> 1);
		}
	}
	// Delete the maximum value
	void pop()
	{
		assert(n > 0);
		n--;
		swap(v[0], v[n]);
		maxHeapify(0);
	}
	// build Heap in linear time
	void buildHeap(vector<T>& data)
	{
		v = data;
		n = (int) data.size();
		int start = ((n-2) >> 1);
		for(int i = start; i >= 0; --i)
			maxHeapify(i);
	}	
	void maxHeapify(int cur)
	{
		int lc, rc, nxt;
		lc = 2*cur+1; rc = lc+1;
		while((lc < n && v[cur] < v[lc]) || (rc < n && v[cur] < v[rc]))
		{
			if(rc >= n)
				nxt = lc;
			else
				nxt = (v[rc] < v[lc] ? lc : rc);
			swap(v[cur], v[nxt]);
			cur = nxt;
			lc = 2*cur+1; rc = lc+1;
		}
	}
	void heapSort(vector<T>& data)
	{
		buildHeap(data);
		for(int i = (int) data.size() - 1; i >= 0; --i)
		{
			data[i] = findMax();
			pop();
		}
	}
};

struct Info
{
	int key;
	Info(int key = -1) : key(key) {}
	bool operator< (Info& i) 
	{
		return key < i.key;
	}
};

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	{
		// Example using struct
		Heap<Info> heap(10); // 10 is maxSize
		heap.push(Info(5));
		heap.push(Info(7));
		heap.push(Info(8));
		heap.push(Info(3));
		heap.push(Info(2));
		heap.push(Info(15));
		while(heap.size())
		{
			printf("Max val = %d\n", heap.findMax().key);
			heap.pop();
		}
	}
	// Example heapSort using int vector
	Heap<int> heap(10);
	int n = 10;
	vector<int> v(n);
	srand(time(0));
	for(int i = 0; i < 10; ++i)
		v[i] = rand()%10;
	for(int i = 0; i < n; ++i)
		printf("%d ", v[i]);
	putchar('\n');
	heap.heapSort(v);
	for(int i = 0; i < n; ++i)
		printf("%d ", v[i]);
	putchar('\n');
}