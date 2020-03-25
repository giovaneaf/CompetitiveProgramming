#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const ll INF = 1000000000000000000LL;
 
int main()
{
    int pre[110];
    int n;
    while(cin >> n)
    {
        pre[0] = 0;
        for(int i = 1; i <= n; ++i)
        {
            cin >> pre[i];
            pre[i] += pre[i-1];
        }
        ll memo[110][110];
        for(int i = 0; i < n; ++i)
            memo[i][i] = 0LL;
        for(int d = 1; d < n; ++d)
        {
            for(int row = 0; row < n-d; ++row)
            {
                int i = row;
                int j = d+row;
                memo[i][j] = INF;
                for(int k = 0; k < j-i; ++k)
                {
                    memo[i][j] = min(memo[i][j], memo[i][i+k] + memo[i+k+1][j] + ((pre[k+i+1] - pre[i])%100) * ((pre[j+1] - pre[k+i+1])%100));
                }
            }
        }
        printf("%lld\n", memo[0][n-1]);
    }
    return 0;
}