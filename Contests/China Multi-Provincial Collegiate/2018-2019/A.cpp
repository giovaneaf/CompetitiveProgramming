/*
Here you can store a pair in the stack the current element and the maximum element inside the stack (from that point to the
bottom). You can compute the maximum element inside the stack will be the current value if the stack is empty and will be
the maximum between current value and the maximum element of the stack before this value is inside it.
Since you stored the maximum value from each point to the bottom you can just pop values from the stack
and don't need to worry to update the max value in the stack.
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
 
int n, p, q, m;
unsigned int SA, SB, SC;
unsigned int rng61()
{
    SA ^= SA << 16;
    SA ^= SA >> 5;
    SA ^= SA << 1;
    unsigned int t = SA;
    SA = SB;
    SB = SC;
    SC ^= t^SA;
    return SC;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
    int T;
    scanf("%d", &T);
    FOR(t, 1, T+1)
    {
        scanf("%d%d%d%d%u%u%u", &n, &p, &q, &m, &SA, &SB, &SC);
        ll ans = 0LL;
        stack<pair<unsigned int, unsigned int>> s;
        FOR(i, 1, n+1)
        {
            if(rng61() % (p+q) < p)
            {
                unsigned int value = rng61()%m+1;;
                if(s.size())
                    s.push(mp(value, max(s.top().snd, value)));
                else
                    s.push(mp(value, value));
            }
            else
            {
                if(s.size())
                {
                    s.pop();
                }
            }
            if(s.size())
            {
                ans ^= (ll) s.top().snd*i;
            }
        }
        printf("Case #%d: %lld\n", t, ans);
    }
    return 0;
}
close