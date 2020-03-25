#include <bits/stdc++.h>

using namespace std;

int main() {
    int fib[50];
    fib[0] = 1;
    fib[1] = 1;
    for(int i = 2; i < 50; ++i) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    int n;
    while(scanf("%d", &n) != EOF and n) {
        printf("%d\n", fib[n]);
    }
    return 0;
}