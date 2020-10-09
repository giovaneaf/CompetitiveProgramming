#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;

int main()
{
    ull n, k, a, b;
    while(cin >> n >> k >> a >> b)
    {
        if(k == 1)
        {
            printf("%llu\n", (n - (ull) 1)*a);
        }
        else
        {
            ull cost = 0;
            while(n > 1)
            {
                if(n%k == 0)
                {
                    ull target = n/k;
                    cost += min(b, (n-target)*a);
                    n = target;
                }
                else
                {
                    ull target = max((ull) 1, (n/k)*k);
                    cost += (n-target)*a;
                    n = target;
                }
            }
            cout << cost << "\n";
        }
    }
    return 0;
}
