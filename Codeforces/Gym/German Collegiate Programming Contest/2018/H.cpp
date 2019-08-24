/*
Just try all possibilities with prunning. The value f(n, s) = sum from i = 1 to s of i^(n-1).
You can check that the highest dimension is less than 60 because f(n, 2) = 10^16 then you have
10^16 = 2^(n-1)+1 <=> n = log2(10^16-1) + 1.
So you can check all dimensions because there are at most 55 (60 for precaution).
Then you just test for all dimensions and keep adding steps until the number of blocks is less than m.
When it's greater then or equal to m just check if it's equal if it's is voilà you found it, if it's not equal
to m just go to another dimension.
Note that when dimension is equal to 3 you have something like f(3, s) = sum from i = 1 to s of i^(2) and this
sum grows in cubic order. So you i'll reach 10^16 in ³√(10^16). So the time complexity is O(|d|³√m) where |d| is 
the number of dimensions tested which is at most 60 in our case.

You can check that this sum grows in cubic order in this cheat sheet: https://www.tug.org/texshowcase/cheat.pdf
*/
 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef pair<int, bool> ib;
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 100010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9
#define mp(a, b) make_pair(a, b)
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll m;
    cin >> m;
    bool can = false;
    RFOR(n, 60, 3)
    {
        ll ans = 0LL;
        ll i = 1LL;
        while(ans < m)
        {
            ll pow = 1LL;
            FOR(j, 0, n-1)
                pow *= i;
            ans += pow;
            i++;
        }
        if(ans == m)
        {
            printf("%d %d\n", n, i-1);
            can = true;
            break;
        }
    }
    if(!can)
        printf("impossible\n");
    return 0;
}