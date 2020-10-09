#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    double minKg = 1000.0;
    for(int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        minKg = min(minKg, a / (double) b);
    }
    printf("%.10f\n", m*minKg);
    return 0;
}