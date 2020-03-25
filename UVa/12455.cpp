#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int val, n;
        cin >> val;
        cin >> n;
        int v[n];
        for(int i = 0; i < n; ++i)
        {
            cin >> v[i];
        }
        bool can = false;
        for(int i = 0; i < (1 << n); ++i)
        {
            int tmp = 0;
            for(int j = 0; j < n; ++j)
            {
                if((i & (1 << j)) > 0)
                {
                    tmp += v[j];
                }
            }
            if(tmp == val)
            {
                can = true;
                break;
            }
        }
        printf("%s\n", can ? "YES" : "NO");
    }
    return 0;
}
