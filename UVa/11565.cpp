#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int sqrtn = ceil(sqrt(c));
        bool hasSolution = false;
        for(int x = -sqrtn; x <= sqrtn && !hasSolution; ++x)
        {
            for(int y = x+1; y <= sqrtn && !hasSolution; ++y)
            {
                for(int z = y+1; z <= sqrtn && !hasSolution; ++z)
                {
                    if(x + y + z == a && x*y*z == b && x*x + y*y + z*z == c)
                    {
                        printf("%d %d %d\n", x, y, z);
                        hasSolution = true;
                        break;
                    }
                }
            }
        }
        if(!hasSolution)
        {
            printf("No solution.\n");
        }
    }
    return 0;
}