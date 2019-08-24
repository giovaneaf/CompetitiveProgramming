/*
If you analyze carefully you note that the parity is very important.
For example the even positions are added together and subtracted by the odd positions.
And the odd positions are added together and subtracted by the even positions.
Noting this, you can conclude that if you start with a number x in first position then all with
the same parity in position with this number will be added by x and subtracted by x otherwise.
So, you can compute by x = 0 (to simplify) and all numbers are determined. For example, the second number
will be a1-x, the second will be a2-(a1-x) and so on.
Then you compute the minimum value for the odd positions (one variable called e below) and 
even positions (another variable called s below) starting at 0 because x = 0.
Then the answer is max(0, e+s+1) because e is always lesser or equal to 0 so you need to start in x = -e: all even positions
greater than or equal to 0 and you can increase x until x = s: all odd positions greater than or equal to 0.
so x can be any value in the interval [-e, s]. The answer will be the interval s-(-e) + 1 = s + e + 1 but this value can
be negative so you put the max(0, e+s+1).
*/

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define MAXN 50010
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
 
int n;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n)
    {
        ll s, e;
        s = 0;
        e = 1e9;
        ll ant = 0;
        FOR(i, 0, n)
        {
            ll val;
            cin >> val;
            ll cur = val - ant;
            if(i&1)
            {
                s = min(cur, s);
            }
            else
            {
                e = min(cur, e);
            }
            ant = cur;
        }
        e += s;
        e = max(0LL, e+1LL);
        printf("%lld\n", e);
    }
    return 0;
}
