#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
ll F, P, E, A;
ll cost[5010][30][2];
ll memo[5010][30];
 
ll B(int cur, int f)
{
    if(cur >= P)
        return 0;
    if(memo[cur][f] != -1LL)
        return memo[cur][f];
    ll ans = LLONG_MAX;
    for(int i = 0; i < F; ++i)
    {
        if(i == f)
            continue;
        ans = min(ans, E*A + B(cur+1, i));
    }
    ans = min(ans, B(cur+1, f));
    return memo[cur][f] = ans + cost[cur][f][0]*cost[cur][f][1];
}
 
int main()
{
    while(scanf("%lld %lld %lld %lld", &F, &P, &E, &A) != EOF)
    {
        if(F == 0 and P == 0 and E == 0 and A == 0) break;
        for(int i = 0; i < P; ++i)
        {
            for(int j = 0; j < F; ++j)
            {
                memo[i][j] = -1LL;
                scanf("%lld %lld", &cost[i][j][0], &cost[i][j][1]);
            }
        }
        ll ans = B(0, 0);
        for(int i = 1; i < F; ++i)
        {
            ans = min(ans, E*A+B(0, i));
        }
        cout << ans << "\n";
    }
    return 0;
}