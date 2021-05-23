/*

Compute Longest Increasing Subsequence (LIS) in O(n*log(n)) using binary search

*/

#include <bits/stdc++.h>
using namespace std;

#define MAXN 100010
 
int n;          // n is the size of the vector
int v[MAXN];    // vector that contains the numbers
// auxiliary vectors for computing LIS
int T[MAXN];
int R[MAXN];    // R[i] store who is the index that comes before of i

bool cmp(const int a, const int b)
{
    return v[a] < v[b];
}

int LIS()
{
    int len;
    len = 1;
    memset(R, -1, sizeof(R));
    T[0] = 0;
    for(int i = 1; i < n; ++i)
    {
        if(v[i] < v[T[0]])
            T[0] = i;
        else
        {
            // use upper_bound if equal numbers can be in the same sequence, otherwise use lower_bound
            int ceiling = distance(T, upper_bound(T, T+len, i, cmp));
            T[ceiling] = i;
            len = max(len, ceiling+1);
            R[i] = T[ceiling-1];
        }
    }
    return len;
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(cin >> n)
    {
        for(int i = 0; i < n; ++i) cin >> v[i];
        printf("%d\n", LIS());
    }
    return 0;
}