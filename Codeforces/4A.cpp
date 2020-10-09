#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    printf("%s\n", (((n&1) == 0) && n != 2) ? "YES" : "NO");
    return 0;
}