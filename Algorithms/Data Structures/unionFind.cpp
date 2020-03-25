/*

    DSU(Disjoint Set Union) a.k.a as UnionFind in O(log*(n)) where log* is the iterated logarithm
    Implementation of UnionFind DS
 
*/
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

struct UnionFind
{
    vi pset;
    vi szset;   // size of the set
    UnionFind(int n) 
    {
        pset.assign(n, 0);
        szset.assign(n, 1);
        for(int i = 0; i < n; ++i) pset[i] = i;
    }
    int findSet(int i)
    {
        return (pset[i] == i ? i : (pset[i] = findSet(pset[i])));
    }
    bool isSameSet(int i, int j)
    {
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j)     // make set i point to j
    {
        if(isSameSet(i, j)) return;
        szset[findSet(j)] += szset[findSet(i)];
        pset[findSet(i)] = findSet(j);
    }
};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    // small example of usage
    UnionFind uf(5);
    uf.unionSet(1, 2);
    uf.unionSet(0, 4);
    uf.unionSet(0, 3);
    for(int i = 0; i < 5; ++i)
    {
        printf("%d %d\n", uf.findSet(i), uf.szset[uf.findSet(i)]);
    }
    return 0;
} 