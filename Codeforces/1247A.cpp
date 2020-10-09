#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int a, b;
    while(cin >> a >> b)
    {
        if(a == b)
        {
            printf("%d0 %d1\n", a, b);
        }
        else if(a + 1 == b)
        {
            printf("%d9 %d0\n", a, b);
        }
        else if (a == 9 && b == 1)
        {
            printf("9 10\n");
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}
