#include <bits/stdc++.h>

using namespace std;

#define MIN 40000000

int main()
{
    int a;
    scanf("%d", &a);
    int n;
    scanf("%d", &n);
    int cnt = 0;
    for(int i = 0; i < n; ++i)
    {
        int f;
        scanf("%d", &f);
        if(a*f >= MIN) cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
