#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, k;
    while(cin >> n >> m >> k)
    {
        vector<int> v(k, 0);
        for(int i = 0; i < n; ++i)
        {
            int h;
            cin >> h;
            v[h%k]++;
        }
        long long ans = 0LL;
        for(int i = 0; i < m; ++i)
        {
            int h;
            cin >> h;
            h %= k;
            ans += v[(k-h)%k];
        }
        cout << ans << "\n";
    }
    return 0;
}
