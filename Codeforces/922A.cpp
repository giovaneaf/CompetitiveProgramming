#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;

int main()
{
    int x, y;
    while(scanf("%d %d", &x, &y) != EOF) {
        if(y == 0) {
            printf("No\n");
            continue;
        }
        if(y == 1) {
            if(x == 0) printf("Yes\n");
            else printf("No\n");
            continue;
        }
        int copies = y-1;
        if(x < copies) {
            printf("No\n");
            continue;
        }
        x -= copies;
        if(x%2 == 0) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
