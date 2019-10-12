/*
Generate all primes with Sieve and store it in an array.
Then you can use a Range Sum Query(RSQ) data structure to query and update in O(log(n)).
You can answer the query offline sorting the query by K value in descending order.
Then you can compute how many numbers in range doensn't have a prime greater than or equal to K in its
prime decomposition by computing all range and removing the numbers that have a prime greater than K in its
prime decomposition.
You start in the last prime and because you sorted the queries by K in descending order you keep adding the primes
(and his multiples) to this RSQ while the prime is greater than the current K of the query. Then when the current prime
is less than or equal to the current K of the query you can answer in the way described above.
Becareful to not add a number to RSQ more than one time.
*/

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