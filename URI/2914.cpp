// Check if the number of diagonals that can be splitted in the circle with equal size parts
// is at least equal to two, if it is then the answer is 'Y' otherwise if 'N'
// This can be done using prefixed array and then for each point in first half of circle
// you check if exists the other half of the circle with the value (total size/2 + current size)
// with a binary search (I used lower_bound built C++ function).
// This can also be done with a set or hash table to check if the searched number exists in set
// or hash table in O(1) or O(logn)

// Time Complexity: O(n*log(n)) - binary search/set or O(n) - hash table

// Binary search here: https://www.geeksforgeeks.org/binary-search/
// Set STL reference here: http://www.cplusplus.com/reference/set/set/

#include <bits/stdc++.h>
#define MAXN 100001
#define MAXQ 50001
#define NOFPRIMES 9592

using namespace std;

typedef long long ll;
tuple<int, int, int> query[MAXQ];
bitset<MAXN> bs;
int prime[NOFPRIMES];
int BIT[MAXN+1];
int ans[MAXQ];

int getSum(int index) 
{ 
    int sum = 0;
    index = index + 1;
    while (index>0) 
    { 
        sum += BIT[index]; 
        index -= index & (-index); 
    } 
    return sum; 
} 
  
void updateBIT(int index, int val) 
{ 
    index = index + 1; 
    while(index <= MAXN) 
    { 
		BIT[index] += val; 
		index += index & (-index); 
    } 
} 

void Sieve()
{
	bs.set();
	bs[0] = bs[1] = 0;
	prime[0] = 2;
	int primes = 1;
	for(int i = 4; i < MAXN; i += 2)
		bs[i] = 0;
	for(int i = 3; i < MAXN; i += 2)
	{
		if(bs[i])
		{
			for(ll j = (ll)i*i; j < MAXN; j += i)
			{
				bs[j] = 0;
			}
			prime[primes++] = i;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	Sieve();
	int q;
	cin >> q;
	for(int i = 0; i < q; ++i)
	{
		int n, k;
		cin >> n >> k;
		query[i] = make_tuple(k, n, i);
	}
	sort(query, query+q, greater<tuple<int, int, int>>());
	int curPrime = NOFPRIMES-1;
	int nQuery = 0;
	bitset<MAXN> marked;
	marked.reset();
	while(nQuery < q)
	{
		while(nQuery < q && get<0>(query[nQuery]) >= prime[curPrime])
		{
			ans[get<2>(query[nQuery])] = get<1>(query[nQuery]) - 1 - getSum(get<1>(query[nQuery]));
			nQuery++;
		}
		for(int j = prime[curPrime]; j < MAXN; j += prime[curPrime])
		{
			if(!marked[j])
			{
				marked[j] = 1;
				updateBIT(j, 1);
			}
		}
		curPrime--;
	}
	for(int i = 0; i < q; ++i)
		printf("%d\n", ans[i]);
	return 0;
}