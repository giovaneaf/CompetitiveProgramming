/*
You can binary search the answer and for each mid value x in binary search
simulate the fight and check who wins.
*/

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define MAXN 1010
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
 
int n, m;
int a[MAXN];
int b[MAXN];
 
bool can(int v)
{
    FOR(i, 0, n)
    {
        if(a[i]+v > b[i]) return true;
        if(a[i]+v < b[i]) return false;
    }
    return true;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n)
    {
        FOR(i, 0, n) cin >> a[i];
        FOR(i, 0, n) cin >> b[i];
        int l = 0;
        int h = MAXN;
        while(h-l > 1)
        {
            int mid = (h+l)/2;
            if(can(mid)) h = mid;
            else l = mid+1;
        }
        printf("%d\n", can(l) ? l : h);
    }
    return 0;
}