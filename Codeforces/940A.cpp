#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, d;
    while(scanf("%d %d", &n, &d) != EOF)
    {
        vector<int> v(n);
        for(int i = 0; i < n; ++i)
        {
            scanf("%d", &v[i]);
        }
        sort(v.begin(), v.end());
        if(n == 1)
        {
            printf("0\n");
            continue;
        }
        int ans = n;
        for(int i = 0; i < n; ++i)
        {
            int j = i+1;
            while(j < n and v[j] - v[i] <= d) j++;
            ans = min(n-(j-i), ans);
        }
        printf("%d\n", ans);
    }
    return 0;
}
