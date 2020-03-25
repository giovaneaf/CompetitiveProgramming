#include <bits/stdc++.h>

using namespace std;

struct p
{
    int a, b, c;
};

int main()
{
    int n, m;
    while(cin >> n >> m)
    {
        if(n == 0 && m == 0) break;
        vector<int> v(n);
        for(int i = 0; i < n; ++i) v[i] = i;
        int a, b, c;
        vector<p> e(m);
        for(int i = 0; i < m; ++i)
        {
            cin >> a >> b >> c;
            e[i] = {a,b,c};
        }
        int pos[n];
        int ans = 0;
        do
        {
            for(int i = 0; i < n; ++i)
            {
                pos[v[i]] = i;
            }
            bool can = true;
            for(int i = 0; i < m; ++i)
            {
                int gap = abs(pos[e[i].a] - pos[e[i].b]);
                if(e[i].c > 0)
                {
                    if(gap > e[i].c)
                    {
                        can = false;
                        break;
                    }
                }
                else
                {
                    if(gap < -e[i].c)
                    {
                        can = false;
                        break;
                    }
                }
            }
            if(can) ans++;
        } while(next_permutation(v.begin(), v.end()));
        printf("%d\n", ans);
    }
    return 0;
}