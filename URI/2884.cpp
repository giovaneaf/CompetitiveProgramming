#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, l, x;
    while(cin >> m >> n)
    {
        bitset<1000> b;
        cin >> l;
        while(l--)
        {
            cin >> x; b[x-1] = 1;
        }
        vector<bitset<1000>> switches(m);
        for(auto& a : switches)
        {
            cin >> l;
            while(l--)
            {
                cin >> x; a[x-1] = 1;
            }
        }
        bool found = false;
        for(int i = 0; i < 2*m; ++i)
        {
            b ^= switches[i%m];

            if(b.none())
            {
                found = true;
                printf("%d\n", i+1);
                break;
            }
        }
        if(!found)
            printf("-1\n");
    }
    return 0;
}
